cmake_minimum_required(VERSION 3.8)
project(tq_distbn_pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(include)

add_library(tq_distbn_srv src/tq_distbn_srv.cpp)
add_library(composition_nodes SHARED
            src/tq_distbn_publisher.cpp
            src/tq_distbn_subscriber.cpp)

add_library(composition_nodes_std_msg SHARED
            src/tq_distbn_publisher_std_msg.cpp
            src/tq_distbn_subscriber_std_msg.cpp)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tq_distbn_interface REQUIRED)
find_package(geometry_msgs REQUIRED)


add_executable(tq_distbn_pubsub_node src/tq_distbn_composed.cpp src/tq_distbn_subscriber.cpp src/tq_distbn_publisher.cpp)
ament_target_dependencies(tq_distbn_pubsub_node rclcpp tq_distbn_interface)
ament_target_dependencies(composition_nodes rclcpp tq_distbn_interface)
ament_target_dependencies(tq_distbn_srv rclcpp)

add_executable(tq_distbn_pubsub_node_std_msg src/tq_distbn_composed_std_msg.cpp src/tq_distbn_subscriber_std_msg.cpp src/tq_distbn_publisher_std_msg.cpp)
ament_target_dependencies(tq_distbn_pubsub_node_std_msg rclcpp geometry_msgs)
ament_target_dependencies(composition_nodes_std_msg rclcpp geometry_msgs)

add_executable(tq_distbn_input_provider_publisher src/tq_distbn_input_provider_publisher)
ament_target_dependencies(tq_distbn_input_provider_publisher rclcpp geometry_msgs)

ament_export_dependencies(rlcpp tq_distbn_interface)

install(TARGETS
  tq_distbn_pubsub_node
  tq_distbn_pubsub_node_std_msg
  tq_distbn_input_provider_publisher
  DESTINATION lib/${PROJECT_NAME})

target_link_libraries(tq_distbn_pubsub_node
  tq_distbn_srv
  composition_nodes)

target_link_libraries(tq_distbn_pubsub_node_std_msg
  tq_distbn_srv
  composition_nodes_std_msg)

ament_package()
