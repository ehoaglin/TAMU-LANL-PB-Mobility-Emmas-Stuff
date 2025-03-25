#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import pybullet as p
import pybullet_data
import time
from sensor_msgs.msg import JointState
import random
import os
import math
import csv
from ament_index_python.packages import get_package_share_directory

class PyBulletSimNode(Node):
    def __init__(self):
        super().__init__('pybullet_sim_node')
        self.joint_positions = {}
        self.get_logger().info('Starting PyBullet simulation...')
        self.subscription = self.create_subscription(JointState, '/joint_states', self.joint_states_callback, 10)
        self.run_simulation()

    def joint_states_callback(self, msg):
        self.get_logger().info('joint_states_callback')
        for joint_name, position in zip(msg.name, msg.position):
            self.joint_positions[joint_name] = position

    def robot_init(self, dt, body_pos, fixed=False):
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
        heightPerturbationRange = 0.05
        if heightfieldSource == useProgrammatic:
            numHeightfieldRows = 900
            numHeightfieldColumns = 500
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

        p.changeVisualShape(terrain, -1, rgbaColor=[1, 1, 1, 1])

        p.configureDebugVisualizer(p.COV_ENABLE_RENDERING, 1)

        robotStartPos = [0, 0, 0.25]
        ang = 3.14 * 0.5 + 3.1415925438 * random.random()
        robotStartOrientation = p.getQuaternionFromEuler([0, 0, ang])

        # Get the path to the URDF file
        dingo_description_path = get_package_share_directory('dingo_description')
        urdf_file = os.path.join(dingo_description_path, 'urdf', 'dingo.urdf')

        body_id = p.loadURDF(urdf_file, robotStartPos, robotStartOrientation, useFixedBase=fixed)
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
            frictionERP=0.0,
        )
        p.setAdditionalSearchPath(pybullet_data.getDataPath())  # optionally

        joint_ids = []

        maxVel = 3.703  # rad/s
        for j in range(p.getNumJoints(body_id)):
            p.changeDynamics(body_id, j, lateralFriction=1e-5, linearDamping=0, angularDamping=0)
            p.changeDynamics(body_id, j, maxJointVelocity=maxVel)
            joint_ids.append(p.getJointInfo(body_id, j))
        return body_id, joint_ids

    def run_simulation(self):
        dT = 0.005
        bodyId, jointIds = self.robot_init(dt=dT, body_pos=[0, 0, 0.18], fixed=False)

        p.setGravity(0, 0, -9.81)

        self.get_logger().info('Loading plane URDF...')
        plane_id = p.loadURDF("plane.urdf")
        self.get_logger().info('Plane URDF loaded.')
        self.get_logger().info('Starting simulation steps...')

        while rclpy.ok():  # Run the simulation loop until ROS is shut down
            # Update joint positions
            for joint_name, position in self.joint_positions.items():
                joint_index = [joint[1] for joint in jointIds if joint[1] == joint_name]
                if joint_index:
                    p.setJointMotorControl2(bodyId, joint_index[0], p.POSITION_CONTROL, targetPosition=position)
                    self.get_logger().info('Setting joint position for joint {} to {}'.format(joint_name, position))
            p.stepSimulation()
            time.sleep(1. / 240.)  # Fixed time step (240 Hz)

        self.get_logger().info('Simulation steps completed.')

        self.get_logger().info('Disconnecting from PyBullet...')
        p.disconnect()
        self.get_logger().info('Disconnected from PyBullet.')

        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    node = PyBulletSimNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

# #!/usr/bin/env python3

# import rclpy
# from rclpy.node import Node
# import pybullet as p
# import pybullet_data
# import time
# from sensor_msgs.msg import JointState
# import random
# import os
# import math 
# import csv
# from ament_index_python.packages import get_package_share_directory

# joint_positions = {}

# def joint_states_callback(msg):
#     global joint_positions
#     node.get_logger().info('joint_states_callback')
#     for joint_name, position in zip(msg.name, msg.position):
#         joint_positions[joint_name] = position


# def robot_init(dt, body_pos, fixed=False):
#     # Connect to PyBullet (DIRECT mode for no GUI)
#     node.get_logger().info('Connecting to PyBullet...')
#     physicsClient = p.connect(p.GUI)  # Use p.GUI if you want the graphical interface
#     p.setAdditionalSearchPath(pybullet_data.getDataPath())  # optionally
#     node.get_logger().info('Connected to PyBullet.')

#     p.resetSimulation()
#     p.setGravity(0, 0, -10)
#     terrainStartPos = [0, 0, 0]
#     terrainStartOrientation = p.getQuaternionFromEuler([0, 0, 0])
#     textureId = -1

#     useProgrammatic = 0
#     useTerrainFromPNG = 1
#     useDeepLocoCSV = 2
#     updateHeightfield = False

#     heightfieldSource = useProgrammatic
#     p.configureDebugVisualizer(p.COV_ENABLE_RENDERING, 0)
#     heightPerturbationRange = 0.05
#     if heightfieldSource == useProgrammatic:
#         numHeightfieldRows = 900
#         numHeightfieldColumns = 500
#         heightfieldData = [0] * numHeightfieldRows * numHeightfieldColumns
#     for j in range(int(numHeightfieldColumns / 2)):
#         for i in range(int(numHeightfieldRows / 2)):
#             height = random.uniform(0, heightPerturbationRange)
#             heightfieldData[2 * i + 2 * j * numHeightfieldRows] = height
#             heightfieldData[2 * i + 1 + 2 * j * numHeightfieldRows] = height
#             heightfieldData[2 * i + (2 * j + 1) * numHeightfieldRows] = height
#             heightfieldData[2 * i + 1 + (2 * j + 1) * numHeightfieldRows] = height

