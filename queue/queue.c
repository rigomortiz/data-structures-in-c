#include "queue.h"

/**
 *
 * @return Queue
 */
Queue newQueue(){

    struct PrivateDataQueue* p = malloc(sizeof(struct PrivateDataQueue));
    p->size = 0;
    p->final = NULL;
    p->queue_adt = NULL;
    Queue q = {
        .private = p,
        .enqueue = _enqueue_queue,
        .dequeue = _dequeue_queue,
        .peek = _peek_queue,
        .empty = _empty_queue,
        .print = _print_queue,
        .enqueue_multiple = _enqueue_multiple_queue,
        .get_size = _get_size
    };
    return q;
}

/**
 *
 * @param queue1
 */
void destroyQueue(Queue *this){
    struct PrivateDataQueue *private = (struct PrivateDataQueue*)this->private;
    unsigned int i = 0, l = private->size;
    for (i = 0; i < l; i++) {
        this->dequeue(this, NULL);
    }
    free(this->private);
}

/**
 *
 * @param this_queue
 * @param d
 * @param callback
 * @return
 */
int _enqueue_queue(Queue *this, const void* d, void (*callback)(const void*))
{
    QueueADT new;
    struct PrivateDataQueue *private = (struct PrivateDataQueue*)this->private;

    new = (QueueADT)malloc(sizeof(ELEMENT_QUEUE));
    if(new != NULL){
        //CODE HERE
        if(callback != NULL)
            callback(d);
        //END
        new->data = (void*)d;
        new->next = NULL;
        if(private->queue_adt == NULL)
            private->queue_adt = new;
        else
            private->final->next = new;
        private->final = new;
        private->size++;
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
int _dequeue_queue(Queue *this, const void (*callback)(const void*))
{
    struct PrivateDataQueue *private = (struct PrivateDataQueue*)this->private;
    QueueADT p = private->queue_adt;
    if(private->size > 0){
        private->queue_adt = p->next;
        //CODE HERE
        if(callback != NULL)
            callback(p->data);
        //END
        free(p);
        private->size--;
        return 1;
    }else return 0;
}

/**
 *
 * @param this_queue
 * @return
 */
void* _peek_queue(Queue *this) {
    struct PrivateDataQueue *private = (struct PrivateDataQueue*)this->private;
    QueueADT p = private->queue_adt;
    if(private->size > 0){
        void* dn = p->data;
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
int _empty_queue(Queue *this){
    struct PrivateDataQueue *private = (struct PrivateDataQueue*)this->private;
    if(private->size > 0){
        long double i, l = private->size;
        for (i = 0; i < l ; ++i) {
            this->dequeue(this, NULL);
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
void _print_queue(Queue *this, const void (*callback)(const void*)) {
    struct PrivateDataQueue *private = (struct PrivateDataQueue*)this->private;
    if( private->size > 0){
        Queue tmp = *this;
        struct PrivateDataQueue privatetmp = *private;

        while(privatetmp.queue_adt != NULL){
            if( callback != NULL)
                callback(privatetmp.queue_adt->data);
            privatetmp.queue_adt = privatetmp.queue_adt->next;
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
int _enqueue_multiple_queue(Queue *this, const void (*callback)(const void*), int count, ... ){
    int i=0;
    int r=1;
    va_list list;
    va_start(list, count);

    for(i=0; i<count; i++){
        r = r && this->enqueue(this, va_arg(list, void*), callback);
    }
    va_end(list);
    return r;
}

unsigned int _get_size(Queue *this){
    struct PrivateDataQueue *private = (struct PrivateDataQueue*)this->private;
    return private->size;
}