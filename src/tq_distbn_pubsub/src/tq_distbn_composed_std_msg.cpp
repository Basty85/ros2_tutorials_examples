#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point32.hpp"
#include "tq_distbn_pubsub/tq_distbn_publisher_std_msg.hpp"
#include "tq_distbn_pubsub/tq_distbn_srv.hpp"
#include "tq_distbn_pubsub/tq_distbn_subscriber_std_msg.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::executors::SingleThreadedExecutor exec;
    // rclcpp::NodeOptions options;

    // input instance
    auto subscriber_node = std::make_shared<Tq_Distbn_Subscriber>();
    // business logic instance
    auto tq_distbn_srv = std::make_shared<Torque_Distribution_Service>(
        subscriber_node->get_powertrain_tq_tar_total(),
        subscriber_node->get_powertrain_tq_recuperation_capacity_actual());
    // output instance
    auto publisher_node = std::make_shared<Tq_Distbn_Publisher>(tq_distbn_srv->get_tq_tar_pt(),
                                                                tq_distbn_srv->get_tq_tar_brk());

    exec.add_node(subscriber_node);
    exec.add_node(tq_distbn_srv);
    exec.add_node(publisher_node);

    exec.spin();

    rclcpp::shutdown();

    return 0;
}
