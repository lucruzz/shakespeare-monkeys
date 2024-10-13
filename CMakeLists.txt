cmake_minimum_required(VERSION 3.28)
project(shakespeare-monkeys)

set(CMAKE_CXX_STANDARD 17)

add_executable(shakespeare-monkeys main.cpp
        Monkey.h
        Monkey.cpp
)
