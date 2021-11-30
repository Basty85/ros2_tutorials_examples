// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point32.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
public:
    MinimalPublisher() : Node("tq_distbn_input_provider_publisher"), count_(0), my_time(0.0)
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Point32>("tq_distbn_in", 100);
        timer_ = this->create_wall_timer(
            100ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto message = geometry_msgs::msg::Point32();
        my_time = count_ * 0.1;
        message.x = 100 * std::sin(2 * M_PI * 0.5 * my_time ) - 50.0; //tq_tar_total
        message.y = -100.0; //recu_capacity
        message.z = 0.0;
        
        RCLCPP_INFO(this->get_logger(), "x: '%f', y: '%f'", message.x, message.z);
        RCLCPP_INFO(this->get_logger(), "my_time: '%f'", my_time);
        publisher_->publish(message);
        count_ += 1;
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Point32>::SharedPtr publisher_;
    size_t count_;
    float my_time;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}
