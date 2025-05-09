#!/usr/bin/env python3
import rclpy
import threading
import numpy as np
import sys
#sys.path.append("/home/ehoaglin/ros2_ws/src/dingo_control/src/dingo_control")
from dingo_control.State import BehaviorState, State
from dingo_control.Command import Command
from dingo_control.dingo_utilities.src.dingo_utilities.Utilities import deadband, clipped_first_order_filter
from sensor_msgs.msg import Joy


class InputInterface:
    def __init__(self, node, config):
        #rclpy.init() # adding to initialize the ROS2 system
        #self.node = rclpy.create_node('input_interface')
        self.node = node  # Use the existing node
        self.config = config
        self.previous_gait_toggle = 0
        self.previous_state = BehaviorState.REST
        self.previous_hop_toggle = 0
        self.previous_joystick_toggle = 0

        self.rounding_dp = 2

        self.hop_event = 0
        self.trot_event = 0
        self.joystick_control_event = 0

        from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,  # Match the publisher's reliability
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )

        self.input_messages = self.node.create_subscription(
            Joy, "/joy", self.input_callback, qos_profile
        )
        #self.input_messages = self.node.create_subscription(Joy, "/joy", self.input_callback, 100) #changed from rospy.Subscriber("joy", Joy, self.input_callback) to self.input_messages = self.create_subscription( Joy, "joy", self.input_callback,10)
        self.current_command = Command()

        self.new_command = Command()
        self.developing_command = Command()
        self.node.get_logger().info(f"Received /joy message:")

    def input_callback(self, msg):
        #self.node.get_logger().info("input_callback triggered")
        self.developing_command = Command()
        # Debugging: Print the received joystick message
        #self.node.get_logger().info(f"Received /joy message: Axes: {msg.axes}, Buttons: {msg.buttons}")

        ####### Handle discrete commands ########
        # Check if requesting a state transition to trotting, or from trotting to resting
        gait_toggle = msg.buttons[5] #R1
        if self.trot_event != 1:
            self.trot_event = (gait_toggle == 1 and self.previous_gait_toggle == 0)

        # Check if requesting a state transition to hopping, from trotting or resting
        hop_toggle = msg.buttons[1] #x
        if self.hop_event != 1:
            self.hop_event = (hop_toggle == 1 and self.previous_hop_toggle == 0)            
        
        joystick_toggle = msg.buttons[4] #L1
        if self.joystick_control_event != 1:
            self.joystick_control_event = (joystick_toggle == 1 and self.previous_joystick_toggle == 0)

        # Update previous values for toggles and state
        self.previous_gait_toggle = gait_toggle
        self.previous_hop_toggle = hop_toggle
        self.previous_joystick_toggle = joystick_toggle

        ####### Handle continuous commands ########
        if self.joystick_control_event:
            x_vel = (msg.axes[1]) * self.config.max_x_velocity  # ly
            y_vel = msg.axes[0] * self.config.max_y_velocity  # lx
            self.developing_command.horizontal_velocity = np.round(np.array([x_vel, y_vel]), self.rounding_dp)
            #self.node.get_logger().info(f"Joystick Control Active: Horizontal Velocity: {self.developing_command.horizontal_velocity}")
            #self.node.get_logger().info("Joystick Control Inactive")
        # x_vel = (msg.axes[1] ) * self.config.max_x_velocity #ly
        # y_vel = msg.axes[0] * self.config.max_y_velocity #lx
        # self.developing_command.horizontal_velocity =  np.round(np.array([x_vel, y_vel]),self.rounding_dp)
        # self.developing_command.yaw_rate = np.round(msg.axes[2],self.rounding_dp) * self.config.max_yaw_rate #rx

        self.developing_command.pitch = np.round(msg.axes[3],self.rounding_dp) * self.config.max_pitch #ry
        self.developing_command.height_movement = np.round(msg.axes[6],self.rounding_dp) #dpady
        self.developing_command.roll_movement = -np.round(msg.axes[7],self.rounding_dp) #dpadx

        self.new_command = self.developing_command
        
    def get_command(self, state, message_rate):
        if self.new_command is None:
            self.get_logger().warn("new_command is not yet updated. Returning default command.")
            return Command()  # Return a default Command object
        self.current_command = self.new_command
        
        self.current_command.trot_event = self.trot_event
        self.current_command.hop_event  = self.hop_event
        self.current_command.joystick_control_event = self.joystick_control_event
        self.hop_event = 0
        self.trot_event = 0
        self.joystick_control_event = 0

        message_dt = 1.0 / message_rate

        deadbanded_pitch = deadband(
            self.current_command.pitch, self.config.pitch_deadband
        )
        pitch_rate = clipped_first_order_filter(
            state.pitch,
            deadbanded_pitch,
            self.config.max_pitch_rate,
            self.config.pitch_time_constant,
        )
        self.current_command.pitch  = np.clip(state.pitch + message_dt * pitch_rate, -0.35,0.35)
        self.current_command.height = np.clip(state.height - message_dt * self.config.z_speed * self.current_command.height_movement,-0.27,-0.08)
        self.current_command.roll   = np.clip(state.roll + message_dt * self.config.roll_speed * self.current_command.roll_movement, -0.3,0.3)

        return self.current_command

