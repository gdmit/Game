cmake_minimum_required(VERSION 3.3)

project(Game)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)
find_package(OpenCV REQUIRED)
set(LIBRARY_DEPS ${OpenCV_LIBS})

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include" ${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pthread")

add_subdirectory(application)
add_subdirectory(model)
add_subdirectory(infrastructure)
add_subdirectory(view)
add_subdirectory(viewmodel)
