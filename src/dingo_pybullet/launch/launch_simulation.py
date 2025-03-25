from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    #dingo_description_dir = FindPackageShare('dingo_description').find('dingo_description')
    dingo_pybullet_dir = FindPackageShare('dingo_pybullet').find('dingo_pybullet')
    xacro_file = PathJoinSubstitution(["dingo_description", 'urdf', 'dingo.urdf'])
    world_file = PathJoinSubstitution([dingo_pybullet_dir, 'world', 'normal.world'])
    controllers_file = PathJoinSubstitution([dingo_pybullet_dir, 'config', 'controllers.yaml'])
    return LaunchDescription([
        Node(
            package='dingo_pybullet',
            executable='launch_robot.py',
            name='pybullet_sim_node',
            output='screen'
        ),
    ])