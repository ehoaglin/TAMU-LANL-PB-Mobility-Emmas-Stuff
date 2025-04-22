cmake_minimum_required(VERSION 3.8)
project(dingo_description)

find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)

# Install URDF files
install(DIRECTORY dingo_description_new/dingo_description/urdf/
  DESTINATION share/${PROJECT_NAME}/urdf
)

# Install meshes
install(DIRECTORY dingo_description_new/dingo_description/meshes/
  DESTINATION share/${PROJECT_NAME}/meshes
)

# Install launch files
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

ament_package()
