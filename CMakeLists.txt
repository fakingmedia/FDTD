cmake_minimum_required(VERSION 3.27)
project(FDTD)

set(CMAKE_CXX_STANDARD 17)

add_executable(FDTD main.cpp
        oneDimensionFdtd.cpp
        oneDimensionFdtd.h
        Grid.cpp
        Grid.h
        update.cpp
        macro.h
        abc.cpp
        alloc.h
)