#     terrainShape = p.createCollisionShape(shapeType=p.GEOM_HEIGHTFIELD, meshScale=[.05, .05, 1], heightfieldTextureScaling=(numHeightfieldRows - 1) / 2, heightfieldData=heightfieldData, numHeightfieldRows=numHeightfieldRows, numHeightfieldColumns=numHeightfieldColumns)
#     terrain = p.createMultiBody(0, terrainShape)
#     p.resetBasePositionAndOrientation(terrain, [0, 0, 0], [0, 0, 0, 1])

#     p.changeVisualShape(terrain, -1, rgbaColor=[1, 1, 1, 1])

#     p.configureDebugVisualizer(p.COV_ENABLE_RENDERING, 1)

#     robotStartPos = [0, 0, 0.25]
#     ang = 3.14 * 0.5 + 3.1415925438 * random.random()
#     robotStartOrientation = p.getQuaternionFromEuler([0, 0, ang])
   
#     # Get the path to the URDF file
#     dingo_description_path = get_package_share_directory('dingo_description')
#     urdf_file = os.path.join(dingo_description_path, 'urdf', 'dingo.urdf')

#     body_id = p.loadURDF(urdf_file, robotStartPos, robotStartOrientation, useFixedBase=fixed)
#     for i in range(150):
#         p.stepSimulation()

#     cubx = [-5, -4, -2, -1, 0, 1, 2, 3, 4, 5]
#     cuby = [-5, -4, -2, -1, 0, 1, 2, 3, 4, 5]
#     CubStartPos = [random.choice(cubx), random.choice(cuby), random.uniform(0.0, 0.02)]
#     CubStartOrientation = p.getQuaternionFromEuler([0, 0, 0])
#     # CuboidID = p.loadURDF("urdf/Anatomy.urdf", CubStartPos, CubStartOrientation, useFixedBase=fixed)
#     p.stepSimulation()

#     p.setRealTimeSimulation(0)
#     p.setPhysicsEngineParameter(
#         fixedTimeStep=dt,
#         numSolverIterations=100,
#         enableFileCaching=0,
#         numSubSteps=1,
#         solverResidualThreshold=1e-10,
#         erp=1e-1,
#         contactERP=0.0,
#         frictionERP=0.0,
#     )
#     p.setAdditionalSearchPath(pybullet_data.getDataPath())  # optionally

#     joint_ids = []

#     maxVel = 3.703  # rad/s
#     for j in range(p.getNumJoints(body_id)):
#         p.changeDynamics(body_id, j, lateralFriction=1e-5, linearDamping=0, angularDamping=0)
#         p.changeDynamics(body_id, j, maxJointVelocity=maxVel)
#         joint_ids.append(p.getJointInfo(body_id, j))
#     return body_id, joint_ids

# def run_simulation():
#     dT = 0.005
#     bodyId, jointIds = robot_init(dt=dT, body_pos=[0, 0, 0.18], fixed=False)

#     p.setGravity(0, 0, -9.81)

#     node.get_logger().info('Loading plane URDF...')
#     #plane_id = p.loadURDF("plane.urdf")
#     node.get_logger().info('Plane URDF loaded.')
#     #robot_id = p.loadURDF("dingo_description/urdf/dingo.urdf")  # Replace with your actual model path
#     node.get_logger().info('Starting simulation steps...')
#     # for i in range(1000):  # Simulate 1000 steps
#     #      # Update joint positions
#     #     for joint_name, position in joint_positions.items():
#     #         joint_index = [joint[1] for joint in jointIds if joint[1] == joint_name]
#     #         if joint_index:
#     #             p.setJointMotorControl2(bodyId, joint_index[0], p.POSITION_CONTROL, targetPosition=position)
#     #             node.get_logger().info('Setting joint position for joint {} to {}'.format(joint_name, position))
#     #     i+=1
#     #     p.stepSimulation()
#     #     time.sleep(1. / 240.)  # Fixed time step (240 Hz)
#     while rclpy.ok():  # Run the simulation loop until ROS is shut down
#         # Update joint positions
#         for joint_name, position in joint_positions.items():
#             joint_index = [joint[1] for joint in jointIds if joint[1] == joint_name]
#             if joint_index:
#                 p.setJointMotorControl2(bodyId, joint_index[0], p.POSITION_CONTROL, targetPosition=position)
#                 node.get_logger().info('Setting joint position for joint {} to {}'.format(joint_name, position))
#         p.stepSimulation()
#         time.sleep(1. / 240.)  # Fixed time step (240 Hz)
#     node.get_logger().info('Simulation steps completed.')

#     node.get_logger().info('Disconnecting from PyBullet...')
#     p.disconnect()
#     node.get_logger().info('Disconnected from PyBullet.')

#     rclpy.shutdown()

# def main(args=None):
#     global node, joint_positions
#     joint_positions = {}
#     rclpy.init(args=args)
#     node = Node('pybullet_sim_node')
#     node.get_logger().info('Starting PyBullet simulation...')
#     node.create_subscription(JointState, '/joint_states', joint_states_callback, 10)
#     node.get_logger().info('Subscription to /joint_states topic created.')

#     run_simulation()

#     rclpy.spin(node)
#     node.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()