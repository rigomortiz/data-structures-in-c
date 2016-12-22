/* 
 * File:   main.cpp
 * Author: regoeco-debian
 *
 * Created on 20 de septiembre de 2015, 03:13 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "puzzle.h"
using namespace std;

/*************************************************************
FUNCIONES LISTA DOBLE ENLACE
/************************************************************/
Funcion listaDobleInsertar(DATOS datosNuevos);
Funcion listaDobleMostrar(DATOS d, int respuesta);
bool funcionbuscarLista(DATOS d, DATOS a_Buscar);
bool funcionEliminarLista(DATOS d, DATOS a_eliminar);
//bool funcionOrdenamiento(DATOS nuevo, DATOS insertardo, char tipo_orden);

/*************************************************************
FUNCIONES GRAFO
/************************************************************/
Funcion funcionInsertarArista(DATOS datosNuevos);
Funcion funcionMostrarListaArista(DATOS d, int respuesta);
Funcion funcionInsertarVertice(DATOS datosNuevos);
Funcion funcionMostrarListaVertice(DATOS d, int respuesta);
bool funcionOrdenamientoArista(DATOS nuevo, DATOS insertardo, char tipo_orden);
bool funcionOrdenamientoVertice(DATOS nuevo, DATOS insertardo, char tipo_orden);
typedef struct{
    int numero;
    char letra;
}S;
int main(int argc, char** argv)
{
    char x;
    //crear el grafo que modela el puzzle
    Puzzle  p(16, NULL, funcionOrdenamientoArista, funcionOrdenamientoVertice, funcionInsertarArista, funcionInsertarVertice);
    //p.imprimirVertices(funcionMostrarListaVertice);
    p.camino(6, 11);
    
    scanf("%c", &x);
    return 1;
}

/*************************************************************
FUNCIONES GRAFO
/************************************************************/
Funcion funcionInsertarArista(DATOS datosNuevos)
{
	//E *s = (E*)datosNuevos;
	//printf("Arista insertada:\t q%d <--> q%d .\n", s->verticeA, s->verticeB);
}
Funcion funcionMostrarListaArista(DATOS d, int respuesta)
{
	if (respuesta) {
		E *s = (E*)d;
		DatosArista *dArista = (DatosArista*)s->dato;
		printf("(%d, %d, %c, %d, %c, %d) --> ", s->verticeA, s->verticeB, s->direccion, dArista->bloqueado, dArista->direccion,  dArista->numero_transito );
	}
	else
		printf("\nLista vacia.\n");
}
Funcion funcionInsertarVertice(DATOS datosNuevos)
{
	//Vertice *s = (Vertice*)datosNuevos;
	//V *v;
	//v = (V*)s->pdatos;
	//printf("Vertice insertados:\t q%d n: %d .\n", v->vertice , v->numeroAristas);
}
Funcion funcionMostrarListaVertice(DATOS d, int respuesta)
{
	if (respuesta) {
		Vertice *s = (Vertice*)d;
		V *v = (V*)s->pdatos;
		DatosVertice *dVertice = (DatosVertice*)v->dato;
		printf("(n:%d, q%d, %d, %d, %d) --> ", v->numeroAristas, v->vertice, dVertice->bloqueado, dVertice->en_lugar_correcto, dVertice->numero_de_la_casilla);
		s->Aristas.mostrar(funcionMostrarListaArista);
	}
	else
		printf("\nLista vacia.\n");
}
bool funcionOrdenamientoVertice(DATOS nuevo, DATOS insertado, char t)
{
	V *i = (V*)insertado;
	V *n = (V*)nuevo;
	return ((t == 'a' && n->vertice <= i->vertice) || (t == 'd' && n->vertice >= i->vertice)) ? true : false;
}
bool funcionOrdenamientoArista(DATOS nuevo, DATOS insertado, char t)
{
	E *i = (E*)insertado;
	E *n = (E*)nuevo;
	return ((t == 'a' && n->verticeB <= i->verticeB) || (t == 'd' && n->verticeB >= i->verticeB)) ? true : false;
}

bool funcionbuscarLista(DATOS d, DATOS a_buscar)
{
    //Datos d es el dato almacenado en la lista
    Vertice *s = (Vertice*)d;
    V *v = (V*)s->pdatos;
    DatosVertice *dVertice = (DatosVertice*)v->dato;
    /**********************************************/
    DatosVertice *datoBuscar = (DatosVertice*)a_buscar;

    return (dVertice->numero_de_la_casilla == datoBuscar->numero_de_la_casilla) ? true : false;
}

bool funcionEliminarLista(DATOS d, DATOS a_eliminar)
{
    //Datos d es el dato almacenado en la lista
    S *s = (S*)d;
    S *s1 = (S*)a_eliminar;
    /**********************************************/

    return (s->letra == s1->letra) ? true : false;
}

/*************************************************************
FUNCIONES LISTA DOBLE ENLACE
/************************************************************/

Funcion listaDobleInsertar (DATOS datosNuevos)
{
	S *s = (S*)datosNuevos;
	printf("Datos insertados: %d, %c .\n", s->numero, s->letra);
}
Funcion listaDobleMostrar(DATOS d, int respuesta)
{
    if (respuesta) {
        S *s = (S*)d;
        printf("(%d, %c ) ---> ", s->numero, s->letra);
    }
    else
        printf("\nLista vacia.\n");
}

/*
//Estructura lista doble enlace
ListaDoble ld('a');
myStruct e, e1, e2, e3, e4, e5, *pstruct, **Ptr;
char x;

e.caracter = 'd'; e.flotante=12.87; e.numero = 89; e.texto = "hello";
e1.caracter = 'b'; e1.flotante=58.39; e1.numero = 46; e1.texto = "yes";
e2.caracter = 'k'; e2.flotante=14.90; e2.numero = 67; e2.texto = "si";
e3.caracter = 'u'; e3.flotante=123.098; e3.numero = 23; e3.texto = "no";
e4.caracter = 'p'; e4.flotante=98.76; e4.numero = 59; e4.texto = "world";

ld.mostrar(listaDobleMostrar);
ld.insertarMultiple(listaDobleInsertar, funcionOrdenamiento, 5, &e, &e1, &e2, &e3, &e4);
ld.mostrar(listaDobleMostrar);
ld.vaciar() ? printf("1") : printf("0");
ld.mostrar(listaDobleMostrar);
*/
