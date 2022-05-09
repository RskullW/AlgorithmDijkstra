cmake_minimum_required(VERSION 3.22)
project(SIOD)

set(CMAKE_CXX_STANDARD 17)

add_executable(SIOD main.cpp MatrixGraphs.cpp MatrixGraphs.h Container.h Graph.h ListGraphs.cpp ListGraphs.h)
