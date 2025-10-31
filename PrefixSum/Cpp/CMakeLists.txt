cmake_minimum_required(VERSION 3.28)
project(prefix_sum)

set(CMAKE_CXX_STANDARD 26)

add_library(prefix_sum src/prefix_sum.cpp)
target_compile_options(prefix_sum PUBLIC -Wall -Wextra -O2)
