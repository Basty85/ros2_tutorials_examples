#pragma once

#include "rclcpp/rclcpp.hpp"
#include "tq_distbn_interface/msg/two_tq.hpp"


class Tq_Distbn_Publisher : public rclcpp::Node
{
public:
    Tq_Distbn_Publisher(const float &ext_tq_tar_pt_Nm, const float &ext_tq_tar_brk_Nm);

private:
    const float &tq_tar_pt_Nm;
    const float &tq_tar_brk_Nm;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<tq_distbn_interface::msg::TwoTq>::SharedPtr publisher_;
};