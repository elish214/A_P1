cmake_minimum_required(VERSION 3.6)
project(A_P1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Point.cpp)

add_executable(A_P1 ${SOURCE_FILES})