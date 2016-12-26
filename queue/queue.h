#ifndef QUEUE_H
#define	QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct{
    void* data;
    struct Queue_ADT *next;
}*pqueue, ELEMENT_QUEUE;

typedef struct Queue Queue;
struct Queue{
    pqueue final;
    pqueue queue_adt;
    long double size;
    int (*enqueue)(Queue *this_queue, const void* d, void (*callback)(const void*));
    int (*dequeue)(Queue *this_queue, const void (*callback)(const void*));
    void** (*peek)(Queue *this_queue);
    int (*empty)(Queue *this_queue);
    void (*print)(Queue *this_queue, const void (*callback)(const void*));
    int (*enqueue_multiple)(Queue *this_queue, const void (*callback)(const void*), int count, ... );
};

Queue newQueue();
void destroyQueue(Queue *queue1);
static int _enqueue_queue(Queue *this_queue, const void* d, void (*callback)(const void*));
static int _dequeue_queue(Queue *this_queue, const void (*callback)(const void*));
static void* *_peek_queue(Queue *this_queue);
static int _empty_queue(Queue *this_queue);
static void _print_queue(Queue *this_queue, const void (*callback)(const void*));
static int _enqueue_multiple_queue(Queue *this_queuek, const void (*callback)(const void*), int count, ... );


#ifdef	__cplusplus
}
#endif
#endif

