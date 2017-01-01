//
// Created by regoeco on 22/12/16.
//

#include "binary_tree.h"
int order_callback(const void* new, const void* inserted);
void print_callback(const void* d);
int search_callback(const void* data_search, const void* data_inserted);
int remove_callback(const void* data_remove, const void* data_inserted);
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
    printf("Inorder DES:");
    b.print(&b).inorder(print_callback).des();
    printf("\nInorder ASC:");
    b.print(&b).inorder(print_callback).asc();
    printf("\nPreorder left:");
    b.print(&b).preorder(print_callback).left();
    printf("\nPreorder right:");
    b.print(&b).preorder(print_callback).right();
    printf("\nPostorder left:");
    b.print(&b).postorder(print_callback).left();
    printf("\nPostorder right:");
    b.print(&b).postorder(print_callback).right();

    data_struct d_new, d2_new ;
    d_new.num = 567, d2_new.num = 2;
    b.insert_multiple(&b, NULL, order_callback, 2, &d_new, &d2_new);

    printf("\nSize:%ld\n", b.number_elements);
    data_struct** data_struct1 = (data_struct**)b.get(&b).inorder().asc();
    int i = 0;
    for(i=0; i<b.number_elements; i++){
        printf("%d-", data_struct1[i]->num);
    }

    printf("\nDepth:%ld", b.depth);

    data_struct s;
    s.num = 2;
    printf("\nFind 2: %s",   b.find(&b, &s, search_callback).get() !=NULL? "yes":"no" );
    s.num = 31;
    printf("\nFind 31: %s", b.find(&b, &s, search_callback).get() !=NULL? "yes":"no" );

    //REMOVE
    s.num = 1;
    printf("\nRemove 1: %s", b.find(&b, &s, remove_callback).remove()==1?"yes":"no");
    printf("\nInorder ASC:");
    b.print(&b).inorder(print_callback).asc();



    destroyBinaryTree(&b);
    free(data_struct1);
    printf("\nSize:%ld", b.number_elements);

    return 1;
}

int order_callback(const void* new, const void* inserted){
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

int search_callback(const void* data_search, const void* data_inserted){
    const data_struct *n = (data_struct*) data_search;
    const data_struct *i = (data_struct*) data_inserted;
    if(n->num > i->num){
        return  1;
    }else if(n->num < i->num){
        return -1;
    }else if(n->num == i->num){
        return 0;
    }
}

int remove_callback(const void* data_remove, const void* data_inserted){
    const data_struct *n = (data_struct*) data_remove;
    const data_struct *i = (data_struct*) data_inserted;
    if(n->num > i->num){
        return  1;
    }else if(n->num < i->num){
        return -1;
    }else if(n->num == i->num){
        return 0;
    }
}

void print_callback(const void* d){
    const data_struct *data = (data_struct*) d;
    printf(" %d ", data->num);
}