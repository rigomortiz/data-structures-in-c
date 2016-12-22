cmake_minimum_required(VERSION 3.6)
project(data_structures)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES tree/binary/binary_tree.c tree/binary/binary_tree.h test/main.c tree/binary/main.c)
add_executable(data_structures ${SOURCE_FILES})