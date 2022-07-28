cmake_minimum_required(VERSION 3.22)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

add_executable(LeetCode main.cpp binary_tree/tree_node.h list_node.h test_interface.h test_interface.cpp binary_tree/binary_tree.h binary_tree/binary_tree.cpp)
