#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import numpy as np
from geometry_msgs.msg import WrenchStamped


class Node:


    def __init__(self):
        super().__init__('calibrate_wrench_node')
        self._max_samples = self.declare_parameter('max_samples', 100)
        self._samples = []
        self._offset = None
        self._pub = self.create_publisher(WrenchStamped, 'wrench/calibrated', 10)
        self._sub = self.create_subscription(WrenchStamped, 'wrench', self._callback, 10)


    def _callback(self, msg):

        n_samples = len(self._samples)

        if n_samples < self._max_samples:
            self._samples.append(msg.wrench)

        elif (n_samples == self._max_samples) and self._offset is None:

            offset = np.array([
                [s.force.x,
                 s.force.y,
                 s.force.z,
                 s.torque.x,
                 s.torque.y,
                 s.torque.z]
                for s in self._samples
            ])

            self._offset = offset.mean(axis=0)

        else:

            msg.wrench.force.x -= self._offset[0]
            msg.wrench.force.y -= self._offset[1]
            msg.wrench.force.z -= self._offset[2]
            msg.wrench.torque.x -= self._offset[3]
            msg.wrench.torque.y -= self._offset[4]
            msg.wrench.torque.z -= self._offset[5]

            self._pub.publish(msg)


    def spin(self):
        rclpy.spin(self)


def main():
    Node().spin()


if __name__ == '__main__':
    main()
