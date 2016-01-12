cmake_minimum_required(VERSION 2.8)

project(webcam)
#set(CMAKE_CXX_COMPILER "/usr/bin/gcc-4.7")

#This line is necessary to link asio
find_package(Boost 1.40.0 REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIR})
include_directories(./include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -lstdc++")

add_subdirectory(src)
add_subdirectory(app)

