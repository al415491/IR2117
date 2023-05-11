#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/set_pen.hpp"
#include <memory>
using turtlesim::srv::set_pen;

void add(
  std::shared_ptr<set_pen::Request>  request,
)
{
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
    "Incoming request\na: %ld" " b: %ld",
     request->a, request->b, request->g, request->width, request->off);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = 
    rclcpp::Node::make_shared("set_pen_server");

  rclcpp::Service<set_pen>::SharedPtr service =
	 node->create_service<set_pen>("set_pen", &add);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
    "Ready to set pen.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}

