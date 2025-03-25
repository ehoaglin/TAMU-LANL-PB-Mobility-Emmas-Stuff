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
# physicsClient = p.connect(p.GUI)#or p.DIRECT for non-graphical version
# p.setAdditionalSearchPath(pybullet_data.getDataPath()) #optionally
# p.setGravity(0,0,-10)
# planeId = p.loadURDF("plane.urdf")
# startPos = [0,0,0.05]
# startOrientation = p.getQuaternionFromEuler([0,0,0])

def rendering(render):
    """Enable/disable rendering"""
    p.configureDebugVisualizer(p.COV_ENABLE_RENDERING, render)
    p.configureDebugVisualizer(p.COV_ENABLE_GUI, render)

class PyBulletSimNode(Node):
    def __init__(self):
        super().__init__('pybullet_sim_node')
        self.joint_positions = {}
        self.get_logger().info('Starting PyBullet simulation...')
        self.subscription = self.create_subscription(JointState, '/joint_states', self.joint_states_callback, 10)
        

    def joint_states_callback(self, msg):
        for joint_name, position in zip(msg.name, msg.position):
            self.joint_positions[joint_name] = position
        self.run_simulation()

        
    def robot_init(self, dt, body_pos, fixed = False ):
        # turn off rendering while loading the models
        rendering(0)
        p.resetSimulation()
        p.setGravity(0, 0, -10)
        terrainStartPos = [0, 0,0]
        terrainStartOrientation = p.getQuaternionFromEuler([0, 0, 0])
        textureId = -1

        useProgrammatic = 0
        useTerrainFromPNG = 1
        useDeepLocoCSV = 2
        updateHeightfield = False

        heightfieldSource = useProgrammatic
        p.configureDebugVisualizer(p.COV_ENABLE_RENDERING,0)
        heightPerturbationRange = 0.05
        if heightfieldSource==useProgrammatic:
            numHeightfieldRows = 900
            numHeightfieldColumns = 500
            heightfieldData = [0]*numHeightfieldRows*numHeightfieldColumns 
        for j in range (int(numHeightfieldColumns/2)):
            for i in range (int(numHeightfieldRows/2) ):
                height = random.uniform(0,heightPerturbationRange)
                heightfieldData[2*i+2*j*numHeightfieldRows]=height
                heightfieldData[2*i+1+2*j*numHeightfieldRows]=height
                heightfieldData[2*i+(2*j+1)*numHeightfieldRows]=height
                heightfieldData[2*i+1+(2*j+1)*numHeightfieldRows]=height
            
            
            terrainShape = p.createCollisionShape(shapeType = p.GEOM_HEIGHTFIELD, meshScale=[.05,.05,1], heightfieldTextureScaling=(numHeightfieldRows-1)/2, heightfieldData=heightfieldData, numHeightfieldRows=numHeightfieldRows, numHeightfieldColumns=numHeightfieldColumns)
            terrain  = p.createMultiBody(0, terrainShape)
            p.resetBasePositionAndOrientation(terrain,[0,0,0], [0,0,0,1])

            p.changeVisualShape(terrain, -1, rgbaColor=[1,1,1,1])

            p.configureDebugVisualizer(p.COV_ENABLE_RENDERING,1)

            robotStartPos = [0, 0, 0.25]
            ang = 3.14*0.5+3.1415925438*random.random()
            robotStartOrientation = p.getQuaternionFromEuler([0,0,ang])
            body_id = p.loadURDF(r"C:\Users\12105\OneDrive\Documents\MEEN 401\hello\DingoQuadruped\dingo_ws\src\dingo_description\urdf\dingo.urdf",robotStartPos, robotStartOrientation, useFixedBase=fixed)

            for i in range(150):
                p.stepSimulation()

            cubx = [-5,-4,-2,-1,0,1,2,3,4,5]
            cuby = [-5,-4,-2,-1,0,1,2,3,4,5]
            CubStartPos = [random.choice(cubx), random.choice(cuby), random.uniform(0.0,0.02)]
            CubStartOrientation = p.getQuaternionFromEuler([0, 0, 0])
            #CuboidID = p.loadURDF("urdf/Anatomy.urdf",CubStartPos, CubStartOrientation, useFixedBase=fixed)
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
            # add floor
            p.setAdditionalSearchPath(pybullet_data.getDataPath()) #optionally
        
            # add robot
            
            
            #body_id = p.loadURDF(r"C:\Users\12105\OneDrive\Documents\MEEN 401\hello\Stride_bot\stridebot.urdf", body_pos, useFixedBase=fixed)
            joint_ids = []
            
            #robot properties
            maxVel = 3.703 #rad/s
            for j in range(p.getNumJoints(body_id)):
                p.changeDynamics( body_id, j, lateralFriction=1e-5, linearDamping=0, angularDamping=0)
                p.changeDynamics( body_id, j, maxJointVelocity=maxVel)
                joint_ids.append( p.getJointInfo(body_id, j))
            rendering(1)
            return body_id, joint_ids
   
    def run_simulation(self):
        # Connect to PyBullet (DIRECT mode for no GUI)
        dT = 0.005
        bodyId, jointIds = self.robot_init( dt = dT, body_pos = [0,0,0.18], fixed = False )
        pybulletDebug = pybulletDebug()
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
        robot_id = p.loadURDF("dingo_description/urdf/dingo.urdf")  # Replace with your actual model path
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