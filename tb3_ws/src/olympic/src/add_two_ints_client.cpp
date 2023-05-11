#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/set_pen.hpp"
#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;
using example_interfaces::srv::AddTwoInts;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  if (argc != 3) {
  	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
     "usage: set_pen X Y");
  	return 1;
  }
  std::shared_ptr<rclcpp::Node> node = 
  rclcpp::Node::make_shared("set_pen");
  rclcpp::Client<AddTwoInts>::SharedPtr client =
  node->create_client<set_pen>("set_pen");

  auto request = std::make_shared<AddTwoInts::Request>();
  request->r = atoll(argv[1]);
  request->g = atoll(argv[2]);
  request->b = atoll(argv[3]);
  request->width = atoll(argv[4]);
  request->off = atoll(argv[5]);

  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), 
       "Interrupted while waiting for the service.");
      return 0;
	 }
	 RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
     "service not available, waiting again...");
  }
     
  auto result = client->async_send_request(request);

  if (rclcpp::spin_until_future_complete(node, result) !=	rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), 
     "Failed to call service set_pen");
  }
  rclcpp::shutdown();
  return 0;
}

