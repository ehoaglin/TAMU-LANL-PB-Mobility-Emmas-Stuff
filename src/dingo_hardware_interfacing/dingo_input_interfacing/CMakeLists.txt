cmake_minimum_required(VERSION 3.8)
project(dingo_input_interfacing)


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)
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
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages

find_package(rclpy REQUIRED)
#############################################################################################################################################################
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

find_package(dingo_control REQUIRED)

  

## Specify additional locations of header files
## Your package locations should be listed before other locations
ament_python_install_package(${PROJECT_NAME})

# install(PROGRAMS
#   scripts/Keyboard.py
#   DESTINATION lib/python3.12/site-packages/${PROJECT_NAME}
# )



ament_package()
