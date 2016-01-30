cmake_minimum_required(VERSION 3.3)

project(Game_View)

set(HEADER_FILES
        include/IViewModel.h
        include/View.h)
set(SOURCES
        src/View.cpp)

add_library(Game_View ${SOURCES} ${HEADER_FILES})

target_include_directories (Game_View PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)