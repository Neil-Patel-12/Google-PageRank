cmake_minimum_required(VERSION 3.27)
project(PageRank)

set(CMAKE_CXX_STANDARD 14)

add_executable(PageRank main.cpp
        GreaphAPI.h)
