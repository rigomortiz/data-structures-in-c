#include "queue.h"

/**
 *
 * @param queue1
 */
void init_queue(queue *queue1){
    queue1->queue_adt = NULL;
    queue1->final = NULL;
    queue1->size = 0;
    queue1->enqueue = enqueue;
    queue1->dequeue = dequeue;
    queue1->peek = peek;
    queue1->empty = empty;
    queue1->print = print;
    queue1->enqueue_multiple = enqueue_multiple;
}

/**
 *
 * @param queue1
 */
void destroy_queue(queue *queue1){
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
int enqueue(queue *this_queue, DATA d, void (*callback)(DATA))
{
    pqueue new;
    new = (pqueue)malloc(sizeof(ELEMENT));
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
int dequeue(queue *this_queue, void (*callback)(DATA))
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
DATA *peek(queue *this_queue)
{
    pqueue p = this_queue->queue_adt;
    if(this_queue->size > 0){
        DATA *dn = p->data;
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
int empty(queue *this_queue){
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
void print(queue *this_queue, void (*callback)(DATA)){
    if( this_queue->size > 0){
        queue tmp = *this_queue;
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
int enqueue_multiple(queue *this_queuek, void (*callback)(DATA), int count, ... ){
    int i=0;
    int r=1;
    va_list list;
    va_start(list, count);

    for(i=0; i<count; i++){
        r = r && this_queuek->enqueue(this_queuek, va_arg(list, DATA), callback);
    }
    va_end(list);
    return r;
}