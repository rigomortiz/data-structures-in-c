#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef	__cplusplus
extern "C" {
    #endif
    /*============================================================================*/
    typedef const char *string;
    typedef void *DATA;
    typedef struct Stack_ADT stack_adt;
    typedef stack_adt *pstack, ELEMENT;
    typedef struct Stack stack;

    struct Stack_ADT{
        DATA data;
        struct Stack_ADT *next;
    };

    struct Stack{
        pstack stack_adt;
        long double size;
        int (*push)(stack *this_stack, DATA d, void (*callback)(DATA));
        int (*pop)(stack *this_stack, void (*callback)(DATA));
        DATA *(*peek)(stack *this_stack);
        int (*empty)(stack *this_stack);
        void (*print)(stack *this_stack, void (*callback)(DATA));
        int (*push_multiple)(stack *this_stack, void (*callback)(DATA), int count, ... );
    };

    void init_stack(stack *stack1);
    void destroy_stack(stack *stack1);
    int pop(stack *this_stack, void (*callback)(DATA));
    int push(stack *this_stack, DATA d, void (*callback)(DATA));
    DATA *peek(stack *this_stack);
    int empty(stack *this_stack);
    void print(stack *this_stack, void (*callback)(DATA));
    int push_multiple(stack *this_stack, void (*callback)(DATA), int count, ... );
    /*____________________________________________________________________________
      ============================================================================*/

    #ifdef	__cplusplus
}
#endif
#endif

