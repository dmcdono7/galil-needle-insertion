cmake_minimum_required(VERSION 3.8)
project(mp_needle_trajectory_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(controller_interface REQUIRED)
find_package(hardware_interface REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(NLopt REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3)


include_directories( include local/include)

add_library(mp_needle_trajectory_controller SHARED src/mp_needle_traj.cpp src/mpc_helpers.cpp)
target_link_libraries(mp_needle_trajectory_controller NLopt::nlopt)
ament_target_dependencies(mp_needle_trajectory_controller rclcpp pluginlib geometry_msgs tf2_geometry_msgs controller_interface hardware_interface Eigen3)


pluginlib_export_plugin_description_file(controller_interface mp_needle_trajectory_controller_plugin.xml)

install( TARGETS mp_needle_trajectory_controller LIBRARY DESTINATION lib )

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

ament_package()
