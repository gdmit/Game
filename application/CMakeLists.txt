cmake_minimum_required(VERSION 3.3)
project(Game_Application)

#include_directories("../model/include/" )

set(SOURCES src/main.cpp)

add_executable(Game_Application ${SOURCES})
target_link_libraries(Game_Application LINK_PUBLIC Game_Model Game_View Game_ViewModel ${LIBRARY_DEPS})