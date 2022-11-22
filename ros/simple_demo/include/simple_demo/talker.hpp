#ifndef GODOT__GODOT_ROS_TALKER_HPP
#define GODOT__GODOT_ROS_TALKER_HPP

#include <core/reference>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class Talker : public Reference
{
  GDCLASS(Talker, Reference);

protected:
  static void _bind_methods();

  // Replace rclcpp::Node with your custum node
  std::shared_ptr<rclcpp::Node> node_;

  // Publisher
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;

  // message to publish
  std::unique_ptr<std_msgs::msg::String> msg_;

public:
  Talker() {
    rclcpp::init(0, nullptr);

    node_ = std::make_shared<rclcpp::Node>("godot_talker_node");

    rclcpp::QoS qos(rclcpp::KeepLast(7));
    pub_ = node_->create_publisher<std_msgs::msg::String>("takler", qos);
  }

  ~Talker() {
    rclcpp::shutdown();
  }

  inline void spin_some() {
    rclcpp::spin_some(node_);
  }

  // Publish message
  inline void talk(const int & count) {
    msg_ = std::make_unique<std_msgs::msg::String>();
    msg_->data = "Hello from Godot: " + std::to_string(count);
    RCLCPP_INFO(node_->get_logger(), "Publishing: %s", msg_->data.c_str());

    pub_->publish(std::move(msg_));
  }

}; // class Talker
#endif // GODOT__GODOT_ROS_TALKER_HPP
