#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <cmath> //M_PI
#include <Eigen/Dense>

#include <vector>

using namespace std::chrono_literals;

std::vector<float> vector;
float min_val;

void topic_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
   {
	
	vector = msg->ranges;
	
	// Mostrar rango
	for ( int i = 9; i>0; i--) {
    std::cout << vector[i] << " ";
    }
    
    for ( int i = 359; i>350; i--) {
    std::cout << vector[i] << " ";
    }
    
    std::cout << std::endl;
    
    // Mostrar mínimo
    Eigen::Map<Eigen::VectorXf> eigen_vector(vector.data(), vector.size());
    
    min_val = eigen_vector.minCoeff();
    
    std::cout << "Minimum value: " << min_val << std::endl;
   }
    

int main(int argc, char * argv[]) 	
{
  
  rclcpp::init(argc, argv);
  //subscriber
  auto node = rclcpp::Node::make_shared("subscriber");
  auto subscription = node->create_subscription<sensor_msgs::msg::LaserScan>("scan", 10, topic_callback);
  
  // publisher
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  geometry_msgs::msg::Twist message;
  rclcpp::WallRate loop_rate(10ms);
  
  const sensor_msgs::msg::LaserScan::SharedPtr msg;
  
   while (rclcpp::ok()) // move forward 
  {
   	message.linear.x = 0;
  	message.angular.z = 0;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    
  }
  
  rclcpp::shutdown();
  return 0;
}

/*
  node->declare_parameter("linear_speed", 0.2);
  node->declare_parameter("angular_speed", 0.2);
  node->declare_parameter("square_length", 1.0);
  double linear_speed = node->get_parameter("linear_speed").get_parameter_value().get<double>();
  double angular_speed = node->get_parameter("angular_speed").get_parameter_value().get<double>();
  double square_length = node->get_parameter("square_length").get_parameter_value().get<double>();
  
  
  for ( int i = 1; i<=4; i++ ) {
  
  
  while (rclcpp::ok() && (distance<square_length)) // move forward 
  {
   	message.linear.x = linear_speed;
  	message.angular.z = 0;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
 
  // send zero velocity to topic
  
  
  message.linear.x = 0;
  publisher->publish(message);
  rclcpp::spin_some(node);
  loop_rate.sleep();
  initial_xp = xp;
  initial_yp = yp;
  loop_rate.sleep();
  
  
  double target_angle = M_PI_2 + initial_angle;
 
  if (target_angle > 2*M_PI) { // Por unas céntesimas puede que el robot se quede girando en bucle
  	target_angle = 6.28
  	;
  }
  std::cout << "target angle: " << target_angle << std::endl;
  
  
  while (rclcpp::ok() && (angle < (target_angle) )) // turn 90 
  {
   std::cout << target_angle << std::endl;
   message.linear.x = 0;
   if ( (target_angle - angle) > 0.25 ) {
   	message.angular.z = angular_speed;
   } else {
   		message.angular.z = 0.1;
   }
   publisher->publish(message);
   rclcpp::spin_some(node);
   loop_rate.sleep();
  }
  message.angular.z = 0;
  publisher->publish(message);
  initial_angle = angle;
  loop_rate.sleep(); 
  */

