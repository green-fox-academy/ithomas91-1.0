cmake_minimum_required(VERSION 3.13)
project(fleetOfThinks)

set(CMAKE_CXX_STANDARD 14)

add_executable(fleetOfThinks main.cpp fleet.h fleet.cpp thing.cpp thing.h)