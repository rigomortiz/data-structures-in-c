/* 
 * File:   main.c
 * Author: regoeco
 *
 * Created on 2016/12/18
 */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int, char**);
void callback_push(DATA);
void callback_pop(DATA);
typedef struct {
    int number;
} struct_number;

int main(int argc, char** argv)
{
    struct_number n[10];
    int i = 0;
    stack stack_numeros, *self = &stack_numeros;
    init_push(self);
    for(i=0; i<10; i++){
        n[i].number = i*i;
        stack_numeros.push(self, &n[i], callback_push);
    }

    struct_number *s_tmp = (struct_number *)stack_numeros.peek(self);

    printf("Peek:%d\n", s_tmp->number);
    printf("Size:%0.0Lf\n", stack_numeros.size);

    destroy_push(self);
    printf("Size:%0.0Lf\n", stack_numeros.size);
    return (EXIT_SUCCESS);
}


void callback_push(DATA new_data) {
    struct_number *s = new_data;
    printf("Data to insert: %d.\n", s->number);
}

void callback_pop(DATA delete_data)
{
    struct_number *s = delete_data;
    printf("Data to delete:  %d.\n", s->number);
}
/*
//FUNCIONES DE LA PILA
void funcionValorPop(DATA datosEliminados);//muestra y elimina el top de la pila
void funcionTop(DATA datosTope);//muestra el valor top de la pila
void funcionMostrarPila(DATA d);//muestra la pila

typedef struct
{
	char uchar;
    int uint;
	short ushort;
	float ulong;

}myStruct;

int main(int argc, char** argv)
{
    TOPE pila = NULL;
    myStruct e, e1, e2, e3, e4, e5, *pstruct;

    e.uchar = 65;e.uint = 1283;e.ulong = 1323232;e.ushort = 132;
    e1.uchar = 66;e1.uint = 1284;e1.ulong = 1323233;e1.ushort = 133;
    e2.uchar = 67;e2.uint = 1285;e2.ulong = 1323234;e2.ushort = 134;
    e3.uchar = 68;e3.uint = 1286;e3.ulong = 1323235;e3.ushort = 135;
    e4.uchar = 69;e4.uint = 1287;e4.ulong = 1323236;e4.ushort = 136;
    e5.uchar = 70;e5.uint = 1288;e5.ulong = 1323237;e5.ushort = 137;
    mostrarPila(pila,funcionMostrarPila);
    pushMultiple(&pila, funcionPush, 6, &e, &e1, &e2, &e3, &e4, &e5);
    mostrarPila(pila,funcionMostrarPila);
    pstruct = (myStruct*)valorPop(&pila, funcionValorPop);
    printf("\nDato elimminado %c\n",pstruct->uchar);
    mostrarPila(pila,funcionMostrarPila);

    pop(&pila);
    mostrarPila(pila,funcionMostrarPila);

    pstruct = (myStruct*)top(&pila, funcionTop);
    printf("\nDato tope %c\n",pstruct->uchar);
    mostrarPila(pila,funcionMostrarPila);

    vaciarPila(&pila);
    mostrarPila(pila,funcionMostrarPila);

    return (EXIT_SUCCESS);
}

void funcionValorPop(DATA datosEliminados)//muestra y elimina el top de la pila
{
	//myStruct *s = datosEliminados;
    //printf("Datos eliminados;Uchar : %c \t ushort: %d.\n", s->uchar, s->ushort );
}
void funcionTop(DATA datoTope)//muestra el valor top de la pila
{
	//myStruct *s = datoTope;
	//printf("Datos tope; Uchar : %c \t ushort: %d.\n", s->uchar, s->ushort );
}
void funcionMostrarPila(DATA d)//muestra la pila
{
	myStruct *s = d;
    printf("(%c,%d,%f,%d) --> ",s->uchar, s->uint, s->ulong, s->ushort);
}

 */