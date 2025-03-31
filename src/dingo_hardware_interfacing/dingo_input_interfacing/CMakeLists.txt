cmake_minimum_required(VERSION 3.8)
project(dingo_input_interfacing)

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)

# Install Python packages
ament_python_install_package(${PROJECT_NAME})
# Install launch files (if you have any launch files)

# install(PROGRAMS
#   dingo_input_interfacing/InputInterface.py
#   DESTINATION lib/${PROJECT_NAME}
# )
# Explicitly install the package.xml file
# install(
#   FILES package.xml
#   DESTINATION share/${PROJECT_NAME}
# )

ament_package()
