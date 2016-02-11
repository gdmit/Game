cmake_minimum_required(VERSION 3.3)

project(Game_ViewModel)

set(HEADER_FILES
        include/IGameProcess.h
        include/ViewModel.h include/Texture2D.h)
set(SOURCES
        src/ViewModel.cpp src/Texture2D.cpp)
set(TEST_FILES
        test/viewmodelTest.cpp)

add_library(Game_ViewModel ${SOURCES} ${HEADER_FILES})

target_include_directories (Game_ViewModel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

add_executable(runViewModelTests ${TEST_FILES})

target_link_libraries(runViewModelTests gtest gtest_main Game_ViewModel Game_Model)