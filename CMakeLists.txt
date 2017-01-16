cmake_minimum_required(VERSION 3.6)
project(data_structures)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES stack/stack.h stack/stack.c  queue/queue.h queue/queue.c tree/binary/binary_tree.h tree/binary/binary_tree.c lists/list.h lists/list.c  graph/graph.h graph/graph.c  tree/pyramid/main.c tree/pyramid/tree-pyramid.c tree/pyramid/tree-pyramid.h size/size.h)
#set(SOURCE_FILES test/main.c)
add_executable(data_structures ${SOURCE_FILES})