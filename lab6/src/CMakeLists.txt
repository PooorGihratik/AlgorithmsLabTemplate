cmake_minimum_required(VERSION 3.16)
project(lab6)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(../../include)
LINK_DIRECTORIES(../../include)
find_library(ALGLIB libAlgorithms ../../include/build)
add_executable(lab6 main.cpp)
target_link_libraries(lab6 ${ALGLIB})