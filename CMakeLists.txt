cmake_minimum_required(VERSION 3.15)
project(design_patterns_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(design_patterns_cpp main.cpp)
add_executable(singleton singleton.cpp)
add_executable(factory_method factory_method.cpp)