cmake_minimum_required(VERSION 3.20)

project(dsa_demos C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(01_linkedlist)
add_subdirectory(02_stack_queue)
add_subdirectory(03_tree)
add_subdirectory(04_sort_search)
add_subdirectory(05_graph)
