cmake_minimum_required(VERSION 3.10)
project(nucleo)

set(CMAKE_CXX_STANDARD 11)
find_package(Boost COMPONENTS REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(nucleo main.cpp)