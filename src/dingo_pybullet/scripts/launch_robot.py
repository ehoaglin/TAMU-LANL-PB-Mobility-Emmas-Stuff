#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import pybullet as p
import pybullet_data
import time
from dingo_control_msg.msg import JointSpace
import random
import os
import math
import csv
from ament_index_python.packages import get_package_share_directory

class PyBulletSimNode(Node):
    def __init__(self):
        super().__init__('pybullet_sim_node')

        self.joint_positions = {}
        self.body_id = None
        self.terrain = None
        self.joint_ids = None
        self.get_logger().info('Starting PyBullet simulation...')
        self.subscription = self.create_subscription(JointSpace, '/joint_space_goals', self.joint_states_callback, 10)
        self.get_logger().info('Subscription to /joint_space_goals topic created.')
        # Initialize the robot in PyBullet
        self.robot_init_flat(dt=0.0083, body_pos=[0, 0, 0.18], fixed=False)
        # self.robot_init_terrain(dt=0.0083, body_pos=[0, 0, 0.18], fixed=False)


    def joint_states_callback(self, msg):
        """Callback to update joint positions from JointSpace messages."""
        # Map joint positions from the JointSpace message
        joint_mapping = {
            'FL_theta1': math.radians(msg.fl_foot.theta1),
            'FL_theta2': math.radians(msg.fl_foot.theta2),
            'FL_theta3': math.radians(msg.fl_foot.theta3),
            'FR_theta1': math.radians(msg.fr_foot.theta1),
            'FR_theta2': math.radians(msg.fr_foot.theta2),
            'FR_theta3': math.radians(msg.fr_foot.theta3),
            'RL_theta1': math.radians(msg.rl_foot.theta1),
            'RL_theta2': math.radians(msg.rl_foot.theta2),
            'RL_theta3': math.radians(msg.rl_foot.theta3),
            'RR_theta1': math.radians(msg.rr_foot.theta1),
            'RR_theta2': math.radians(msg.rr_foot.theta2),
            'RR_theta3': math.radians(msg.rr_foot.theta3),
            'arm_joint1': math.radians(msg.exc_arm.theta1),
            'arm_joint2': math.radians(msg.exc_arm.theta2),
            'arm_joint3': math.radians(msg.exc_arm.theta3),
            'arm_joint4': math.radians(msg.exc_arm.theta4),
        }

        # Apply the updated joint positions to the PyBullet simulation
        for joint_name, position in joint_mapping.items():
            # Find the joint index in PyBullet using the joint name
            joint_index = next(
                (joint[0] for joint in self.joint_ids if joint[1].decode('utf-8') == joint_name),
                None
            )
            if joint_index is not None:
                # Set the joint position in PyBullet
                p.setJointMotorControl2(
                    self.body_id, joint_index, p.POSITION_CONTROL, targetPosition=position, force=7.35
                )
                #self.get_logger().info(f"Set joint {joint_name} (index {joint_index}) to position {position}")
            else:
                self.get_logger().warn(f"Joint {joint_name} not found in URDF!")
        # Step the simulation
        # contact_points = p.getContactPoints(bodyA=self.body_id, bodyB=self.terrain)
        # if contact_points:
        #     print("Contact points detected:", contact_points)
        # else:
        #     print("No contact points detected!")

        p.stepSimulation()


    def robot_init_terrain(self, dt, body_pos, fixed=False):
        """Initialize the robot in a varried terrain environment.
        To activate,change the robot_init function to robot_init_terrain in the main function.
        """
        self.get_logger().info('Connecting to PyBullet...')
        physicsClient = p.connect(p.GUI)  # Use p.GUI if you want the graphical interface
        p.setAdditionalSearchPath(pybullet_data.getDataPath())  # optionally
        self.get_logger().info('Connected to PyBullet.')

        p.resetSimulation()
        p.setGravity(0, 0, -10)
        terrainStartPos = [0, 0, 0]
        terrainStartOrientation = p.getQuaternionFromEuler([0, 0, 0])
        textureId = -1

        useProgrammatic = 0
        useTerrainFromPNG = 1
        useDeepLocoCSV = 2
        updateHeightfield = False

        heightfieldSource = useProgrammatic
        p.configureDebugVisualizer(p.COV_ENABLE_RENDERING, 0)
        heightPerturbationRange = 0.03

        if heightfieldSource == useProgrammatic:
            numHeightfieldRows = 450
            numHeightfieldColumns = 250
            heightfieldData = [0] * numHeightfieldRows * numHeightfieldColumns
        for j in range(int(numHeightfieldColumns / 2)):
            for i in range(int(numHeightfieldRows / 2)):
                height = random.uniform(0, heightPerturbationRange)
                heightfieldData[2 * i + 2 * j * numHeightfieldRows] = height
                heightfieldData[2 * i + 1 + 2 * j * numHeightfieldRows] = height
                heightfieldData[2 * i + (2 * j + 1) * numHeightfieldRows] = height
                heightfieldData[2 * i + 1 + (2 * j + 1) * numHeightfieldRows] = height

        terrainShape = p.createCollisionShape(shapeType=p.GEOM_HEIGHTFIELD, meshScale=[.05, .05, 1], heightfieldTextureScaling=(numHeightfieldRows - 1) / 2, heightfieldData=heightfieldData, numHeightfieldRows=numHeightfieldRows, numHeightfieldColumns=numHeightfieldColumns)
        terrain = p.createMultiBody(0, terrainShape)
        p.resetBasePositionAndOrientation(terrain, [0, 0, 0], [0, 0, 0, 1])
        p.changeDynamics(terrain, -1, lateralFriction=1.0)  # Set terrain friction
        p.changeVisualShape(terrain, -1, rgbaColor=[1, 1, 1, 1])

        p.configureDebugVisualizer(p.COV_ENABLE_RENDERING, 1)

        robotStartPos = [0, 0, 0.25]
        ang = 3.14 * 0.5 + 3.1415925438 * random.random()
        robotStartOrientation = p.getQuaternionFromEuler([0, 0, 0])

        # Get the path to the URDF file
        dingo_description_path = get_package_share_directory('dingo_description')
        urdf_file = os.path.join(dingo_description_path, 'urdf', 'dingo.urdf')

        body_id = p.loadURDF(urdf_file, robotStartPos, robotStartOrientation)
        for i in range(150):
            p.stepSimulation()

        cubx = [-5, -4, -2, -1, 0, 1, 2, 3, 4, 5]
        cuby = [-5, -4, -2, -1, 0, 1, 2, 3, 4, 5]
        CubStartPos = [random.choice(cubx), random.choice(cuby), random.uniform(0.0, 0.02)]
        CubStartOrientation = p.getQuaternionFromEuler([0, 0, 0])
        # CuboidID = p.loadURDF("urdf/Anatomy.urdf", CubStartPos, CubStartOrientation, useFixedBase=fixed)
        p.stepSimulation()

        p.setRealTimeSimulation(0)
        p.setPhysicsEngineParameter(
            fixedTimeStep=dt,
            numSolverIterations=100,
            enableFileCaching=0,
            numSubSteps=1,
            solverResidualThreshold=1e-10,
            erp=1e-1,
            contactERP=0.0,
            frictionERP=0.3,
        )
        p.setAdditionalSearchPath(pybullet_data.getDataPath())  # optionally

        joint_ids = []

        maxVel = 3.703  # rad/s
        for j in range(p.getNumJoints(body_id)):
            p.changeDynamics(body_id, j, lateralFriction=1.0, linearDamping=0, angularDamping=0)
            p.changeDynamics(body_id, j, maxJointVelocity=maxVel)
            joint_ids.append(p.getJointInfo(body_id, j))

        self.body_id = body_id  # Store body_id as a class attribute
        self.terrain = terrain
        self.joint_ids = joint_ids  # Store joint_ids as a class attribute
        contact_points = p.getContactPoints(bodyA=self.body_id, bodyB=terrain)
        if contact_points:
            print("Contact points detected:", contact_points)
        else:
            print("No contact points detected!")

        return body_id, joint_ids


    def robot_init_flat(self, dt, body_pos, fixed=False):
        """Initialize the robot in a flat terrain environment.
        To activate, change the robot_init function to robot_init_flat in the main function.
        """
        self.get_logger().info('Connecting to PyBullet...')
        physicsClient = p.connect(p.GUI)  # Use p.GUI for graphical interface
        p.setAdditionalSearchPath(pybullet_data.getDataPath())  # Optional
        self.get_logger().info('Connected to PyBullet.')

        # Reset simulation and set gravity
        p.resetSimulation()
        p.setGravity(0, 0, -9.81)

        # Add a ground plane
        plane_id = p.loadURDF("plane.urdf")
        self.get_logger().info('Ground plane added.')

        # Set robot initial position and orientation
        robotStartPos = [0, 0, 0.18]  # Slightly above the ground
        robotStartOrientation = p.getQuaternionFromEuler([0, 0, 0])

        # Load the robot URDF
        dingo_description_path = get_package_share_directory('dingo_description')
        urdf_file = os.path.join(dingo_description_path,'urdf', 'dingo_copy.urdf')
        self.body_id = p.loadURDF(urdf_file, robotStartPos, robotStartOrientation)

        # Step the simulation to stabilize the robot
        for _ in range(150):
            p.stepSimulation()

        # Set joint dynamics
        self.joint_ids = []
        for j in range(p.getNumJoints(self.body_id)):
            p.changeDynamics(self.body_id, j, lateralFriction=1.0, linearDamping=0.04, angularDamping=0.04)
            self.joint_ids.append(p.getJointInfo(self.body_id, j))

        self.get_logger().info('Robot initialized.')


    def destroy_node(self):
        """Clean up resources when the node is destroyed."""
        self.get_logger().info('Shutting down PyBullet simulation...')
        p.disconnect()  # Disconnect from PyBullet
        self.get_logger().info('Disconnected from PyBullet.')
        super().destroy_node()  # Call the parent class's destroy_node method


def main(args=None):
    rclpy.init(args=args)
    node = PyBulletSimNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()