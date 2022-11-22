#ifndef GODOT__GODOT_ROS_VIEW_PORT_HPP
#define GODOT__GODOT_ROS_VIEW_PORT_HPP

#include <core/reference.h>
#include <core/image.h>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>

#include <cstring>
#include <iostream>


class ViewPort : public Reference
{
  GDCLASS(ViewPort, Reference);

protected:
  static void _bind_methods();

  // Replace rclcpp::Node with your custum node
  std::shared_ptr<rclcpp::Node> node_;

  // Publisher
  rclcpp::Publisher<sesor_msgs::msg::Image>::SharedPtr pub_;

  // message to publish
  std::unique_ptr<sensor_msgs::msg::Image> msg_;

public:
  ViewPort() {
    rclcpp::init(0, nullptr);

    node_ = std::make_shared<rclcpp::Node>("godot_image_node");
    pub_ = node_->create_publisher<sensor_msgs::msg::Image>("image", 10);
  }

  ~ViewPort() {
    rclcpp::shutdown();
  }

  inline void spin_some() {
    rclcpp::spin_some(node_);
  }

  inline void pubImage(const Ref<Image> &img) {
    msg_ = std::make_shared<sensor_msgs::msg::Image>();
    // populate image data
    msg_->height = img->get_height();
    msg_->width = img->get_width();

    msg_->encoding = "rgb8";
    msg_->is_bigendian = false;
    msg_->step = img->get_data().size() / msg_->height;
    mgs_->data.resize(img->get_data().size());
    std::memcopy(&msg_->data[0], img->get_data().write().ptr(), img->get_data().size());

    pub_->publish(std::move(msg_));
  }
}; // class; ViewPort

#endif // GODOT__GODOT_ROS_VIEW_PORT_HPP
