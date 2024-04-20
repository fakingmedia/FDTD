cmake_minimum_required(VERSION 3.27)
project(FDTD)

set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE( OPENMP REQUIRED)
if(OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif ()

add_executable(FDTD src/main.cpp
        src/Grid.cpp
        src/Grid.h
        src/update.cpp
        src/macro.h
        src/abc.cpp
        src/alloc.h
        src/snapshot.cpp
        src/iterator.cpp
        src/ezinc.h
)
