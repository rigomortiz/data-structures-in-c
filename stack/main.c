/* 
 * File:   main.c
 * Author: regoeco
 *
 * Created on 2016/12/18
 */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int, char**);
void callback_push(DATA);
void callback_pop(DATA);
void callback_print(DATA d);

typedef struct {
    int number;
} struct_number;

int main(int argc, char** argv)
{
    struct_number n[10];
    int i = 0;
    stack stack_numeros, *self = &stack_numeros;
    init_stack(self);
    for(i=0; i<10; i++){
        n[i].number = i*i;
        stack_numeros.push(self, &n[i], callback_push);
    }

    struct_number *s_tmp = (struct_number *)stack_numeros.peek(self);

    printf("Peek:%d\n", s_tmp->number);
    printf("Size:%0.0Lf\n", stack_numeros.size);

    stack_numeros.print(self, callback_print);

    destroy_stack(self);
    printf("Size:%0.0Lf\n", stack_numeros.size);
    return (EXIT_SUCCESS);
}


void callback_push(DATA new_data) {
    struct_number *s = new_data;
    printf("Data to insert: %d.\n", s->number);
}

void callback_pop(DATA delete_data)
{
    struct_number *s = delete_data;
    printf("Data to delete:  %d.\n", s->number);
}

void callback_print(DATA d)
{
	struct_number *s = d;
    printf("(%d) --> ",s->number);
}