import numpy as np


class Command:
    """Stores movement command
    """

    def __init__(self):
        self.horizontal_velocity = np.array([0, 0])
        #self.arm_movement = np.array([0, -75, 160, 180])
        self.arm_joint1_rate = 0.0
        self.arm_joint2_rate = 0.0
        self.arm_joint3_rate = 0.0
        self.arm_joint4_rate = 0.0
        self.yaw_rate = 0.0
        self.height = -0.28
        self.pitch = 0.0
        self.roll = 0.0
        self.joystick_control_active = 0
        self.trotting_active = 0

        self.height_movement = 0
        self.roll_movement = 0
        
        self.hop_event = False
        self.trot_event = False
        self.arm_event = False
        self.joystick_control_event = False
    
    def __repr__(self):
        return (f"Command(horizontal_velocity={self.horizontal_velocity}, "
                f"yaw_rate={self.yaw_rate}, pitch={self.pitch}, "
                f"height_movement={self.height_movement}, roll_movement={self.roll_movement}, "
                f"trot_event={self.trot_event}, hop_event={self.hop_event}, "
                f"joystick_control_event={self.joystick_control_event})")