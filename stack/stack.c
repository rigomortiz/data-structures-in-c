#include "stack.h"

/**
 *
 * @return Stack
 */
Stack newStack(){
    Stack stack1;
    stack1.stack_adt = NULL;
    stack1.size = 0;
    stack1.push = _push_stack;
    stack1.pop = _pop_stack;
    stack1.peek = _peek_stack;
    stack1.empty = _empty_stack;
    stack1.print = _print_stack;
    stack1.push_multiple = _push_multiple_stack;
    return stack1;
}

/**
 *
 * @param stack1
 */
void destroyStack(Stack *stack1){
    stack1->empty(stack1);
}

/**
 *
 * @details Pushing (storing) an element on the stack.
 * @param this_stack stack self
 * @param d void*
 * @param function_push function to execute
 * @return int
 */
int _push_stack(Stack *this_stack, void* d, const void (*callback)(const void*))
{
    pstack pstack_new = (pstack)malloc(sizeof(ELEMENT_STACK));
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
int _pop_stack(Stack *this_stack, const void (*callback)(const void*))
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
 * @param this_stack
 * @return
 */
void* *_peek_stack(Stack *this_stack)
{
    pstack p = this_stack->stack_adt;
    if(this_stack->size > 0){
        void* *dn = p->data;
        return dn;
    }else {
        return NULL;
    }
}

/**
 *
 * @param this_Stack
 * @return
 */
int _empty_stack(Stack *this_stack)
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
void _print_stack(Stack *this_stack, const  void (*callback)(const void*))
{
    Stack tmp = *this_stack;
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
int _push_multiple_stack(Stack *this_stack, const void (*callback)(const void*), int count, ... )
{
    int i=0;
    int r=1;
    va_list list;
    va_start(list, count);

    for(i=0; i<count; i++){
        r = r && this_stack->push(this_stack, va_arg(list, void*), callback);
    }
    va_end(list);
    return r;
}