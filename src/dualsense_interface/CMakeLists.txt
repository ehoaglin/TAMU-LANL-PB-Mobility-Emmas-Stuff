cmake_minimum_required(VERSION 3.8)
project(dualsense_interface)

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)

# Install Python packages
ament_python_install_package()

# Install launch files (if you have any launch files)


# Install the Python script (if applicable)
install(PROGRAMS
  dualsense_interface/hidraw_to_joy.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()