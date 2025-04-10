cmake_minimum_required(VERSION 3.8)
project(dingo_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)

  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(dingo_control_msg REQUIRED)

find_package(dingo_servo_interfacing REQUIRED)
find_package(dingo_peripheral_interfacing REQUIRED)
find_package(dingo_peripheral_interfacing_msg REQUIRED)
find_package(dingo_hardware_config REQUIRED)


ament_python_install_package(${PROJECT_NAME})

ament_package()