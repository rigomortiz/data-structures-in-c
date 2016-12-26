#include "queue.h"

/**
 *
 * @return Queue
 */
Queue newQueue(){
    Queue q;
    q.queue_adt = NULL;
    q.final = NULL;
    q.size = 0;
    q.enqueue = _enqueue_queue;
    q.dequeue = _dequeue_queue;
    q.peek = _peek_queue;
    q.empty = _empty_queue;
    q.print = _print_queue;
    q.enqueue_multiple = _enqueue_multiple_queue;
    return q;
}

/**
 *
 * @param queue1
 */
void destroyQueue(Queue *queue1){
    long double i = 0, l = queue1->size;
    for (i = 0; i < l; i++) {
        queue1->dequeue(queue1, NULL);
    }
}

/**
 *
 * @param this_queue
 * @param d
 * @param callback
 * @return
 */
int _enqueue_queue(Queue *this_queue, const void* d, void (*callback)(const void*))
{
    pqueue new;
    new = (pqueue)malloc(sizeof(ELEMENT_QUEUE));
    if(new != NULL){
        //CODE HERE
        if(callback != NULL)
            callback(d);
        //END
        new->data = d;
        new->next = NULL;
        if(this_queue->queue_adt == NULL)
            this_queue->queue_adt = new;
        else
            this_queue->final->next = new;
        this_queue->final = new;
        this_queue->size++;
        return 1;
    }else {
        return 0;
    }
}

/**
 *
 * @param this_queue queue
 * @param callback
 * @return
 */
int _dequeue_queue(Queue *this_queue, const void (*callback)(const void*))
{
    pqueue p = this_queue->queue_adt;
    if(this_queue->size > 0){
        this_queue->queue_adt = p->next;
        //CODE HERE
        if(callback != NULL)
            callback(p->data);
        //END
        free(p);
        this_queue->size--;
        return 1;
    }else return 0;
}

/**
 *
 * @param this_queue
 * @return
 */
void* *_peek_queue(Queue *this_queue)
{
    pqueue p = this_queue->queue_adt;
    if(this_queue->size > 0){
        void* *dn = p->data;
        return dn;
    }else {
        return NULL;
    }
}

/**
 *
 * @param this_queue
 * @return
 */
int _empty_queue(Queue *this_queue){
    if(this_queue->size > 0){
        long double i, l = this_queue->size;
        for (i = 0; i < l ; ++i) {
            this_queue->dequeue(this_queue, NULL);
        }
        return 1;
    }else{
        return 0;
    }
}

/**
 *
 * @param this_queue
 * @param callback
 */
void _print_queue(Queue *this_queue, const void (*callback)(const void*)){
    if( this_queue->size > 0){
        Queue tmp = *this_queue;
        while(tmp.queue_adt != NULL){
            if( callback != NULL)
                callback(tmp.queue_adt->data);
            tmp.queue_adt = tmp.queue_adt->next;
        }
        printf(" NULL.\n");
    }
    else{
        printf("\nCola vacia.\n");
    }
}

/**
 *
 * @param this_queuek
 * @param callback
 * @param count
 * @return
 */
int _enqueue_multiple_queue(Queue *this_queuek, const void (*callback)(const void*), int count, ... ){
    int i=0;
    int r=1;
    va_list list;
    va_start(list, count);

    for(i=0; i<count; i++){
        r = r && this_queuek->enqueue(this_queuek, va_arg(list, void*), callback);
    }
    va_end(list);
    return r;
}