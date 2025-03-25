from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    dingo_description_dir = FindPackageShare('dingo_description').find('dingo_description')
    dingo_pybullet_dir = FindPackageShare('dingo_pybullet').find('dingo_pybullet')
    xacro_file = PathJoinSubstitution([dingo_description_dir, 'urdf', 'dingo.urdf'])
    world_file = PathJoinSubstitution([dingo_pybullet_dir, 'world', 'normal.world'])
    controllers_file = PathJoinSubstitution([dingo_pybullet_dir, 'config', 'controllers.yaml'])

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        DeclareLaunchArgument('robot', default_value=xacro_file),

        # Include the PyBullet simulation launch file
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([dingo_pybullet_dir, 'launch', 'empty_world.launch.py']),
            launch_arguments={'world_name': world_file, 'use_sim_time': LaunchConfiguration('use_sim_time')}.items()
        ),

        # Spawn the robot in PyBullet
        Node(
            package='pybullet_ros',
            executable='spawn_model',
            name='spawn_urdf',
            output='screen',
            arguments=['-param', 'robot_description', '-urdf', '-z', '3', '-model', 'dingo_pybullet'],
            parameters=[{'robot_description': LaunchConfiguration('robot')}]
        ),

        # Load controllers
        Node(
            package='controller_manager',
            executable='spawner',
            name='controller_spawner',
            output='screen',
            namespace='dingo_controller',
            arguments=[
                'FR_theta1', 'FR_theta2', 'FR_theta3',
                'FL_theta1', 'FL_theta2', 'FL_theta3',
                'RR_theta1', 'RR_theta2', 'RR_theta3',
                'RL_theta1', 'RL_theta2', 'RL_theta3'
            ],
            parameters=[controllers_file]
        ),

        # Robot State Publisher
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'publish_frequency': 10.0}],
            remappings=[('/joint_states', '/dingo_pybullet/joint_states')]
        )
    ])