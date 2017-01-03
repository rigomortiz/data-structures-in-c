#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main(int, char**);

//INTERFACE OF CALLBACKS
const void callback_enqueue(const void*);
const void callback_dequeue(const void*);
const void callback_print(const void* d);

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
    Queue queue = newQueue();

    //ENQUEUE DATA
    for(i=0; i<10; i++){
        n[i].number = i*i;
        queue.enqueue(&queue, &n[i], callback_enqueue);
    }

    //PEEK DATA
    struct_number *s_tmp = (struct_number *)queue.peek(&queue);
    printf("Peek:%d\n", s_tmp->number);

    //SIZE QUEUE
    printf("Size:%u\n", queue.get_size(&queue));

    //PRINT QUEUE
    queue.print(&queue, callback_print);
    
    //DESTROY QUEUE
    destroyQueue(&queue);
    return (EXIT_SUCCESS);
}

const void callback_enqueue(const void* new_data) {
    struct_number *s = new_data;
    printf("Data to insert: %d.\n", s->number);
}

const void callback_dequeue(const void *delete_data)
{
    struct_number *s = delete_data;
    printf("Data to delete:  %d.\n", s->number);
}

const void callback_print(const void* d)
{
    struct_number *s = d;
    printf("(%d) --> ",s->number);
}