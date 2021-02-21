cmake_minimum_required(VERSION 3.17)
project(Lab4)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(../include)
LINK_DIRECTORIES(../include)
add_executable(Lab4 main.cpp)