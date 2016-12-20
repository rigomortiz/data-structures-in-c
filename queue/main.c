#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main(int, char**);
void callback_enqueue(DATA);
void callback_dequeue(DATA);
void callback_print(DATA d);

typedef struct {
    int number;
} struct_number;

int main(int argc, char** argv)
{
    struct_number n[10];
    int i = 0;
    queue queue_numeros, *self = &queue_numeros;
    init_queue(self);
    for(i=0; i<10; i++){
        n[i].number = i*i;
        queue_numeros.enqueue(self, &n[i], callback_enqueue);
    }

    struct_number *s_tmp = (struct_number *)queue_numeros.peek(self);

    printf("Peek:%d\n", s_tmp->number);
    printf("Size:%0.0Lf\n", queue_numeros.size);

    queue_numeros.print(self, callback_print);

    destroy_queue(self);
    printf("Size:%0.0Lf\n", queue_numeros.size);
    return (EXIT_SUCCESS);
}

void callback_enqueue(DATA new_data) {
    struct_number *s = new_data;
    printf("Data to insert: %d.\n", s->number);
}

void callback_dequeue(DATA delete_data)
{
    struct_number *s = delete_data;
    printf("Data to delete:  %d.\n", s->number);
}

void callback_print(DATA d)
{
    struct_number *s = d;
    printf("(%d) --> ",s->number);
}