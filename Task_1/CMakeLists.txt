cmake_minimum_required(VERSION 3.27)
project(Task_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task_1 main.cpp
        function.h
        input.cpp
        output.cpp
        dobavlenie.cpp
        find.cpp
        delete_change.cpp
        sort.cpp
        file_operations.cpp)