cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
cmake_policy(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(${CMAKE_TOOLCHAIN_FILE})

project(UniGen  VERSION 0.1.0)

add_subdirectory(Sustain)
add_subdirectory(WorldGen)
