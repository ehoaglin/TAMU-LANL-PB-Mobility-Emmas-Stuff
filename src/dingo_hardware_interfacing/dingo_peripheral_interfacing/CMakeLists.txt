# cmake_minimum_required(VERSION 3.8)
# project(dingo_peripheral_interfacing)

# ## Compile as C++11, supported in ROS Kinetic and newer
# # add_compile_options(-std=c++11)

# ## Find catkin macros and libraries
# ## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
# ## is used, also find other catkin packages
# # find_package(catkin REQUIRED COMPONENTS
# #   rospy message_generation std_msgs
# # )

# ## System dependencies are found with CMake's conventions
# # find_package(Boost REQUIRED COMPONENTS system)


# ## Uncomment this if the package has a setup.py. This macro ensures
# ## modules and global scripts declared therein get installed
# ## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html

# find_package(ament_cmake REQUIRED)
# find_package(rclpy REQUIRED)
# # Install the package


# # Install package.xml


# ## Specify additional locations of header files
# ## Your package locations should be listed before other locations
# include_directories(${ament_INCLUDE_DIRS})

# ament_package()

################################################
## Declare ROS messages, services and actions ##
################################################

cmake_minimum_required(VERSION 3.8)
project(dingo_peripheral_interfacing)

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
  "msg/ElectricalMeasurements.msg"
  DEPENDENCIES geometry_msgs std_msgs # Add packages that above messages depend on, in this case geometry_msgs for Sphere.msg
)
#ament_python_install_package(${PROJECT_NAME} PACKAGE_DIR src)
ament_package()
