cmake_minimum_required(VERSION 3.17)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(../../include)
LINK_DIRECTORIES(../../include)
find_library(ALGLIB libAlgorithms ../../include/build)
add_executable(lab4 main.cpp)
target_link_libraries(lab4 ${ALGLIB})