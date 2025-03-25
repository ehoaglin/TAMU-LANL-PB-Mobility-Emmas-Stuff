cmake_minimum_required(VERSION 3.8)
project(dingo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)

# Manually add the path to the dingo_hardware_interfacing package
#set(dingo_hardware_interfacing_DIR /home/ehoaglin/ros2_ws/install/dingo_hardware_interfacing/share/dingo_hardware_interfacing/cmake)
#find_package(dingo_hardware_interfacing REQUIRED)

find_package(dingo_control REQUIRED)
find_package(dingo_input_interfacing REQUIRED)
find_package(dingo_servo_interfacing REQUIRED)
find_package(dingo_peripheral_interfacing REQUIRED)
find_package(dingo_peripheral_interfacing_msg REQUIRED)
find_package(dingo_control_msg REQUIRED)

# Install Python modules
ament_python_install_package(${PROJECT_NAME})


# Specify additional locations of header files
include_directories(${ament_INCLUDE_DIRS})

# Install executable scripts
install(PROGRAMS
  scripts/dingo_driver.py
  scripts/run_robot.py
  DESTINATION lib/${PROJECT_NAME}
)
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

# Install the package
ament_package()

