from launch import LaunchDescription
from launch_ros.actions import Node
import launch.actions

def generate_launch_description():
	return LaunchDescription([
	  launch.actions.DeclareLaunchArgument('bagfile'),
	  launch.actions.ExecuteProcess(
	  	cmd=['ros2', 'bag', 'play',
	  		launch.substitutions.LaunchConfiguration('bagfile')],
	  	output='screen'
	  ),
	  Node(
	  	package='obstacles',
	  	executable='detector'
	  	namespace='front',
	  	parameters=[
	  		{"obs_angle_min": -0.3927},
	  		{"obs_angle_max": 0.3927},
	  		{"obs_threshold":	1.0}]
	  	)
	  Node(
	  	package='obstacles',
	  	executable='detector'
	  	namespace='left',
	  	parameters=[
	  		{"obs_angle_min": 0.3927},
	  		{"obs_angle_max": 1.1781},
	  		{"obs_threshold":	1.0}]
	  	)
	  Node(
	  	package='obstacles',
	  	executable='detector'
	  	namespace='right',
	  	parameters=[
	  		{"obs_angle_min": -1.1781},
	  		{"obs_angle_max": -0.3927},
	  		{"obs_threshold":	1.0}]
	  	)
	])
