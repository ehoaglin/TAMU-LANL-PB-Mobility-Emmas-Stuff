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

        self.node = node  # Use the existing node
        self.config = config
        self.previous_gait_toggle = 0
        self.previous_state = BehaviorState.REST
        self.previous_hop_toggle = 0
        self.previous_joystick_toggle = 0
        self.previous_arm_toggle = 0

        self.rounding_dp = 2

        self.arm_event = 0
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
        #self.input_messages = rospy.Subscriber("joy", Joy, self.input_callback)
        self.current_command = Command()

        self.new_command = Command()
        self.developing_command = Command()
        self.node.get_logger().info(f"Received /joy message:")

    def input_callback(self, msg):

        self.developing_command = Command()

        ####### Handle discrete commands ########
        # Check if requesting a state transition to trotting, or from trotting to resting, or to arm
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

        arm_toggle = msg.buttons[9] #options
        if self.arm_event != 1:
            self.arm_event = (arm_toggle == 1 and self.previous_arm_toggle == 0)

        # Update previous values for toggles and state
        self.previous_gait_toggle = gait_toggle
        self.previous_hop_toggle = hop_toggle
        self.previous_joystick_toggle = joystick_toggle
        self.previous_arm_toggle = arm_toggle

        ####### Handle continuous commands ########
        
        x_vel = (msg.axes[1]) * self.config.max_x_velocity  # ly
        y_vel = msg.axes[0] * self.config.max_y_velocity  # lx

        self.developing_command.horizontal_velocity = np.round(np.array([x_vel, y_vel]), self.rounding_dp)
    
        arm_joint_2 = msg.axes[3] * 90  #ry
        arm_joint_1 = msg.axes[2] * 180 #rx
        arm_joint_3 = msg.axes[1] * 180 #ly
        arm_joint_4 = msg.axes[0] * 180 #lx

        # I did this one myself so it's a little messed up but this creates an array of the 
        # arm joint angle command values and enforces the physical allowable range of movement
        # self.developing_command.arm_movement = np.round(np.array([np.clip(arm_joint_1,-180, 180), 
        #                                                           np.round(msg.axes[3],self.rounding_dp) * self.config.max_joint_rate, 
        #                                                           np.clip(arm_joint_3,-160, 20), 
        #                                                           np.clip(arm_joint_4,-115,0)]), self.rounding_dp)
        
        self.developing_command.arm_joint1_rate = np.round(msg.axes[2],self.rounding_dp) * self.config.max_joint_rate
        self.developing_command.arm_joint2_rate = np.round(msg.axes[3],self.rounding_dp) * self.config.max_joint_rate
        self.developing_command.arm_joint3_rate = np.round(msg.axes[1],self.rounding_dp) * self.config.max_joint_rate
        self.developing_command.arm_joint4_rate_close = np.round(msg.axes[6],self.rounding_dp) * self.config.max_joint_rate
        self.developing_command.arm_joint4_rate_open = np.round(msg.axes[5],self.rounding_dp) * self.config.max_joint_rate
        self.developing_command.yaw_rate = np.round(msg.axes[2],self.rounding_dp) * self.config.max_yaw_rate #rx 

        self.developing_command.pitch = np.round(msg.axes[3],self.rounding_dp) * self.config.max_pitch #ry
        self.developing_command.height_movement = np.round(msg.axes[6],self.rounding_dp) #dpady
        self.developing_command.roll_movement = -np.round(msg.axes[7],self.rounding_dp) #dpadx

        self.new_command = self.developing_command
        
    def get_command(self, state, message_rate):

        self.current_command = self.new_command
        self.current_command.arm_event = self.arm_event
        self.current_command.trot_event = self.trot_event
        self.current_command.hop_event  = self.hop_event
        self.current_command.joystick_control_event = self.joystick_control_event
        self.arm_event = 0
        self.hop_event = 0
        self.trot_event = 0
        self.joystick_control_event = 0

        message_dt = 1.0 / message_rate

        deadbanded_pitch = deadband(
            self.current_command.pitch, self.config.pitch_deadband
        )
        #print(deadband)
        pitch_rate = clipped_first_order_filter(
            state.pitch,
            deadbanded_pitch,
            self.config.max_pitch_rate,
            self.config.pitch_time_constant,
        )
        #print(pitch_rate)
        
        self.current_command.pitch  = np.clip(state.pitch + message_dt * pitch_rate, -0.35,0.35)
        self.current_command.height = np.clip(state.height - message_dt * self.config.z_speed * self.current_command.height_movement,-0.27,-0.08)
        self.current_command.roll   = np.clip(state.roll + message_dt * self.config.roll_speed * self.current_command.roll_movement, -0.3,0.3)

        return self.current_command

