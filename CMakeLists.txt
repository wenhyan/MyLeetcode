cmake_minimum_required(VERSION 3.22)
project(MyLeetcode)

set(CMAKE_CXX_STANDARD 11)

add_executable(LeetCode main.cpp binary_tree/tree_node.h single_list/list_node.h third_lib/test_interface.h binary_tree/binary_tree.h binary_tree/binary_tree.cpp)
