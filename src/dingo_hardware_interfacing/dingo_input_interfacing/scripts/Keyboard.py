import rclpy
import sys, signal
import os
from pynput import keyboard # used sudo apt install python3-pynput to install
from sensor_msgs.msg import Joy

class Keyboard:
    def __init__(self):
        super().__init__('keyboard input listner') #initialize ROS2 node, unfortunately :(
        self.used_keys = ['w','a','s','d','1','2', '7','8','9','0', keyboard.Key.shift, keyboard.Key.backspace, keyboard.Key.up, keyboard.Key.down, keyboard.Key.left, keyboard.Key.right]
        self.speed_multiplier = 1
        self.joystick_message_pub = self.create_publisher(Joy, "joy", 10) #changed from rospy.Publisher("joy", Joy, queue_size=10) to self.create_publisher(Joy, "joy", 10)
        self.keyboard_listener = keyboard.Listener(
            on_press=self.on_press,
            on_release=self.on_release)
        self.keyboard_listener.start()

        self.current_joy_message = Joy()
        self.current_joy_message.axes = [0.,0.,0.,0.,0.,0.,0.,0.]
        self.current_joy_message.buttons = [0,0,0,0,0,0,0,0,0,0,0]

        
    def on_press(self,key):
        if hasattr(key, 'char'):
            key = key.char
        msg = self.current_joy_message

        if key == keyboard.Key.shift:
            self.speed_multiplier = 2
        elif key == 'w' or key == 'W':
            msg.axes[1] = 0.5*self.speed_multiplier
        elif key == 's' or key == 'S':
            msg.axes[1] = -0.5*self.speed_multiplier
        elif key == 'a' or key == 'A':
            msg.axes[0] = 0.5*self.speed_multiplier
        elif key == 'd' or key == 'D':
            msg.axes[0] = -0.5*self.speed_multiplier
        elif key == '1':
            msg.buttons[5] = 1
        elif key == '2':
            msg.buttons[0] = 1
        elif key == keyboard.Key.backspace:
            msg.buttons[4] = 1
        elif key == keyboard.Key.up:
            msg.axes[4] = 0.5*self.speed_multiplier
        elif key == keyboard.Key.down:
            msg.axes[4] = -0.5*self.speed_multiplier
        elif key == keyboard.Key.left:
            msg.axes[3] = 0.5*self.speed_multiplier
        elif key == keyboard.Key.right:
            msg.axes[3] = -0.5*self.speed_multiplier
        elif key == '0':
            msg.axes[7] = 1
        elif key == '9':
            msg.axes[7] = -1
        elif key == '8':
            msg.axes[6] = 1
        elif key == '7':
            msg.axes[6] = -1
        else: return
        self.current_joy_message = msg
        return

    def on_release(self, key):
        if hasattr(key, 'char'):
            key = key.char

        msg = self.current_joy_message

        if key == keyboard.Key.shift:
            self.speed_multiplier = 1
        elif key == 'w' or key == 'W':
            msg.axes[1] = 0.0
        elif key == 's' or key == 'S':
            msg.axes[1] = 0.0
        elif key == 'a' or key == 'A':
            msg.axes[0] = 0.0
        elif key == 'd' or key == 'D':
            msg.axes[0] = 0.0
        elif key == '1':
            msg.buttons[5] = 0
        elif key == '2':
            msg.buttons[0] = 0
        elif key == keyboard.Key.backspace:
            msg.buttons[4] = 0
        elif key == keyboard.Key.up:
            msg.axes[4] = 0.0
        elif key == keyboard.Key.down:
            msg.axes[4] = 0.0
        elif key == keyboard.Key.left:
            msg.axes[3] = 0.0
        elif key == keyboard.Key.right:
            msg.axes[3] = 0.0
        elif key == '0':
            msg.axes[7] = 1
        elif key == '9':
            msg.axes[7] = -1
        elif key == '8':
            msg.axes[6] = 1
        elif key == '7':
            msg.axes[6] = -1

        
        self.current_joy_message = msg
    
    def publish_current_command(self):
        self.current_joy_message.header.stamp = self.get_clock().now().to_msg() #changed from rospy.Time.now() to self.get_clock().now().to_msg()
        self.joystick_message_pub.publish(self.current_joy_message)

def signal_handler(sig, frame):
    sys.exit(0)

def main(): 

    rclpy.init() #new, to bring in the init function from earlier
    """Main program
    """
    #initialize keybpard node
    #changed from rospy.init_node("keyboard_input_listener") to self.get_clock().now().to_msg()
    
    

    if os.getenv("DISPLY", default="-") != "-":
        print("This device does not have a display connected. The keyboard node requires a connected display due to a limitation of the underlying package. Keyboard node now shutting down") #changed from rospy.logfatal() to print()
        #rclpy.shutdown()#changed from rospy.sleep(1) to rclpy.shutdown()
        sys.exit(0)

    keyboard_listener = Keyboard()

    signal.signal(signal.SIGINT, signal_handler)

    rate = keyboard_listener.create_rate(30) #changed from rate = rospy.Rate(30) to rate = keyboard_listener.create_rate(30)
    

    while rclpy.ok(): #changed from while not rospy.is_shutdown(): to while rclpy.ok():
        keyboard_listener.publish_current_command()
        rate.sleep()

main()