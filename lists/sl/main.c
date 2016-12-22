/*
 * File:   main.c
 * Author: regoeco
 * Title: Lista
 * Created on 3 de mayo de 2015, 12:25 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

//FUNCIONES DE LA LISTA
void funcionEliminar();
void funcionInsertar();
void funcionMostrarLista();
typedef struct
{
	int i;
	float f;
	char c;
	double d;
}myStruct;

int main(int argc, char** argv) {
	LISTA L2;
	myStruct e, e1, e2, e3, e4;

	L2.orden = "asc";
	L2.Lista = NULL;


	e.i = 11;e.f = 12.03;e.c = 'v';e.d = 1566.022222;
	e1.i = 10;e1.f = 12.02;e1.c = 'u';e1.d = 1566.022221;
	e2.i = 9;e2.f = 12.01;e2.c = 't';e2.d = 1566.022220;
	e3.i = 8;e3.f = 12.00;e3.c = 's';e3.d = 1566.022219;
	e4.i = 7;e4.f = 11.99;e4.c = 'r';e4.d = 1566.022218;

	//insertar(&L2, &e , funcionInsertar);
	//insertar(&L2, &e1 , funcionInsertar);
	insertarMultiple(&L2, funcionInsertar, 5, &e, &e1, &e2, &e3, &e4 );

	printf("\nelementos #:%d\n", NelementosLista(L2));
	mostrarLista(L2, funcionMostrarLista);

	vaciarLista(&L2);
	printf("\nelementos #:%d\n", NelementosLista(L2));
    mostrarLista(L2, funcionMostrarLista);
    return (EXIT_SUCCESS);
}

void funcionEliminar(DATOS *d, DATOS dn){}

void funcionInsertar(DATOS datosNuevos)
{
	myStruct *s = datosNuevos;
    printf("Datos insertados; %f, %f, %d, %c.\n", s->d, s->f, s->i, s->c);
}

void funcionMostrarLista(DATOS d)
{
	myStruct *s = d;
	printf("(%f, %f, %d, %c) --> ", s->d, s->f, s->i, s->c);
}
