//
// Created by regoeco on 29/12/16.
//
#include "list.h"
//INTERFACE OF CALLBACKS
void callback_insert(const void*);
void callback_delete(const void*);
void callback_print(const void* d);

//void* STRUCTURE OF QUEUE
typedef struct {
    int number;
} struct_number;
void gh(int *c);
//MAIN
int main(int argc, char** argv)
{
/*
    //DATA TO INSERT
    struct_number n[10];
    int i = 0;

    //INSTANCE= newList(LINEAL || DOUBLE, SIMPLE || CIRCULAR);
    List list = newList(LINEAL, SIMPLE);

    for(i = 0; i <10; i++) {
        n[i].number = i * i;
        list.insert(&list).top(&n[i], NULL);
    }
    //list.insert(&list).pos(0, &n[9], NULL);
    //printf("\nSize:%ld", list.get_size(&list));


    //list.insert.top(data, callback)

    //list.insert.bottom(data, callback)
    //list.insert.pos(int, data, callback)

    list.print(&list, callback_print);
    //list.delete(&list).pos(5, NULL);
    //list.insert(&list).pos(5, &n[0], NULL);
    list.replace(&list, &n[0], 5, NULL, NULL);
    //list.delete(&list).top(NULL);
    //list.delete(&list).bottom(NULL);
    printf("\n");
    struct_number** d = (struct_number**)list.get(&list).all();
    unsigned int size = list.get_size(&list);
    //int i;
    for(i = 0; i<size; i++){
        printf("%d --> ", *d[i]);
    }

    //list.print(&list, callback_print);
    destroyList(&list);
*/
    int* i = calloc(3 , sizeof(int*));
    gh(i);

    printf("%d\n", i[0]);
    printf("%d\n", *(i+1));
    printf("%d\n", i[2]);
    free(i);

    return (EXIT_SUCCESS);
}


void callback_insert(const void* new_data) {
    struct_number *s = new_data;
    printf("Data to insert: %d.\n", s->number);
}

void callback_delete(const void* delete_data) {
    struct_number *s = delete_data;
    printf("Data to delete:  %d.\n", s->number);
}

void callback_print(const void* d) {
    struct_number *s = d;
    printf("(%d) --> ",s->number);
}

void gh(int *h){
    int i = 0;
    int a = 10, b = 20, c= 30;

    h[0] = a;
    h[1] = b;
    h[2] = c;

}