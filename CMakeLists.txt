cmake_minimum_required(VERSION 3.3)

project(Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pthread")

add_subdirectory(application)
add_subdirectory(model)
add_subdirectory(infrastructure)
add_subdirectory(view)
add_subdirectory(viewmodel)
