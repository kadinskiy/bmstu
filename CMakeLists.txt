cmake_minimum_required(VERSION 4.0)
project(kadinsky)

set(CMAKE_CXX_STANDARD 26)

add_executable(kadinsky trash/lab_01/main.cpp
        test.cpp
        lab02/task_01.cpp
        lab02/task_02.cpp)
