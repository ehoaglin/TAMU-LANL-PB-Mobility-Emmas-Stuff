cmake_minimum_required(VERSION 3.8)
project(dingo_servo_interfacing)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
# Install the package


# Install package.xml


## Specify additional locations of header files
## Your package locations should be listed before other locations
ament_python_install_package(${PROJECT_NAME})

ament_package()
## System dependencies are found with CMake's conventions
