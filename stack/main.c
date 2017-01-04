/* 
 * File:   main.c
 * Author: regoeco
 *
 * Created on 2016/12/18
 */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//INTERFACE OF CALLBACKS
void callback_push(const void*);
void callback_pop(const void*);
void callback_print(const void* d);

//void* STRUCTURE OF QUEUE
typedef struct {
    int number;
} struct_number;

//MAIN
int main(int argc, char** argv)
{
    //DATA TO INSERT
    struct_number n[10];
    int i = 0;

    //INSTANCE
    Stack stack = newStack();

    //PUSH DATA
    for(i=0; i<10; i++){
        n[i].number = i*i;
        stack.push(&stack, &n[i], callback_push);
    }

    //PEEK DATA
    struct_number *s_tmp = (struct_number *)stack.peek(&stack);
    printf("Peek:%d\n", s_tmp->number);

    //SIZE STACK
    printf("Size:%d\n", stack.get_size(&stack));

    //PRINT STACK
    stack.print(&stack, callback_print);

    //DESTROY STACK
    destroyStack(&stack);
    printf("Size:%d\n", stack.get_size(&stack));
    return (EXIT_SUCCESS);
}


void callback_push(const void* new_data) {
    struct_number *s = new_data;
    printf("Data to insert: %d.\n", s->number);
}

void callback_pop(const void* delete_data)
{
    struct_number *s = delete_data;
    printf("Data to delete:  %d.\n", s->number);
}

void callback_print(const void* d)
{
    struct_number *s = d;
    printf("(%d) --> ",s->number);
}