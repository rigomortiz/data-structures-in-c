//
// Created by regoeco on 22/12/16.
//

#include "binary_tree.h"
const int order_callback(const void* new, const void* inserted);
const void print_callback(const void* d);
typedef struct {
    int num;
}data_struct;

int main(){
    BinaryTree b = newBinaryTree();
    data_struct d[10];
    d[0].num = 134;
    d[1].num = 87;
    d[2].num = 1;
    d[3].num = 23;
    d[4].num = 45;
    d[5].num = 89;
    d[6].num = 145;
    d[7].num = 90;
    d[8].num = 12;
    d[9].num = 27;


    b.insert_multiple(&b, NULL, order_callback, 10,&d[0], &d[1], &d[2], &d[3], &d[4], &d[5], &d[6], &d[7], &d[8], &d[9]);
    printf("Inorder:");
    b.print(&b).inorder(print_callback);
    printf("\nPostorder:");
    b.print(&b).postorder(print_callback);
    printf("\nPreorder:");
    b.print(&b).preorder(print_callback);

    return 1;
}

const int order_callback(const void* new, const void* inserted){
    const data_struct *n = (data_struct*) new;
    const data_struct *i = (data_struct*) inserted;
    if(n->num > i->num){
        return  1;
    }else if(n->num < i->num){
        return -1;
    }else if(n->num == i->num){
        return 0;
    }
}

const void print_callback(const void* d){
    const data_struct *data = (data_struct*) d;
    printf(" %d ", data->num);
}