#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <cmath> //M_PI

using namespace std::chrono_literals;

double xp; 
double yp; 
double xo; 
double yo;
double angle;
double initial_xp;
double initial_yp;
double initial_angle;
double distance;
 

void topic_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
	if (initial_xp == 0 && initial_yp == 0 && initial_angle == 0) {
        initial_xp = msg->pose.pose.position.x;
        initial_yp = msg->pose.pose.position.y;
        initial_angle = std::atan2(msg->pose.pose.orientation.y, msg->pose.pose.orientation.x);
    }
	xp = msg->pose.pose.position.x;
	yp = msg->pose.pose.position.y;
	xo = msg->pose.pose.orientation.x;
	yo = msg->pose.pose.orientation.y;
	angle = std::atan2(yo, xo);
	distance = std::sqrt(std::pow(xp - initial_xp, 2) + std::pow(yp - initial_yp, 2));
	std::cout << "Initial x: " << initial_xp << std::endl;
	std::cout << "Initial y: " << initial_yp << std::endl;
	std::cout << "Pos x: " << xp << std::endl;
	std::cout << "Pos y: " << yp << std::endl;
	std::cout << "Angle in radians: " << angle << std::endl;
	std::cout << "distance: " << distance << std::endl;
	std::cout << "----------" << std::endl;
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
