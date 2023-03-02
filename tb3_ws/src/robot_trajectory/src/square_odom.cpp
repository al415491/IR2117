#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <cmath> //M_PI

using namespace std::chrono_literals;

double x; 
double y; 

void topic_callback(const nav_msgs::msg::Odometry::SharedPtr msg){
	x = msg->pose.pose.position.x;
	y = msg->pose.pose.position.y;
	std::cout << "Pos x: " << x << std::endl;
	std::cout << "Pos y: " << y << std::endl;
}

int main(int argc, char * argv[]) 	
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("subscriber");
  auto subscription = node->create_subscription<nav_msgs::msg::Odometry>("odom", 10, topic_callback);
  rclcpp::WallRate loop_rate(10ms);
  

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}





// Voy a 0.1 m/s --> 1m en 10s --> 10s = 10 000ms
// Mando looprates de 10ms así que utilizamos 10000/10 iteraciones = 1000


/*
90 grados = pi/2 radianes
Tiempo necesario para girar pi/2 radianes a 0.1 rad/s:
t = (pi/2) / 0.1 = 5*pi segundos

En un looprate de 10 ms, el número de iteraciones necesarias sería:

iteraciones = (5*pi segundos) / (0.01 segundos/iteración) = 1570.8 iteraciones

*/