#!/usr/bin/env python3
# def main(args=None):
#     rclpy.init(args=args)

#     # Create a ROS 2 node
#     node = rclpy.create_node("input_interface_node")

#     # Create a configuration object (replace with actual configuration if needed)
#     from dingo_control.Config import Configuration
#     config = Configuration()

#     # Create an instance of the InputInterface class
#     input_interface = InputInterface(node, config)

#     # Spin the node in a background thread
#     spin_thread = threading.Thread(target=rclpy.spin, args=(node,), daemon=True)
#     spin_thread.start()

#     # Main thread logic (example)
#     try:
#         while rclpy.ok():
#             # Perform other tasks in the main thread
#             node.get_logger().info("Main thread is running...")
#             rclpy.sleep(1.0)  # Simulate some work
#     except KeyboardInterrupt:
#         node.get_logger().info("Shutting down InputInterface node...")
#     finally:
#         rclpy.shutdown()
#         spin_thread.join()
# try:
#             self.node.get_logger().info("input_callback triggered")
#             self.node.get_logger().info(f"Received /joy message: Axes: {msg.axes}, Buttons: {msg.buttons}")
            
#             # Handle discrete commands
#             gait_toggle = msg.buttons[5]  # R1
#             if self.trot_event != 1:
#                 self.trot_event = (gait_toggle == 1 and self.previous_gait_toggle == 0)

#             hop_toggle = msg.buttons[0]  # X
#             if self.hop_event != 1:
#                 self.hop_event = (hop_toggle == 1 and self.previous_hop_toggle == 0)

#             joystick_toggle = msg.buttons[4]  # L1
#             if self.joystick_control_event != 1:
#                 self.joystick_control_event = (joystick_toggle == 1 and self.previous_joystick_toggle == 0)

#             # Update previous values for toggles and state
#             self.previous_gait_toggle = gait_toggle
#             self.previous_hop_toggle = hop_toggle
#             self.previous_joystick_toggle = joystick_toggle

#             # Handle continuous commands
#             x_vel = (msg.axes[1]) * self.config.max_x_velocity  # ly
#             y_vel = msg.axes[0] * self.config.max_y_velocity  # lx
#             self.developing_command.horizontal_velocity = np.round(np.array([x_vel, y_vel]), self.rounding_dp)
#             self.developing_command.yaw_rate = np.round(msg.axes[2], self.rounding_dp) * self.config.max_yaw_rate  # rx

#             self.developing_command.pitch = np.round(msg.axes[3], self.rounding_dp) * self.config.max_pitch  # ry
#             self.developing_command.height_movement = np.round(msg.buttons[7], self.rounding_dp)  # dpady
#             self.developing_command.roll_movement = -np.round(msg.buttons[7], self.rounding_dp)  # dpadx

#             self.new_command = self.developing_command
#         except Exception as e:
#             self.node.get_logger().error(f"Error in input_callback: {e}")