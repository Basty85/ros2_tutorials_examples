#pragma once

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point32.hpp"

class Tq_Distbn_Subscriber : public rclcpp::Node
{
public:
    Tq_Distbn_Subscriber();

    const float &get_powertrain_tq_tar_total() { return powertrain_tq_tar_total_Nm; }
    const float &get_powertrain_tq_recuperation_capacity_actual()
    {
        return powertrain_tq_recuperation_capacity_actual_Nm;
    }

private:
    void topic_callback(const geometry_msgs::msg::Point32::SharedPtr msg);

    float powertrain_tq_tar_total_Nm;
    float powertrain_tq_recuperation_capacity_actual_Nm;

    rclcpp::Subscription<geometry_msgs::msg::Point32>::SharedPtr subscription_;
};