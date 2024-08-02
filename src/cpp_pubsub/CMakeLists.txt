cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()
add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)
add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)
add_executable(sender src/sender_node.cpp)
ament_target_dependencies(sender rclcpp std_msgs)
add_executable(draw_circle src/draw_circle.cpp)
ament_target_dependencies(draw_circle rclcpp geometry_msgs)
add_executable(pose_subscriber src/pose_sub.cpp)
ament_target_dependencies(pose_subscriber rclcpp turtlesim)
add_executable(turtle_controller src/turtle_controller.cpp)
ament_target_dependencies(turtle_controller rclcpp turtlesim geometry_msgs)
add_executable(cpp_param src/cpp_param.cpp)
ament_target_dependencies(cpp_param  rclcpp)
install(TARGETS
  talker
  listener
  turtle_controller
  sender
  pose_subscriber
  cpp_param
  draw_circle
  DESTINATION lib/${PROJECT_NAME})

ament_package()
