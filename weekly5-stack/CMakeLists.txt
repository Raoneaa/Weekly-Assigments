cmake_minimum_required(VERSION 3.28)
project(weekly5_stack C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(weekly5_stack
        main.c
        stack.c
        stack.h)
