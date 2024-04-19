cmake_minimum_required(VERSION 3.27)
project(FDTD)

set(CMAKE_CXX_STANDARD 17)

add_executable(FDTD src/main.cpp
        src/Grid.cpp
        src/Grid.h
        src/update.cpp
        src/macro.h
        src/ABC.cpp
        src/alloc.h
        src/ABC.h
        src/snapshot.cpp
)
