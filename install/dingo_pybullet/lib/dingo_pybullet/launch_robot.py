#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import pybullet as p
import pybullet_data
import time
# physicsClient = p.connect(p.GUI)#or p.DIRECT for non-graphical version
# p.setAdditionalSearchPath(pybullet_data.getDataPath()) #optionally
# p.setGravity(0,0,-10)
# planeId = p.loadURDF("plane.urdf")
# startPos = [0,0,0.05]
# startOrientation = p.getQuaternionFromEuler([0,0,0])
class PyBulletSimNode(Node):
    def __init__(self):
        super().__init__('pybullet_sim_node')
        self.get_logger().info('Starting PyBullet simulation...')
        self.run_simulation()

    def run_simulation(self):
        # Connect to PyBullet (DIRECT mode for no GUI)
        self.get_logger().info('Connecting to PyBullet...')
        physicsClient = p.connect(p.GUI)  # Use p.GUI if you want the graphical interface
        p.setAdditionalSearchPath(pybullet_data.getDataPath())  # optionally
        self.get_logger().info('Connected to PyBullet.')

        # Set gravity
        self.get_logger().info('Setting gravity...')
        p.setGravity(0, 0, -9.81)

        # Load your robot model
        self.get_logger().info('Loading plane URDF...')
        plane_id = p.loadURDF("plane.urdf")
        self.get_logger().info('Plane URDF loaded.')
        #robot_id = p.loadURDF("dingo_description/urdf/dingo.urdf")  # Replace with your actual model path
        # Simulate for a few steps
        self.get_logger().info('Starting simulation steps...')
        for i in range(1000):  # Simulate 1000 steps
            p.stepSimulation()
            time.sleep(1./240.)  # Fixed time step (240 Hz)
        self.get_logger().info('Simulation steps completed.')

        # Disconnect
        self.get_logger().info('Disconnecting from PyBullet...')
        p.disconnect()
        self.get_logger().info('Disconnected from PyBullet.')

        # Shutdown the node after simulation completes
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    node = PyBulletSimNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()