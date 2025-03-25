import pybullet as p
import time

def run_simulation():
    # Connect to PyBullet (DIRECT mode is used to run simulation without GUI)
    physics_client = p.connect(p.DIRECT)  # For non-graphical simulation use p.DIRECT, or p.GUI for GUI
    
    # Set gravity
    p.setGravity(0, 0, -9.81)

    # Load your robot model (URDF format)
    robot_id = p.loadURDF("your_robot_model.urdf")  # Replace with your actual model path
    
    # Run the simulation for some time
    for _ in range(1000):  # Run for 1000 simulation steps
        p.stepSimulation()
        time.sleep(1./240.)  # Sleep for a fixed time step (PyBullet default is 240 Hz)
    
    # Disconnect from the simulator
    p.disconnect()

if __name__ == "__main__":
    run_simulation()





# import rclpy
# from rclpy.node import Node
# from sensor_msgs.msg import JointState
# from ros_pybullet_interface.message_interface.msg import JointInfo
# from ros_pybullet_interface.message_interface.srv import CalculateInverseKinematics

# class JointStatesSubscriberPlugin(Node):
#     def __init__(self):
#         super().__init__('joint_states_subscriber_plugin')
#         self.joint_positions = {}

#         self.subscription = self.create_subscription(
#             JointState,
#             '/joint_states',
#             self.joint_states_callback,
#             10
#         )
#         self.set_joint_state_client = self.create_client(CalculateInverseKinematics, '/pybullet/set_joint_state')

#     def joint_states_callback(self, msg):
#         for joint_name, position in zip(msg.name, msg.position):
#             self.joint_positions[joint_name] = position

#         self.actuate_robot()

#     def actuate_robot(self):
#         # Apply the joint positions to the simulated robot
#         joint_control = JointInfo()
#         joint_control.model_name = 'your_robot_model_name'

#         for joint_name, position in self.joint_positions.items():
#             joint_control.joint_names.append(joint_name)
#             joint_control.positions.append(position)

#         if self.set_joint_state_client.wait_for_service(timeout_sec=1.0):
#             future = self.set_joint_state_client.call_async(CalculateInverseKinematics.Request(joint_control=joint_control))
#             rclpy.spin_until_future_complete(self, future)
#             if future.result() is not None:
#                 self.get_logger().info('Set joint state successfully')
#             else:
#                 self.get_logger().error('Failed to set joint state')
#         else:
#             self.get_logger().error('Service /pybullet/set_joint_state not available')

# def main(args=None):
#     rclpy.init(args=args)
#     plugin = JointStatesSubscriberPlugin()
#     rclpy.spin(plugin)
#     plugin.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()