#include "tq_distbn_pubsub/tq_distbn_publisher_std_msg.hpp"

using namespace std::chrono_literals;

Tq_Distbn_Publisher::Tq_Distbn_Publisher(const float &ext_tq_tar_pt_Nm, const float &ext_tq_tar_brk_Nm)

    :

      Node("tq_distbn_publisher"),
      tq_tar_pt_Nm(ext_tq_tar_pt_Nm),
      tq_tar_brk_Nm(ext_tq_tar_brk_Nm)
{
    publisher_ = this->create_publisher<geometry_msgs::msg::Point32>("tq_distbn_out", 100);

    auto publish_msg = [this]() -> void
    {
        auto message = geometry_msgs::msg::Point32();

        message.x = tq_tar_pt_Nm;
        message.y = tq_tar_brk_Nm;
        message.z = 0.0;

        std::cout << "tq_tar_pt:" << message.x << "  tq_tar_brk:" << message.y << std::endl;

        this->publisher_->publish(message);
    };
    timer_ = this->create_wall_timer(0.001s, publish_msg);
}