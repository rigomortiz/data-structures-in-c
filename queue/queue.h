#ifndef QUEUE_H
#define	QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

#ifdef	__cplusplus
extern "C" {
#endif
typedef struct QueueADT* QueueADT, ELEMENT_QUEUE;
typedef struct Queue Queue;

struct QueueADT{
    void* data;
    QueueADT next;
};

typedef struct PrivateDataQueue{
    QueueADT final;
    QueueADT queue_adt;
    unsigned int size;
};
struct Queue{
    void* const private;
    unsigned  int (*const get_size)(Queue *this);
    int (*const enqueue)(Queue *this, const void* d, void(*const callback)(const void*));
    int (*const dequeue)(Queue *this, void(*const callback)(const void*));
    void* (*const peek)(Queue *this);
    int (*const empty)(Queue *this);
    void (*const print)(Queue *this, void(*const callback)(const void*));
    int (*const enqueue_multiple)(Queue *this, void(*const callback)(const void*), int count, ... );
};

Queue newQueue();
void destroyQueue(Queue *queue);
static unsigned int _get_size(Queue *this);
static int _enqueue_queue(Queue *this, const void* d, void (*const callback)(const void*));
static int _dequeue_queue(Queue *this, void(*const callback)(const void*));
static void* _peek_queue(Queue *this);
static int _empty_queue(Queue *this);
static void _print_queue(Queue *this, void(*const callback)(const void*));
static int _enqueue_multiple_queue(Queue *this, void(*const callback)(const void*), int count, ... );


#ifdef	__cplusplus
}
#endif
#endif

