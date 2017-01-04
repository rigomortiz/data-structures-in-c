#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct StackADT* StackADT, ELEMENT_STACK;
typedef struct Stack Stack;

struct StackADT{
    void* data;
    StackADT next;
};

typedef struct PrivateDataStack{
    StackADT stack_adt;
    unsigned int size;
};

struct Stack{
    void* const private;
    unsigned  int (*const get_size)(Stack *this);
    int (*const push)(Stack *this, void* d, void(*const callback)(const void*));
    int (*const pop)(Stack *this, void(*const callback)(const void*));
    void* (*const peek)(Stack *this);
    int (*const empty)(Stack *this);
    void (*const print)(Stack *this, void(*const callback)(const void*));
    int (*const push_multiple)(Stack *this, void(*const callback)(const void*), int count, ... );
};

Stack newStack();
void destroyStack(Stack *this);
static int _pop_stack(Stack *this, void(*const callback)(const void*));
static int _push_stack(Stack *this, void* d, void(*const callback)(const void*));
static void* _peek_stack(Stack *this);
static int _empty_stack(Stack *this);
static void _print_stack(Stack *this, void(*const callback)(const void*));
static int _push_multiple_stack(Stack *this, void(*const callback)(const void*), int count, ... );
unsigned int _get_size(Stack *this);
#ifdef	__cplusplus
}
#endif
#endif

