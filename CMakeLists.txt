cmake_minimum_required(VERSION 3.19)
project(gifted2021 C)

set(CMAKE_C_STANDARD 11)

include_directories(lib)
include_directories(src)

add_executable(gifted2021
        lib/hash.h
        src/main.c)
