cmake_minimum_required(VERSION 3.6)
project(data_structures)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES  queue/queue.c queue/queue.h stack/stack.h stack/stack.c tree/binary/binary_tree.h tree/binary/binary_tree.c tree/binary/main.c)
#set(SOURCE_FILES test/main.c)
add_executable(data_structures ${SOURCE_FILES})