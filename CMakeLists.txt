cmake_minimum_required(VERSION 3.31)
project(cars)

set(CMAKE_CXX_STANDARD 20)

add_executable(cars main.cpp
        cars.cpp
        cars.h
        payingoptions.cpp
        payingoptions.h)
