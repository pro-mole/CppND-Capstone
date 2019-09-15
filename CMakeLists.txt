cmake_minimum_required(VERSION 3.7)
project(Rogue)

find_package(SDL2 REQUIRED)
add_definitions(-std=c++17)

aux_source_directory(src/engine ENGINE)

add_executable(Rogue ${ENGINE} src/main.cpp)
include_directories(engine)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(Rogue ${SDL2_LIBRARIES})

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")