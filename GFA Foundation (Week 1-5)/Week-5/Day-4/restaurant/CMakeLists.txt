cmake_minimum_required(VERSION 3.13)
project(restaurant)

set(CMAKE_CXX_STANDARD 14)

add_executable(restaurant main.cpp restaurant.cpp restaurant.h employee.cpp employee.h waiter.cpp waiter.h chef.cpp chef.h manager.cpp manager.h)