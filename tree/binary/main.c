//
// Created by regoeco on 22/12/16.
//

#include "binary_tree.h"

int main(){
    binary_tree b;
    b.insert(&b, (void*)6, NULL, NULL);
    b.get(&b).preorder(NULL);
}