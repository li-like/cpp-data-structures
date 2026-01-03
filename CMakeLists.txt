cmake_minimum_required(VERSION 4.1)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(notes/C++全套数据结构算法代码/22_布隆过滤器)
include_directories(notes/C++全套数据结构算法代码/25_一致性哈希算法)

add_executable(CPP
        codes/vector.cpp)
