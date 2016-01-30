cmake_minimum_required(VERSION 3.3)
project(Game_Application)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#include_directories("../model/include/" )

set(SOURCES src/main.cpp)

add_executable(Game_Application ${SOURCES})
target_link_libraries(Game_Application LINK_PUBLIC Game_Model)