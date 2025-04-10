import numpy as np
import time
import rclpy
from rclpy.node import Node
import sys
from std_msgs.msg import Float64
import signal
import socket
import platform
from dingo_peripheral_interfacing_msg.msg import ElectricalMeasurements

# Fetching is_sim and is_physical from arguments
def get_args():
    rclpy.init(args=sys.argv)
    node = rclpy.create_node('argument_parser')
    args = node.get_parameters(['is_sim', 'is_physical'])
    rclpy.shutdown()
    return args
args = get_args()
if len(args) != 4: #arguments have not been provided, go to defaults (not sim, is physical)
    is_sim = 0
    is_physical = 1
    use_imu = 1
else:
    is_sim = int(args[1])
    is_physical = int(args[2])
    use_imu = int(args[3])

from dingo_control.Controller import Controller
from dingo_peripheral_interfacing.IMU import IMU
from dingo_input_interfacing.InputInterface import InputInterface
from dingo_control.State import State
from dingo_control.Kinematics import Kinematics
from dingo_control.Config import Configuration
from dingo_input_interfacing.InputInterface import InputInterface

if is_physical:
    from dingo_servo_interfacing.HardwareInterface import HardwareInterface
    from dingo_control.Config import Leg_linkage

def signal_handler(sig, frame):
    sys.exit(0)

def get_args():
    rclpy.init(args=sys.argv)
    node = rclpy.create_node('argument_parser')
    node.declare_parameter('is_sim', 1)
    node.declare_parameter('is_physical', 0)
    is_sim = node.get_parameter('is_sim').get_parameter_value().integer_value
    is_physical = node.get_parameter('is_physical').get_parameter_value().integer_value
    rclpy.shutdown()
    return is_sim, is_physical

is_sim, is_physical = get_args()

def main(use_imu=False):
    """Main program
    """
    #rclpy.init(args=sys.argv)  # Initialize ROS2
    node = rclpy.create_node('robot_controller')  # Create ROS2 node

    signal.signal(signal.SIGINT, signal_handler)

    # TODO: Create a publisher for joint states 
    publishers = []
    if is_sim:
        command_topics = ["/notspot_controller/FR1_joint/command",
                  "/notspot_controller/FR2_joint/command",
                  "/notspot_controller/FR3_joint/command",
                  "/notspot_controller/FL1_joint/command",
                  "/notspot_controller/FL2_joint/command",
                  "/notspot_controller/FL3_joint/command",
                  "/notspot_controller/RR1_joint/command",
                  "/notspot_controller/RR2_joint/command",
                  "/notspot_controller/RR3_joint/command",
                  "/notspot_controller/RL1_joint/command",
                  "/notspot_controller/RL2_joint/command",
                  "/notspot_controller/RL3_joint/command"]

        for topic in command_topics:
            publishers.append(node.create_publisher(Float64, topic, 10))

    # Create config
    config = Configuration()
    kinematics = Kinematics(config)

    # Initialize physical hardware if needed
    if is_physical:
        linkage = Leg_linkage(config)
        hardware_interface = HardwareInterface(linkage)
        # Create imu handle
        if use_imu:
            imu = IMU(port="/dev/ttyACM0")
            imu.flush_buffer()

    # Create controller and user input handles
    controller = Controller(
        config,
        kinematics.four_legs_inverse_kinematics,
    )
    state = State()
    print("Creating input listener...")
    input_interface = InputInterface(config)
    print(platform.processor())
    # input_Controller = InputController(1, platform.processor()) # Check raspi hostname and replace here # platform.processor to processor
    print("Done.")

    last_loop = time.time()

    print("Summary of gait parameters:")
    print("overlap time: ", config.overlap_time)
    print("swing time: ", config.swing_time)
    print("z clearance: ", config.z_clearance)
    print("x shift: ", config.x_shift)

    # Wait until the activate button has been pressed
    rate = node.create_rate(50)  # Loop rate (50 Hz)

    while rclpy.ok():
        print("Waiting for L1 to activate robot.")
        command = input_interface.get_command(state, 50)
        if command.joystick_control_event == 1:
            print("Robot activated.")
            break
        rate.sleep()
        
    loop = 0
    while rclpy.ok():
        command = input_interface.get_command(state, 50)
        if command.joystick_control_event == 1:
            print("Deactivating Robot")
            break

        # Read imu data. Orientation will be None if no data was available
        quat_orientation = (
            imu.read_orientation() if use_imu else np.array([1, 0, 0, 0])
        )
        state.quat_orientation = quat_orientation

        # Step the controller forward by dt
        controller.run(state, command)

        # TODO: Publish the joint values (in state.joint_angles) to a publisher
        # If running simulator, publish joint angles to gazebo controller:
        if is_sim:
            rows, cols = state.joint_angles.shape
            for row in range(rows):
                for col in range(cols):
                    publishers[rows * row + col].publish(Float64(data=state.joint_angles[row, col]))
        
        if is_physical:
            # Update the pwm widths going to the servos
            hardware_interface.set_actuator_positions(state.joint_angles)
        
        loop += 1
        rate.sleep()

main()