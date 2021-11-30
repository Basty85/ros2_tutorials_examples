#pragma once

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point32.hpp"

class Tq_Distbn_Publisher : public rclcpp::Node
{
public:
    Tq_Distbn_Publisher(const float &ext_tq_tar_pt_Nm, const float &ext_tq_tar_brk_Nm);

private:
    const float &tq_tar_pt_Nm;
    const float &tq_tar_brk_Nm;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Point32>::SharedPtr publisher_;
};