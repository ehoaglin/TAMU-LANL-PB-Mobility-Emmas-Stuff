from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.conditions import IfCondition
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('is_sim', default_value='1'),
        DeclareLaunchArgument('is_physical', default_value='0'),
        DeclareLaunchArgument('use_joystick', default_value='1'),
        DeclareLaunchArgument('use_keyboard', default_value='0'),
        DeclareLaunchArgument('serial_port', default_value='/dev/ttyS0'),
        DeclareLaunchArgument('use_imu', default_value='0'),

        GroupAction([
            Node(
                package='rosserial_python',
                executable='serial_node.py',
                name='dingo_rosserial',
                output='screen',
                parameters=[{'serial_port': LaunchConfiguration('serial_port')}]
            ),
            Node(
                package='dingo_peripheral_interfacing',
                executable='dingo_lcd_interfacing.py',
                name='dingo_LCD_node',
                output='screen'
            )
        ], condition=IfCondition(LaunchConfiguration('is_physical'))),

        GroupAction([
            Node(
                package='dualsense_interface',
                executable='hidraw_to_joy.py',
                name='hidraw_joy_node',
                output='screen',
                parameters=[{'device': '/dev/hidraw0'}]  # Update the device path if necessary
            )
        ], condition=IfCondition(LaunchConfiguration('use_joystick'))),

        GroupAction([
            Node(
                package='dingo_input_interfacing',
                executable='Keyboard.py',
                name='keyboard_input_listener',
                output='screen'
            )
        ], condition=IfCondition(LaunchConfiguration('use_keyboard'))),

        Node(
            package='dingo',
            executable='dingo_driver.py',
            name='dingo_driver_node',
            output='screen',
            parameters=[
                {'is_sim': LaunchConfiguration('is_sim')},
                {'is_physical': LaunchConfiguration('is_physical')},
                {'use_imu': LaunchConfiguration('use_imu')}
            ]
        )
    ])