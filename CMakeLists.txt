# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

CMAKE_MINIMUM_REQUIRED(VERSION 3.22)
project(opencv_playground)

set(CMAKE_CXX_STANDARD 20)

FIND_PACKAGE(OpenCV 4 REQUIRED)
MESSAGE("OpenCV version: ${OpenCV_VERSION}")
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

SET(SRC main.cpp main.h)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})


# Add tasks subprojects
#include(main main.cpp main.h)
#add_subprojects(${CMAKE_SOURCE_DIR})
