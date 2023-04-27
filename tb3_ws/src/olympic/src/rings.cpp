#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <cmath> //M_PI

using namespace std::chrono_literals;

int main(int argc, char * argv[]) 	
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("rings");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
  node->declare_parameter("radius", 1.0);
  geometry_msgs::msg::Twist message;
  rclcpp::WallRate loop_rate(10ms);

  double radius = node->get_parameter("radius").get_parameter_value().get<double>();
  
  double time_for_circle = 2 * M_PI * radius / 1.0; // time to complete a circle
  int num_iterations = static_cast<int>(time_for_circle / 0.01); // number of iterations to complete a circle

  for (int i = 0; i < num_iterations; i++) { // do circle
    message.linear.x = 1;
    message.angular.z = 2 * M_PI / time_for_circle;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  
  // send zero velocity to topic  	
  message.linear.x = 0;
  message.angular.z = 0;
  publisher->publish(message);
  
  rclcpp::shutdown();
  return 0;
}






