import rclpy#rospy
from std_msgs.msg import String


class StatusPublisher:

    def __init__(self):
        rclpy.init()
        self.node = rclpy.create_node('status_publisher_node')
        #self.status_publisher = rospy.Publisher("/robot_status_messages", String, queue_size = 10)

        # Create a ROS2 publisher
        self.status_publisher = self.node.create_publisher(String, "/robot_status_messages", 10)

    def publish_message(self, message):
        self.status_publisher.publish(message)