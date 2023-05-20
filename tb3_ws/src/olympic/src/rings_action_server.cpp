#include <inttypes.h>
#include <memory>
#include "olympic_interfaces/action/rings.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

using Rings = 
  olympic_interfaces::action::Rings;

using GoalHandleRings = 
  rclcpp_action::ServerGoalHandle<Rings>;

rclcpp_action::GoalResponse handle_goal(
  const rclcpp_action::GoalUUID & uuid, 
  std::shared_ptr<const Rings::Goal> goal)
{
  RCLCPP_INFO(rclcpp::get_logger("server"), 
    "Got goal request with radius %d", goal->radius);
  (void)uuid;
  return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse handle_cancel(
  const std::shared_ptr<GoalHandleRings> goal_handle)
{
  RCLCPP_INFO(rclcpp::get_logger("server"), 
    "Got request to cancel goal");
  (void)goal_handle;
  return rclcpp_action::CancelResponse::ACCEPT;
}

void execute(const std::shared_ptr<GoalHandleRings>);

void handle_accepted(const std::shared_ptr<GoalHandleRings> goal_handle){
  std::thread{execute, goal_handle}.detach();
}


void execute(const std::shared_ptr<GoalHandleRings> goal_handle) {
  RCLCPP_INFO(rclcpp::get_logger("server"), 
    "Executing goal");
  rclcpp::Rate loop_rate(1);
  const auto goal = goal_handle->get_goal();
  auto feedback = std::make_shared<Rings::Feedback>();
  auto result = std::make_shared<Rings::Result>();
  
    for (int i = 1; (i < goal->radius) && rclcpp::ok(); ++i) {
    if (goal_handle->is_canceling()) {
      
      goal_handle->canceled(result);
      RCLCPP_INFO(rclcpp::get_logger("server"), 
        "Goal Canceled");
      return;
  }
    }
    if (rclcpp::ok()) {
    goal_handle->succeed(result);
    RCLCPP_INFO(rclcpp::get_logger("server"), 
      "Goal Succeeded");
  }
}

int main(int argc, char ** argv){
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("action_server");
  auto action_server = 
    rclcpp_action::create_server<Rings>(node,
      "rings",
      handle_goal,
      handle_cancel,
      handle_accepted);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}




