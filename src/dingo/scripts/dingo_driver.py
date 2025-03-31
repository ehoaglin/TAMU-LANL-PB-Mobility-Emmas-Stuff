#!/usr/bin/env python3
import numpy as np
import time
import rclpy #rospy
from rclpy.node import Node #rospy
import sys
from std_msgs.msg import Float64
import signal
import socket
import platform

from dingo_peripheral_interfacing_msg.msg import ElectricalMeasurements


#Fetching is_sim and is_physical from arguments
# Fetching is_sim and is_physical from arguments
def get_args():
    # Default values
    is_sim = 1
    is_physical = 0
    use_imu = 0

    # Parse command-line arguments
    for arg in sys.argv:
        if arg.startswith("--is_sim="):
            is_sim = int(arg.split("=")[1])
        elif arg.startswith("--is_physical="):
            is_physical = int(arg.split("=")[1])
        elif arg.startswith("--use_imu="):
            use_imu = int(arg.split("=")[1])
    args = [is_sim, is_physical, use_imu]
    return args

args = get_args()
if len(args) != 3:  # arguments have not been provided, go to defaults (not sim, is physical)
    is_sim = 1
    is_physical = 0
    use_imu = 0
else:
    is_sim = int(args[0])
    is_physical = int(args[1])
    use_imu = int(args[2])

from dingo_control.Controller import Controller
from dingo_input_interfacing.InputInterface import InputInterface
from dingo_control.State import State, BehaviorState
#from dingo_control.Kinematics import four_legs_inverse_kinematics
from dingo_control.Config import Configuration
from dingo_control_msg.msg import TaskSpace, JointSpace, Angle
from std_msgs.msg import Bool
from dingo_control.Kinematics import Kinematics

if is_physical:
    from dingo_servo_interfacing.HardwareInterface import HardwareInterface
    from dingo_peripheral_interfacing.IMU import IMU
    from dingo_control.Config import Leg_linkage

