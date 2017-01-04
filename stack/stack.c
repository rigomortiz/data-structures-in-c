#include "stack.h"

/**
 *
 * @return Stack
 */
Stack newStack(){
    struct PrivateDataStack* p = malloc(sizeof(struct PrivateDataStack));
    p->size = 0;
    p->stack_adt = NULL;
    Stack stack = {
        .private = p,
        .get_size = _get_size,
        .empty = _empty_stack,
        .peek = _peek_stack,
        .pop = _pop_stack,
        .print = _print_stack,
        .push = _push_stack,
        .push_multiple = _push_multiple_stack
    };
    return stack;
}

/**
 *
 * @param stack1
 */
void destroyStack(Stack *this){
    this->empty(this);
    free(this->private);
}

/**
 *
 * @details Pushing (storing) an element on the stack.
 * @param this_stack stack self
 * @param d void*
 * @param function_push function to execute
 * @return int
 */
int _push_stack(Stack *this, void* d, void(*const callback)(const void*)) {
    StackADT new;
    struct PrivateDataStack *private = (struct PrivateDataStack*)this->private;

    new = (StackADT)malloc(sizeof(ELEMENT_STACK));
    if(new != NULL){
        //CODE HERE
        if(callback != NULL)
            callback(d);
        //END
        new->data = d;
        new->next = private->stack_adt;
        private->stack_adt = new;
        private->size++;
        return 1;
    }else {
        return 0;
    }
}

/**
 *
 * @details Removing (accessing) an element from the stack.
 * @param this_stack stack self
 * @param function_pop function to execute
 * @return int
 */
int _pop_stack(Stack *this, void(*const callback)(const void*)) {
    struct PrivateDataStack  *private = (struct PrivateDataStack*)this->private;
    if(private->size > 0){
        StackADT p = private->stack_adt;
        //CODE HERE
        if(callback != NULL)
            callback(p->data);
        //END
        private->stack_adt = p->next;
        free(p);
        private->size--;
        return 1;
    }else return 0;
}

/**
 *
 * @param this_stack
 * @return
 */
void* _peek_stack(Stack *this) {
    struct PrivateDataStack *private = (struct PrivateDataStack*)this->private;
    if(private->size > 0){
        StackADT p = private->stack_adt;
        return p->data;
    }else {
        return NULL;
    }
}

/**
 *
 * @param this_Stack
 * @return
 */
int _empty_stack(Stack *this){
    struct PrivateDataStack *private = (struct PrivateDataStack*)this->private;
    if(private->size > 0){
        unsigned int i, l = private->size;
        for (i = 0; i < l ; i++) {
            this->pop(this, NULL);
        }
        return 1;
    }else{
        return 0;
    }
}

/**
 *
 * @param this_stack
 * @param callback
 */
void _print_stack(Stack *this, void(*const callback)(const void*)) {
    struct PrivateDataStack *private = (struct PrivateDataStack*)this->private;
    struct PrivateDataStack private_tmp = *private;
    if(private_tmp.size > 0){
        while(private_tmp.stack_adt != NULL){
            if(callback != NULL){
                callback(private_tmp.stack_adt->data);
            }
            private_tmp.stack_adt = private_tmp.stack_adt->next;
        }
        printf(" NULL.\n");
    }else{
        printf("\nPila vacia.\n");
    }
}

/**
 *
 * @param this_stack
 * @param callback
 * @param count
 * @return
 */
int _push_multiple_stack(Stack *this, void(*const callback)(const void*), int count, ... ) {
    int i=0;
    int r=1;
    va_list list;
    va_start(list, count);

    for(i=0; i<count; i++){
        r = r && this->push(this, va_arg(list, void*), callback);
    }
    va_end(list);
    return r;
}

/**
 *
 * @param this
 * @return
 */
unsigned int _get_size(Stack *this){
    struct PrivateDataStack *private = (struct PrivateDataStack*)this->private;
    return private->size;
}