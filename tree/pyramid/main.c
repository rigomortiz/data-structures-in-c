//
// Created by regoeco on 15/01/17.
//

#include <stdio.h>
#include "tree-pyramid.h"
void callback_print(const void* data){
    printf("%d --> ", *(int*)data);
}
void callback_insert(const void* data){
    printf("Insert:%d\n", *(int*)data);
}
int main(){
    PyramidTree pyramidTree = newPyramidTree();

    int i;
    for(i=0; i< 50; i++){
        pyramidTree.insert(&pyramidTree, &i, NULL);
    }
    printf("\ndepth left des:\n");
    pyramidTree.print(&pyramidTree).depth(callback_print).left().des();
    printf("\ndepth right des:\n");

    pyramidTree.print(&pyramidTree).depth(callback_print).right().des();

//    destroyPyramidTree(&pyramidTree);
    return 0;
}