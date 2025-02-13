# cmake_minimum_required(VERSION 3.5)
# project(dingo_control)

# find_package(ament_cmake REQUIRED)
# find_package(ament_cmake_python REQUIRED)
# find_package(rclpy REQUIRED)
# find_package(std_msgs REQUIRED)
# find_package(geometry_msgs REQUIRED)
# find_package(rosidl_default_generators REQUIRED)



# rosidl_generate_interfaces(${PROJECT_NAME}
#   "msg/TaskSpace.msg"
#   "msg/JointSpace.msg"
#   "msg/Angle.msg"
#   DEPENDENCIES std_msgs geometry_msgs
# )

# # Install Python modules
# ament_python_install_package(${PROJECT_NAME} PACKAGE_DIR src)

# # Specify additional locations of header files
# #include_directories(${ament_INCLUDE_DIRS})
# #ament_export_dependencies(rosidl_default_runtime)

# # Install the package
# ament_package()

cmake_minimum_required(VERSION 3.8)
project(dingo_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

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

find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Angle.msg"
  "msg/JointSpace.msg"
  "msg/TaskSpace.msg"
  DEPENDENCIES geometry_msgs std_msgs # Add packages that above messages depend on, in this case geometry_msgs for Sphere.msg
)
#ament_python_install_package(${PROJECT_NAME} src PACKAGE_DIR)
ament_package()