class DingoDriver(Node):
    #def __init__(self,is_sim, is_physical, use_imu):
    def __init__(self, is_sim: bool, is_physical: bool, use_imu: bool):
         # Initialize the parent Node class with a unique name
        super().__init__("dingo_driver_node")  # Initialize the ROS2 node
        self.message_rate = 40
        #self.rate = rospy.Rate(self.message_rate)
        self.rate = self.create_rate(self.message_rate) # Use Duration for rate

        # store the parameters
        self.is_sim = is_sim
        self.is_physical = is_physical
        self.use_imu = use_imu

        # declare parameters
        self.declare_parameter('is_sim', self.is_sim)
        self.declare_parameter('is_physical', self.is_physical)
        self.declare_parameter('use_imu', self.use_imu)

        # subscriptions
        self.joint_command_sub = self.create_subscription(JointSpace, "/joint_space_cmd", self.run_joint_space_command, 10) 
        self.task_command_sub = self.create_subscription(TaskSpace, "/task_space_cmd", self.run_task_space_command, 10) 
        self.estop_status_sub = self.create_subscription(Bool, "/emergency_stop_status", self.update_emergency_stop_status, 100)
        # rospy.Subscriber("/joint_space_cmd", JointSpace, self.run_joint_space_command) 
        # rospy.Subscriber("/task_space_cmd", TaskSpace, self.run_task_space_command) 
        # rospy.Subscriber("/emergency_stop_status", Bool, self.update_emergency_stop_status) 


        self.external_commands_enabled = 0
        self.get_logger().info('DingoDriver Node initialized and subscriptions created.')

        if self.is_sim:
            self.sim_command_topics = ["/dingo_controller/FR_theta1/command",
                    "/dingo_controller/FR_theta2/command",
                    "/dingo_controller/FR_theta3/command",
                    "/dingo_controller/FL_theta1/command",
                    "/dingo_controller/FL_theta2/command",
                    "/dingo_controller/FL_theta3/command",
                    "/dingo_controller/RR_theta1/command",
                    "/dingo_controller/RR_theta2/command",
                    "/dingo_controller/RR_theta3/command",
                    "/dingo_controller/RL_theta1/command",
                    "/dingo_controller/RL_theta2/command",
                    "/dingo_controller/RL_theta3/command"]

            self.sim_publisher_array = []
            for topic in self.sim_command_topics:
                self.sim_publisher_array.append(self.create_publisher(Float64, topic, 10)) 
                #commented out because it is redundant
                #self.create_subscription(Bool, "/emergency_stop_status", self.update_emergency_stop_status, 100)

        # Create config
        self.config = Configuration()
        kinematics = Kinematics(self, self.config)
        if is_physical:
            self.linkage = Leg_linkage(self.config)
            self.hardware_interface = HardwareInterface(self.linkage)
            # Create imu handle
        if self.use_imu:
            self.imu = IMU()

        # Create controller and user input handles
        self.controller = Controller(
            self,
            self.config,
            kinematics.four_legs_inverse_kinematics,
        )

        self.state = State()
        #rospy.loginfo("Creating input listener...") #changed rospy.loginfo to self.node.get_logger().info
        self.get_logger().info("Creating input listener...")
        self.input_interface = InputInterface(self, self.config)
        self.get_logger().info("Input listener successfully initialised... Robot will now receive commands via Joy messages")
        # rospy.loginfo("Input listener successfully initialised... Robot will now receive commands via Joy messages")

        self.get_logger().info(f"Summary of current gait parameters:")
        self.get_logger().info(f"overlap time: {self.config.overlap_time:.2f}")
        self.get_logger().info(f"swing time: {self.config.swing_time:.2f}")
        self.get_logger().info(f"z clearance: {self.config.z_clearance:.2f}")
        self.get_logger().info(f"back leg x shift: {self.config.rear_leg_x_shift:.2f}")
        self.get_logger().info(f"front leg x shift: {self.config.front_leg_x_shift:.2f}")
        # rospy.loginfo 
        # rospy.loginfo 
        # rospy.loginfo 
        # rospy.loginfo 
        # rospy.loginfo 
        # rospy.loginfo 


        # Create a timer to periodically call the run() method
        self.timer = self.create_timer(1.0 / self.message_rate, self.run)
    
    def initialize_robot(self):
        """One-time initialization logic for the robot."""
        self.get_logger().info("Initializing robot to default state...")
        if self.state.currently_estopped == 1:
            self.get_logger().warn("E-stop is pressed. Initialization paused until E-stop is released.")
            while self.state.currently_estopped == 1:
                self.rate.sleep()
            self.get_logger().info("E-stop released. Continuing initialization.")

         # Set the robot to a default state
        self.state.behavior_state = BehaviorState.REST
        command = self.input_interface.get_command(self.state, self.message_rate)
        self.controller.run(self.state, command)
        self.controller.publish_joint_space_command(self.state.joint_angles)
        self.controller.publish_task_space_command(self.state.rotated_foot_locations)

        if self.is_sim:
            self.publish_joints_to_sim(self.state.joint_angles)
            self.get_logger().info("Simulation mode: Default joint angles published.")
        if self.is_physical:
            self.hardware_interface.set_actuator_postions(self.state.joint_angles)
            self.get_logger().info("Physical mode: Default joint angles sent to hardware.")

    def run(self):
        """Periodic control logic executed by the timer."""
        if self.state.currently_estopped == 1:
            self.get_logger().warn("E-stop pressed. Control loop paused until E-stop is released.")
            self.state.trotting_active = 0
            return

        # Fetch the latest command
        command = self.input_interface.get_command(self.state, self.message_rate)

        # Read IMU data if enabled
        self.state.euler_orientation = (
            self.imu.read_orientation() if self.use_imu else np.array([0, 0, 0])
        )

        # Step the controller forward
        self.controller.run(self.state, command)

        # Publish commands
        if self.state.behavior_state in [BehaviorState.TROT, BehaviorState.REST]:
            self.controller.publish_joint_space_command(self.state.joint_angles)
            self.controller.publish_task_space_command(self.state.rotated_foot_locations)

            if self.is_sim:
                self.publish_joints_to_sim(self.state.joint_angles)
            if self.is_physical:
                self.hardware_interface.set_actuator_postions(self.state.joint_angles)

            if self.state.currently_estopped == 0:
                #self.get_logger().info("Manual Control deactivated. Now accepting external commands")
                command = self.input_interface.get_command(self.state,self.message_rate)
                #print(command)
                self.state.behavior_state = BehaviorState.REST
                self.controller.run(self.state, command)
                self.controller.publish_joint_space_command(self.state.joint_angles)
                self.controller.publish_task_space_command(self.state.rotated_foot_locations)
                if self.is_sim:
                        self.publish_joints_to_sim(self.state.joint_angles)
                if self.is_physical:
                    # Update the pwm widths going to the servos
                    self.hardware_interface.set_actuator_postions(self.state.joint_angles)
                if self.state.currently_estopped == 0:
                    command = self.input_interface.get_command(self.state,self.message_rate)
                    if command.joystick_control_event == 1:
                        self.external_commands_enabled = 0
                        
                    self.rate.sleep()
    
    def update_emergency_stop_status(self, msg):
        if msg.data == 1:
            self.state.currently_estopped = 1
        if msg.data == 0:
            self.state.currently_estopped = 0
        return

    def run_task_space_command(self, msg):
        if self.external_commands_enabled == 1 and self.state.currently_estopped == 0:
            foot_locations = np.zeros((3,4))
            j = 0
            for i in range(3):
                foot_locations[i] = [msg.fr_foot[j], msg.fl_foot[j], msg.rr_foot[j], msg.rl_foot[j]]
                j = j+1
            #print('hello', foot_locations)
            joint_angles = self.controller.inverse_kinematics(foot_locations, self.config)
            if self.is_sim:
                self.publish_joints_to_sim(self, joint_angles)
            
            if self.is_physical:
                self.hardware_interface.set_actuator_postions(joint_angles)
            
        elif self.external_commands_enabled == 0:
            self.get_logger().error("ERROR: Robot not accepting commands. Please deactivate manual control before sending control commands")
        elif self.state.currently_estopped == 1:
            self.get_logger().error("ERROR: Robot currently estopped. Please release before trying to send commands")

    def run_joint_space_command(self, msg):
        if self.external_commands_enabled == 1 and self.state.currently_estopped == 0:
            joint_angles = np.zeros((3,4))
            j = 0
            for i in range(3):
                joint_angles[i] = [msg.fr_foot[j], msg.fl_foot[j], msg.rr_foot[j], msg.rl_foot[j]]
                j = j+1
            print(joint_angles)

            if self.is_sim:
                self.publish_joints_to_sim(self, joint_angles)
            
            if self.is_physical:
                self.hardware_interface.set_actuator_postions(joint_angles)
            
        elif self.external_commands_enabled == 0:
            self.get_logger().error("ERROR: Robot not accepting commands. Please deactivate manual control before sending control commands")
        elif self.state.currently_estopped == 1:
            self.get_logger().error("ERROR: Robot currently estopped. Please release before trying to send commands")
    
    def publish_joints_to_sim(self, joint_angles):
        rows, cols = joint_angles.shape
        i = 0
        for col in range(cols):
            for row in range(rows):
                msg = Float64()
                msg.data = float(joint_angles[row, col])
                self.sim_publisher_array[i].publish(msg)
                #self.sim_publisher_array[i].publish(joint_angles[row,col])
                i = i + 1



