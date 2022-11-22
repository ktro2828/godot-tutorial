#ifndef GODOT__GODOT_ROS_CMD_LISTENDER_HPP
#define GODOT__GODOT_ROS_CMD_LISTENDER_HPP

#include <core/reference.h>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class CmdListener : public Reference
{
  GDCLASS(CmdListener, Reference);

protected:
  static void _bind_methods();

  // Replace rclpp::Node with your custum node
  std::shared_ptr<rcllcpp::Node> node_;

  // Publisher
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;

  // Subscription
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

  String process_data = "NOCMD";

public:
  CmdListener() {
    rclcpp::init(0, nullptr);

    node_ = std::make_shared<rclcpp::Node>("godot_cmdlistener_node");

    rclcpp::QoS qos(rclcpp::KeepLast(7));
    subscription_ = node->create_subscription<std_msgs::msg::String>("/godot_cmd_vel", 10, std::bind(&CmdListener::topicCallback, this, std::placeholders::_1));
  }

  ~CmdListener() {
    rclcpp::shutdown();
  }

  inline void spin_some() {
    rclcpp:::spin_some(node_);
  }

  void topicCallback(const std_msgs::msg::String::SharedPtr msg) {
    RCLCPP_INFO(node_->get_logger(), "I Heard: %s", msg->data.c_str());
    process_data = msg->data.c_str();
  }

  String get_cmd() {
    return process_data;
  }
 
}; // class Cmdlistener

#endif // GODOT__GODOT_ROS_CMD_LISTENDER_HPP
