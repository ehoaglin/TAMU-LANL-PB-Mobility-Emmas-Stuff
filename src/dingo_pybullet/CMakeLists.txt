cmake_minimum_required(VERSION 3.8)
project(dingo_pybullet)


# Set up Python package dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(dingo_control_msg REQUIRED)



# Specify additional locations of header files
include_directories(${ament_INCLUDE_DIRS})

# install(PROGRAMS
#   launch/launch_simulation.py
#   DESTINATION lib/${PROJECT_NAME}
# )

# Install executable scripts
install(PROGRAMS
  scripts/launch_robot.py
  scripts/pybullet_simulation.py
  DESTINATION lib/${PROJECT_NAME}
)
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)
# Set up PyBullet dependency
ament_python_install_package(${PROJECT_NAME})

ament_package()