def signal_handler(sig, frame):
    sys.exit(0)

def main():
    """Main program
    """
    rclpy.init(args=sys.argv)
    signal.signal(signal.SIGINT, signal_handler)
    #rospy.init_node("dingo_driver") 
    #node = Node('dingo_driver')
    dingo = DingoDriver(is_sim, is_physical, use_imu)
    dingo.initialize_robot()
    rclpy.spin(dingo)
    rclpy.shutdown()
    
main()




# clock = self.get_clock()
#         # Wait until the activate button has been pressed
#         # while rclpy.ok():# changed not rospy.is_shutdown(): to rclpy.ok():
#         if self.state.currently_estopped == 1:
#             self.get_logger().warn("E-stop pressed. Controlling code now disabled until E-stop is released") #changed rospy.logwarn to self.node.get_logger().warn
#             self.state.trotting_active = 0
#             while self.state.currently_estopped == 1:
#                 self.rate.sleep()
#             self.get_logger().info("E-stop released") #changed rospy.loginfo to self.node.get_logger().info
        
#         self.get_logger().info("Manual robot control active. Currently not accepting external commands") #changed rospy.loginfo to self.node.get_logger().info
#         #Always start Manual control with the robot standing still. Send default positions once
#         command = self.input_interface.get_command(self.state,self.message_rate)
#         self.state.behavior_state = BehaviorState.REST
#         self.controller.run(self.state, command)
#         self.controller.publish_joint_space_command(self.state.joint_angles)
#         self.controller.publish_task_space_command(self.state.rotated_foot_locations)
#         if self.is_sim:
#                 self.publish_joints_to_sim(self.state.joint_angles)
#                 self.get_logger().info("is_sim")
#         if self.is_physical:
#             # Update the pwm widths going to the servos
#             self.hardware_interface.set_actuator_postions(self.state.joint_angles)
#             self.get_logger().info("is_not_sim")
#         if self.state.currently_estopped == 0:
#             #time.start = rospy.Time.now()
#             time.start = self.get_clock().now()

