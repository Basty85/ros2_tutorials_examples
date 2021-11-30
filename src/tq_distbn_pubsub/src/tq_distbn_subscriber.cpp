#include "tq_distbn_pubsub/tq_distbn_subscriber.hpp"

using std::placeholders::_1;

Tq_Distbn_Subscriber::Tq_Distbn_Subscriber()

    :

      Node("tq_distbn_subscriber"),
      powertrain_tq_tar_total_Nm(0.0),
      powertrain_tq_recuperation_capacity_actual_Nm(0.0)

{
    subscription_ = this->create_subscription<tq_distbn_interface::msg::TwoTq>(
        "tq_distbn_in", 10, std::bind(&Tq_Distbn_Subscriber::topic_callback, this, _1));
}

void Tq_Distbn_Subscriber::topic_callback(const tq_distbn_interface::msg::TwoTq::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "tq_tar_total_Nm: '%f' tq_recu_capacity_Nm: '%f'", msg->tq_value1, msg->tq_value2);

    powertrain_tq_tar_total_Nm = msg->tq_value1;
    powertrain_tq_recuperation_capacity_actual_Nm = msg->tq_value2;
}
