#!/usr/bin/env python3

import rclpy
import struct
from rclpy.node import Node
from sensor_msgs.msg import Joy

class HIDRawJoyNode(Node):
    def __init__(self):
        super().__init__('hidraw_joy_node')

        # Declare and get parameters
        self.declare_parameter('device', '/dev/hidraw0')  # Change if needed to match local dev file in computer, mine is hidraw0 but yours migth be different
        self.device_path = self.get_parameter('device').value

        # Publisher for Joy messages
        self.joy_pub = self.create_publisher(Joy, 'joy', 10)

        # Open the hidraw device
        try:
            self.hidraw = open(self.device_path, 'rb')
            self.get_logger().info(f"Opened HIDRAW device: {self.device_path}")
        except Exception as e:
            self.get_logger().error(f"Failed to open {self.device_path}: {e}")
            return

        # Start reading loop
        self.read_loop()


    def read_loop(self):
        while rclpy.ok():
            try:
                # Read 64 bytes (PS5 controllers typically send 64-byte reports)
                raw_data = self.hidraw.read(64)
                if not raw_data:
                    continue

                # Process raw HID data
                joy_msg = self.parse_hidraw(raw_data)

                # Publish message
                self.joy_pub.publish(joy_msg)
            except Exception as e:
                self.get_logger().error(f"Error reading HIDRAW device: {e}")
                break


    def parse_hidraw(self, data):
        """ Parse raw HID data into a Joy message """
        try:
            joy_msg = Joy()
            joy_msg.header.stamp = self.get_clock().now().to_msg()

            # Extract joystick axes (left & right stick)
            joy_msg.axes = list([
                
                (data[1] - 128) / (128.0),  # Left stick X (-1 to 1)
                (data[2] - 128) / (-128.0),     # Left stick Y (-1 to 1)
                (data[3] - 128) / (128.0),  # Right stick X (-1 to 1)
                (data[4] - 128) / (-128.0),     # Right stick Y (-1 to 1)
                (data[5]) / 255,       # L2
                (data[6]) / 255,       # R2
            ])

            # Extract hat switch (D-pad)
            hat_switch = data[8] & 0x0F
            dpad = [0, 0]  # [X, Y]

            if hat_switch == 0:  # Up
                dpad = [0, 1]
            elif hat_switch == 1:  # Up-Right
                dpad = [1, 1]
            elif hat_switch == 2:  # Right
                dpad = [1, 0]
            elif hat_switch == 3:  # Down-Right
                dpad = [1, -1]
            elif hat_switch == 4:  # Down
                dpad = [0, -1]
            elif hat_switch == 5:  # Down-Left
                dpad = [-1, -1]
            elif hat_switch == 6:  # Left
                dpad = [-1, 0]
            elif hat_switch == 7:  # Up-Left
                dpad = [-1, 1]

            joy_msg.axes.extend(list(dpad))  # Ensure list format


            # Extract buttons (example mapping, may need adjustments)
            joy_msg.buttons = list([
                (data[8] & 0x10) >> 4,  # Square
                (data[8] & 0x20) >> 5,  # Cross (X)
                (data[8] & 0x40) >> 6,  # Circle
                (data[8] & 0x80) >> 7,  # Triangle
                (data[9] & 0x01),       # L1
                (data[9] & 0x02) >> 1,  # R1
                (data[9] & 0x04) >> 2,  # L2
                (data[9] & 0x08) >> 3,  # R2
                (data[9] & 0x10) >> 4,  # Create
                (data[9] & 0x20) >> 5,  # Options
                (data[9] & 0x40) >> 6,  # L3
                (data[9] & 0x80) >> 7,  # R3
                (data[10] & 0x01),      # PS button
                (data[10] & 0x02) >> 1, # Touchpad button
                (data[10] & 0x04) >> 2, # Mute button
            ])
            
            return joy_msg
        except Exception as e:
            self.get_logger().error(f"Error parsing HID data: {e}")
            return None

def main():
    rclpy.init()
    node = HIDRawJoyNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
# to run, in split terminal first run 'python3 hidraw_to_joy.py'
# in other terminal run 'ros2 topic echo /joy'

