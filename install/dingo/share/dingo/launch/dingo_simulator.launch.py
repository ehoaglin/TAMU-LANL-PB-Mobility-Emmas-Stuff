from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    dingo_pybullet_launch_dir = FindPackageShare('dingo_pybullet').find('dingo_pybullet') + '/launch'

    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([dingo_pybullet_launch_dir, '/simulation.launch.py'])
        )
    ])