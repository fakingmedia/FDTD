cmake_minimum_required(VERSION 3.27)
project(FDTD)

set(CMAKE_CXX_STANDARD 17)

add_executable(FDTD main.cpp
        serialFdtd.cpp
        serialFdtd.h
        parallelFdtd.cpp
        parallelFdtd.h)
