cmake_minimum_required(VERSION 3.13)
project(shelter)

set(CMAKE_CXX_STANDARD 14)

add_executable(shelter main.cpp animal.cpp animal.h cat.cpp cat.h)