#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <cmath> //M_PI

using namespace std::chrono_literals;

int main(int argc, char * argv[]) 	
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("square");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  node->declare_parameter("linear_speed", 0.1);
  node->declare_parameter("angular_speed", M_PI / 20);
  geometry_msgs::msg::Twist message;
  rclcpp::WallRate loop_rate(10ms);

  double linear_speed = node->get_parameter("linear_speed").get_parameter_value().get<double>();
  double angular_speed = node->get_parameter("angular_speed").get_parameter_value().get<double>();
  for(int j=0; j<4; j++)
  { 
  	int linear_iterations = 1 / (0.01 * linear_speed);
  	int i=0;
  	while (rclcpp::ok() && (i<linear_iterations)) { // move forward 1m
  		i++;	
  		message.linear.x = linear_speed;
  		message.angular.z = 0;
    	publisher->publish(message);
    	rclcpp::spin_some(node);
    	loop_rate.sleep();
  	}
  	// send zero velocity to topic
  	message.linear.x = 0;
  	publisher->publish(message);
  	
  	
    i=0; 
    double angular_iterations = (1.57 /angular_speed)/0.01;
    // (tiempo en girar 90ª/velocidad) / looprate
  	while (rclcpp::ok() && (i<angular_iterations)) { // turn 90
  		i++;	
  		message.linear.x = 0;
  		message.angular.z = angular_speed;
    	publisher->publish(message);
    	rclcpp::spin_some(node);
    	loop_rate.sleep();
  	}
  	message.angular.z = 0;
  	publisher->publish(message);
  }
  
  
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
