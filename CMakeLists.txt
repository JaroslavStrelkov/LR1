cmake_minimum_required(VERSION 3.28.3)
project(sanitize)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak -g")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -g")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsantize=undefined -g")
add_executable (LR1 Task_3.cpp)