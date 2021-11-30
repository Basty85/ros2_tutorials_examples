from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='sim'
        ),
        Node(
            package='turtlesim',
            executable='turtle_teleop_key',
            name='sim_teleop_key',
            prefix=['gnome-terminal -x']
            #prefix=['terminator -x']
        ),
        Node(
            package='tf2_workshop',
            executable='add_fixed_frame_off',
            name='add_frame_carrot1'
        ),
        Node(
            package='tf2_workshop',
            executable='broadcaster_off',
            name='broadcaster1',
            parameters=[
                {'turtlename': 'turtle1'}
            ]
        ),
        DeclareLaunchArgument(
            'target_frame', default_value='turtle1',
            description='Target frame name.'
        ),
        Node(
            package='tf2_workshop',
            executable='broadcaster_off',
            name='broadcaster2',
            parameters=[
                {'turtlename': 'turtle2'}
            ]
        ),
        Node(
            package='tf2_workshop',
            executable='listener_off',
            name='listener',
            parameters=[
                {'target_frame': LaunchConfiguration('target_frame')}
            ]
        ),
    ])