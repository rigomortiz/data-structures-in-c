cmake_minimum_required(VERSION 3.6)
project(data_structures)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES
#STACK
stack/stack.h stack/stack.c
#QUEUE
queue/queue.h queue/queue.c
#TREE BINARY
tree/binary/binary_tree.h tree/binary/binary_tree.c
#LIST
lists/list.h lists/list.c
#GRAPH
graph/graph.h graph/graph.c
#TREE PYRAMID
tree/pyramid/tree-pyramid.c tree/pyramid/tree-pyramid.h
#SIZE
size/size.h
#CUBE
cube/data_structure/ADT/cube.c cube/data_structure/ADT/cube.h cube/data_structure/query/query.c cube/data_structure/query/query.h
cube/main.c cube/cube_summation.c cube/cube_summation.h)
#set(SOURCE_FILES test/main.c)
add_executable(data_structures ${SOURCE_FILES})