#include <chrono>
#include <cmath> //M_PI
#include <memory>
#include <cstdlib>
#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/set_pen.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;
using turtlesim::srv::SetPen;

// void add(std::shared_ptr<SetPen::Request> request)
// {
//   RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
//               "Incoming request\nr: %ld, g: %ld, b: %ld, width: %ld, off: %ld",
//               request->r, request->g, request->b, request->width, request->off);
// }

int main(int argc, char* argv[])
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



  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to set pen.");

  //set_pen client
  auto client = node->create_client<SetPen>("set_pen");
  
  auto request = std::make_shared<SetPen::Request>();
  request->r = std::atoll(argv[1]);
  request->g = std::atoll(argv[2]);
  request->b = std::atoll(argv[3]);
  request->width = std::atoll(argv[4]);
  request->off = std::atoll(argv[5]);

  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
  }

  auto result = client->async_send_request(request);
  // Wait for the result
  if (rclcpp::spin_until_future_complete(node,result) == rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Todo bien");
  } else  {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service SetPen");
  }
    
  //off
  rclcpp::shutdown();
  return 0;
}


