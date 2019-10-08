cmake_minimum_required(VERSION 2.8.3)
project(velodyne_description)

find_package(catkin REQUIRED
             rospy
             octomap_server
             tf
             geometry_msgs
             nav_msgs
             )

catkin_python_setup()

catkin_package(CATKIN_DEPENDS
rospy 
geometry_msgs
nav_msgs
octomap_server
tf
)

install(DIRECTORY launch meshes rviz urdf world
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

#add_executable(control_turtle src/control_turtle.cpp)

catkin_install_python(PROGRAMS bin/point_op
DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

#install(DIRECTORY launch 
#	DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
#)

