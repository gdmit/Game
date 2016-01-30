cmake_minimum_required(VERSION 3.3)

project(Game_ViewModel)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pthread")

set(HEADER_FILES
        include/IGameProcess.h
        include/ViewModel.h)
set(SOURCES
        src/ViewModel.cpp)
set(TEST_FILES
        test/viewmodelTest.cpp)

add_library(Game_ViewModel ${SOURCES} ${HEADER_FILES})

target_include_directories (Game_ViewModel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

add_executable(runViewModelTests ${TEST_FILES})

target_link_libraries(runViewModelTests gtest gtest_main)