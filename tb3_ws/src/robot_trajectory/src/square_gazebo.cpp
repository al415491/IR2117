#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[]) 	
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("publisher");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  geometry_msgs::msg::Twist message;
  rclcpp::WallRate loop_rate(10ms);

  for(int j=0; j<4; j++)
  {
  	int i=0, n=1000;
  	while (rclcpp::ok() && (i<n)) { // move forward 1m
  		i++;	
  		message.linear.x = 0.1;
  		message.angular.z = 0;
    	publisher->publish(message);
    	rclcpp::spin_some(node);
    	loop_rate.sleep();
  	}
  	// send zero velocity to topic
  	message.linear.x = 0;
  	publisher->publish(message);
  
  	i=0; 
  	n=1571; // a ojo
  	while (rclcpp::ok() && (i<n)) { // turn 90
  		i++;	
  		message.linear.x = 0;
  		message.angular.z = 0.1;
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
