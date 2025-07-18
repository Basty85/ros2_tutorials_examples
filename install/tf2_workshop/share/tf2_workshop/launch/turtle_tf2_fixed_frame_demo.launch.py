import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch_ros.actions import Node


def generate_launch_description():
   demo_nodes = IncludeLaunchDescription(
      PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('tf2_workshop'), 'launch'),
            '/turtle_tf2_demo.launch.py']),
      )

   return LaunchDescription([
      demo_nodes,
      Node(
            package='tf2_workshop',
            executable='add_fixed_frame_off',
            name='fixed_broadcaster',
      ),
   ])