#             #Update the robot controller's parameters
#             command = self.input_interface.get_command(self.state,self.message_rate)
#             if command.joystick_control_event == 1:
#                 if self.state.currently_estopped == 0:
#                     self.external_commands_enabled = 1
                    
#                 else:
#                     self.get_logger().error("Received Request to enable external control, but e-stop is pressed so the request has been ignored. Please release e-stop and try again") # changed rospy.logerr to self.node.get_logger().error
            
#             # Read imu data. Orientation will be None if no data was available
#             #self.get_logger().info(self.imu.read_orientation())
#             self.state.euler_orientation = (
#                 self.imu.read_orientation() if self.use_imu else np.array([0, 0, 0])
#             )
#             [yaw,pitch,roll] = self.state.euler_orientation
# #                print('Yaw: ',np.round(yaw,2),'Pitch: ',np.round(pitch,2),'Roll: ',np.round(roll,2))
#             # Step the controller forward by dt
#             self.controller.run(self.state, command)

#             # if self.state.behavior_state == BehaviorState.TROT or self.state.behavior_state == BehaviorState.REST:
#             if self.state.behavior_state == BehaviorState.TROT or self.state.behavior_state == BehaviorState.REST:
#                 self.controller.publish_joint_space_command(self.state.joint_angles)
#                 self.controller.publish_task_space_command(self.state.rotated_foot_locations)
# #                    self.get_logger().info(str(self.state.joint_angles))
# #                    self.get_logger().info(f'State.height: {self.state.height}')

#                 #If running simulator, publish joint angles to gazebo controller:
#                 if self.is_sim:
#                     self.publish_joints_to_sim(self.state.joint_angles)
#                 if self.is_physical:
#                     # Update the pwm widths going to the servos
#                     self.hardware_interface.set_actuator_postions(self.state.joint_angles)
                
# #                    self.get_logger().info(f'All angles: \n {np.round(np.degrees(self.state.joint_angles),2)}')
#                 time.end = self.get_clock().now()
#                 #Uncomment following line if want to see how long it takes to execute a control iteration
#                 #self.get_logger().info(str(time.start-time.end))

# #                    self.get_logger().info(f'State: \n {self.state}')
#                 #else:
#                 if self.is_sim:
#                     self.publish_joints_to_sim(self.state.joint_angles)
#                 #self.rate.sleep()

#             if self.state.currently_estopped == 0:
#                 self.get_logger().info("Manual Control deactivated. Now accepting external commands")
#                 command = self.input_interface.get_command(self.state,self.message_rate)
#                 print(command)
#                 self.state.behavior_state = BehaviorState.REST
#                 self.controller.run(self.state, command)
#                 self.controller.publish_joint_space_command(self.state.joint_angles)
#                 self.controller.publish_task_space_command(self.state.rotated_foot_locations)
#                 if self.is_sim:
#                         self.publish_joints_to_sim(self.state.joint_angles)
#                 if self.is_physical:
#                     # Update the pwm widths going to the servos
#                     self.hardware_interface.set_actuator_postions(self.state.joint_angles)
#                 if self.state.currently_estopped == 0:
#                     command = self.input_interface.get_command(self.state,self.message_rate)
#                     if command.joystick_control_event == 1:
#                         self.external_commands_enabled = 0
                        
#                     self.rate.sleep()