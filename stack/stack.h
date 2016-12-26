#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef	__cplusplus
extern "C" {
#endif
typedef struct Stack Stack;

typedef struct Stack_ADT{
    void* data;
    struct Stack_ADT *next;
}*pstack, ELEMENT_STACK;

struct Stack{
    pstack stack_adt;
    long double size;
    int (*push)(Stack *this_stack, void* d, const void (*callback)(const void*));
    int (*pop)(Stack *this_stack, const void (*callback)(const void*));
    void** (*peek)(Stack *this_stack);
    int (*empty)(Stack *this_stack);
    void (*print)(Stack *this_stack, const void (*callback)(const void*));
    int (*push_multiple)(Stack *this_stack, const void (*callback)(const void*), int count, ... );
};

Stack newStack();
void destroyStack(Stack *stack1);
static int _pop_stack(Stack *this_stack, const void (*callback)(const void*));
static int _push_stack(Stack *this_stack, void* d, const void (*callback)(const void*));
static void* *_peek_stack(Stack *this_stack);
static int _empty_stack(Stack *this_stack);
static void _print_stack(Stack *this_stack, const void (*callback)(const void*));
static int _push_multiple_stack(Stack *this_stack, const void (*callback)(const void*), int count, ... );

#ifdef	__cplusplus
}
#endif
#endif

