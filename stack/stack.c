#include "stack.h"
/**
 *
 * @param stack1
 */
void init_stack(stack *stack1){
    stack1->stack_adt = NULL;
    stack1->size = 0;
    stack1->push = push;
    stack1->pop = pop;
    stack1->peek = peek;
    stack1->empty = empty;
    stack1->print = print;
    stack1->push_multiple = push_multiple;
}

/**
 *
 * @param stack1
 */
void destroy_stack(stack *stack1){
    stack1->empty(stack1);
}

/**
 *
 * @details Pushing (storing) an element on the stack.
 * @param this_stack stack self
 * @param d DATA
 * @param function_push function to execute
 * @return int
 */
int push(stack *this_stack, DATA d, void (*callback)(DATA))
{
    pstack pstack_new = (pstack)malloc(sizeof(ELEMENT));
    if(pstack_new != NULL){
        //CODE HERE
        if(callback != NULL)
            callback(d);
        //END
        pstack_new->data = d;
        pstack_new->next = this_stack->stack_adt;
        this_stack->stack_adt = pstack_new;
        this_stack->size++;
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
int pop(stack *this_stack, void (*callback)(DATA))
{
    pstack p = this_stack->stack_adt;
    if(this_stack->size > 0){
        //CODE HERE
        if(callback != NULL)
            callback(p->data);
        //END
        this_stack->stack_adt = p->next;
        free(p);
        this_stack->size--;
        return 1;
    }else return 0;
}

/**
 *
 * @param pila
 * @param funcionTop
 * @return
 */
DATA *peek(stack *this_stack)
{
    pstack p = this_stack->stack_adt;
    if(this_stack->size > 0){
        DATA *dn = p->data;
        return dn;
    }else {
        return NULL;
    }
}

/**
 *
 * @param this_stack *stack
 * @return
 */
int empty(stack *this_stack)
{
    if(this_stack->size > 0){
        long double i, l = this_stack->size;
        for (i = 0; i < l ; ++i) {
            this_stack->pop(this_stack, NULL);
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
void print(stack *this_stack, void (*callback)(DATA))
{
    stack tmp = *this_stack;
    if(tmp.size > 0){
        while(tmp.stack_adt != NULL){
            if(callback != NULL){
                callback(tmp.stack_adt->data);
            }
            tmp.stack_adt = tmp.stack_adt->next;
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
int push_multiple(stack *this_stack, void (*callback)(DATA), int count, ... )
{
    int i=0;
    int r=1;
    va_list list;
    va_start(list, count);

    for(i=0; i<count; i++){
        r = r && this_stack->push(this_stack, va_arg(list, DATA), callback);
    }
    va_end(list);
    return r;
}