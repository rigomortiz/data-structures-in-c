#ifndef PILA_H
#define	PILA_H

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
/*____________________________________________________________________________
  ============================================================================*/


/*============================================================================*/
struct Stack_ADT{
    DATA data;
    struct Stack_ADT *next;
};

struct Stack{
    pstack stack_adt;
    long double size;
    int (*push)(stack *this_stack, DATA d, void (*callback)(DATA));
    int (*pop)(stack *this_stack, void (*callback)(DATA));
    void (*peek)(void);
    void (*print)(void);
    void (*remove)(void);
};
/*____________________________________________________________________________
  ============================================================================*/

/*============================================================================*/
int pop(stack *this_stack, void (*callback)(DATA));
int push(stack *this_stack, DATA d, void (*callback)(DATA));
void print(void);
void init_push(stack *stack1);
void destroy_push(stack *stack1);


int pushMultiple(pstack *pila, void (*callback)(void), int numero,... );
DATA *valorPop(pstack *pila, void (*callback)(void)); //devuelve el elemento del tope de la pila y lo elimina
DATA *top(pstack *pila, void (*callback)(void));//devuelve el valor del tope de la pila sin sacarlo
int mostrarPila(pstack pila, void (*callback)(void));//muestra toda la pila
int vaciarPila(pstack *pila); //vacia la pila
int NelementosPila(pstack pila);//devuelve el numero de elementos
int vaciaPila(pstack pila);//devuelve un 0 si la pila esta vacia

/*____________________________________________________________________________
  ============================================================================*/

/* 
 * [===========================================================================]
 * Ejemplo de funciones como argumento
void funcionPush(DATA DATANuevos)//insertar en la pila
{
	//myStruct *s = DATANuevos;
    //printf("DATA insertados; Uchar : %c ushort: %d.\n", s->uchar, s->ushort );
}
void funcionValorPop(DATA DATAEliminados)//muestra y elimina el top de la pila
{
	//myStruct *s = DATAEliminados;
    //printf("DATA eliminados;Uchar : %c \t ushort: %d.\n", s->uchar, s->ushort );
}
void funcionTop(DATA datoTope)//muestra el valor top de la pila
{
	//myStruct *s = datoTope;
	//printf("DATA tope; Uchar : %c \t ushort: %d.\n", s->uchar, s->ushort );
}
void funcionMostrarPila(DATA d)//muestra la pila
{
	//myStruct *s = d;
    //printf("(%c,%d,%f,%d) --> ",s->uchar, s->uint, s->ulong, s->ushort);
}
*/
    #ifdef	__cplusplus
}
#endif
#endif	/* PILA_H */

