cmake_minimum_required(VERSION 3.3)

project(Game_Infrastructure)

set(HEADER_FILES include/ICamera.h include/Camera2D.h)
set(SOURCES src/Camera2D.cpp)

add_library(Game_Infrastructure ${SOURCES} ${HEADER_FILES})

target_include_directories (Game_Infrastructure PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)