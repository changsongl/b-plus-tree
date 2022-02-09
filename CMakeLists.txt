cmake_minimum_required(VERSION 3.21)
project(b_plus_tree C)

set(CMAKE_C_STANDARD 99)

add_executable(b_plus_tree btree.c file.h file.c btree.h)

