cmake_minimum_required(VERSION 3.13)
project(airCraft)

set(CMAKE_CXX_STANDARD 14)

add_executable(airCraft main.cpp aircraft.cpp f16.cpp f35.cpp f35.h carrier.cpp carrier.h)