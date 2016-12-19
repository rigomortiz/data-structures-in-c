cmake_minimum_required(VERSION 3.6)
project(data_structures)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES stack/main.c  stack/stack.h stack/stack.c)
add_executable(data_structures ${SOURCE_FILES})