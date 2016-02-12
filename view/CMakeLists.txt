cmake_minimum_required(VERSION 3.3)

project(Game_View)

set(HEADER_FILES
        include/IViewModel.h
        include/ViewOCV.h)
set(SOURCES
        src/ViewOCV.cpp)

add_library(Game_View ${SOURCES} ${HEADER_FILES})

target_link_libraries(Game_View ${LIBRARY_DEPS} ${OpenCV_LIBRARIES})

target_include_directories (Game_View PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})