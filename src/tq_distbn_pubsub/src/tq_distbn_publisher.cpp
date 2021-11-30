#include "tq_distbn_pubsub/tq_distbn_publisher.hpp"

using namespace std::chrono_literals;

Tq_Distbn_Publisher::Tq_Distbn_Publisher(const float &ext_tq_tar_pt_Nm, const float &ext_tq_tar_brk_Nm)

    :

      Node("tq_distbn_publisher"),
      tq_tar_pt_Nm(ext_tq_tar_pt_Nm),
      tq_tar_brk_Nm(ext_tq_tar_brk_Nm)
{
    publisher_ = this->create_publisher<tq_distbn_interface::msg::TwoTq>("tq_distbn_out", 10);

    auto publish_msg = [this]() -> void
    {
        auto message = tq_distbn_interface::msg::TwoTq();

        message.tq_value1 = tq_tar_pt_Nm;
        message.tq_value2 = tq_tar_brk_Nm;

        std::cout << "tq_tar_pt:" << message.tq_value1 << "  tq_tar_brk:" << message.tq_value2 << std::endl;

        this->publisher_->publish(message);
    };
    timer_ = this->create_wall_timer(0.001s, publish_msg);
}
