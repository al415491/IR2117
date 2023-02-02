#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[]) 	
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("publisher");
  auto publisher = node->create_publisher<std_msgs::msg::String>("topic", 10);
  std_msgs::msg::String message;
  auto publish_count = 0;
  rclcpp::WallRate loop_rate(500ms);

  while (rclcpp::ok()) {
    message.data = "Hello, world! " + std::to_string(publish_count++);
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}


/*
rclcpp:: library de ros
l10 inicializa nodo --> objeto de la clase Node dentro de la biblioteca rclcpp
l11 creamos un objeto publisher dentro de node que publicara en un topic en formato string
l12 variable msg 
l16 True hasta que hagamos ctrl+c
l18 publica
l19 Se ocupa de que no acabe el programa hasta hacer ctrl+c o se ocupa de cosas pendientes
l20 pausa de 500 ms

*/

