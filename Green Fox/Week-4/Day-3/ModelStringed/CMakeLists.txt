cmake_minimum_required(VERSION 3.13)
project(ModelStringed)

set(CMAKE_CXX_STANDARD 14)

add_executable(ModelStringed main.cpp instrument.cpp stringedInstrument.cpp ElectricGuitar.cpp BassGuitar.cpp Violin.cpp)