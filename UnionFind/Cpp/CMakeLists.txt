cmake_minimum_required(VERSION 3.28)
project(union_find_cpp)

set(CMAKE_CXX_STANDARD 23)

add_library(union_find src/union_find.cpp)
target_compile_options(union_find PUBLIC -Wall -Wextra -O2)
