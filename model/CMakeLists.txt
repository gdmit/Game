cmake_minimum_required(VERSION 3.3)

project(Game_Model)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(HEADER_FILES
        include/Map.h
        include/IMap.h
        include/Cell.h
        include/Individual.h
        include/IPopulation.h
        include/Population.h
        include/Vector2D.h)

set(SOURCES
        src/Map.cpp
        src/Cell.cpp
        src/Individual.cpp
        src/Population.cpp)

set(TEST_FILES
        test/modelTest.cpp
        test/mapTest.cpp
        test/individualTest.cpp
        test/populationTest.cpp)

add_library(Game_Model ${SOURCES} ${HEADER_FILES})

target_include_directories (Game_Model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

add_executable(runModelTests ${TEST_FILES})

target_link_libraries(runModelTests gtest gtest_main Game_Model)