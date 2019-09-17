cmake_minimum_required(VERSION 3.7)
project(RogueLite)

find_package(SDL2 REQUIRED)
find_package(Threads REQUIRED)
add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall -g")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

aux_source_directory(src/engine ENGINE)

add_executable(RogueLite ${ENGINE} src/main.cpp)
include_directories(engine)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(RogueLite ${SDL2_LIBRARIES})
target_link_libraries(RogueLite ${CMAKE_THREAD_LIBS_INIT})
