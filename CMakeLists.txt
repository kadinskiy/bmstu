cmake_minimum_required(VERSION 4.0)
project(kadinsky)

set(CMAKE_CXX_STANDARD 26)

add_executable(kadinsky trash/lab_01/main.cpp
        labs/lab_02/task_01.cpp
        labs/lab_02/task_02.cpp
        labs/lab_02/task_03.cpp
        labs/lab_02/02/task_02_01.cpp
        labs/lab_02/02/task_02_02.cpp
        labs/lab_02/02/task_02_03.cpp
        labs/lab_02/02/task_02_04.cpp
        labs/lab_02/02/task_02_05.cpp
        main.cpp
        labs/lab_03/task_01.cpp
        labs/lab_03/task_02.cpp
        labs/lab_03/task_03.cpp
        labs/lab_04/main.cpp
        labs/lab_04/task_02_01.cpp
        labs/lab_04/task_06.cpp
        labs/lab_04/task_07.cpp
        labs/lab_04/task_04.cpp
        labs/lab_04/task_03.cpp
        labs/lab_04/task_05.cpp
        labs/lab_04/task_01.cpp
        DZ/dz_01/task_01.cpp
        DZ/dz_01/task_02.cpp
        UTP_ver_02.cpp
        UTP_ver_03.cpp
)