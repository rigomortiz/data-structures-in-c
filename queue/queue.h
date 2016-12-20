#ifndef QUEUE_H
#define	QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef	__cplusplus
extern "C" {
    #endif
    /*============================================================================*/
    typedef const char *string;
    typedef void *DATA;
    typedef struct Queue_ADT queue_adt;
    typedef queue_adt *pqueue, ELEMENT;
    typedef struct Queue queue;

    struct Queue_ADT{
        DATA data;
        struct Queue_ADT *next;
    };

    struct Queue{
        pqueue final;
        pqueue queue_adt;
        long double size;
        int (*enqueue)(queue *this_queue, DATA d, void (*callback)(DATA));
        int (*dequeue)(queue *this_queue, void (*callback)(DATA));
        DATA* (*peek)(queue *this_queue);
        int (*empty)(queue *this_queue);
        void (*print)(queue *this_queue, void (*callback)(DATA));
        int (*enqueue_multiple)(queue *this_queue, void (*callback)(DATA), int count, ... );
    };

    void init_queue(queue *queue1);
    void destroy_queue(queue *queue1);
    int enqueue(queue *this_queue, DATA d, void (*callback)(DATA));
    int dequeue(queue *this_queue, void (*callback)(DATA));
    DATA *peek(queue *this_queue);
    int empty(queue *this_queue);
    void print(queue *this_queue, void (*callback)(DATA));
    int enqueue_multiple(queue *this_queuek, void (*callback)(DATA), int count, ... );

    #ifdef	__cplusplus
}
#endif
#endif

