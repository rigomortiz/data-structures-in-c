#ifndef LISTA_H
#define	LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#ifdef	__cplusplus
extern "C" {
    #endif
/*============================================================================*/
//ESTRUCTURA DATOS
typedef const char *string; //cadena de caracteres
typedef void *DATOS;//Datos a almacenar
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//ESTRUCTURA: LISTA DOBLE ENLACE SIGUIENTE ANTERIOR
typedef const char *Ordenamiento;

typedef struct{
	string  orden;
	struct List{
		DATOS pdatos;//Datos que se almacenan en la pila
		struct List *siguiente;//puntero hacia el elemento siguiente de la lista
		struct List *anterior;//puntero hacia el elemento anterior de la lista
	}*Lista;
}LISTA;
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//TIPOS DE DATOS
typedef struct List ELEMENTO;//tipo de dato Elemento
typedef ELEMENTO *ENLACE;//tipo de dato puntero de tipo elemnto
typedef void FuncionLista();//función como argumento
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//FUNCIONES COMO ARGUMENTO
FuncionLista funcionInsertar;
FuncionLista funcionMostrarLista;
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//FUNCIONES PROTOTIPO
int vaciaLista(ENLACE *lista);//retorna 0 si la pila esta vacia
int vaciarLista(LISTA *lista); //para vaciar la lista
int NelementosLista(LISTA lista);//devuelve el numero de elementos de la lista
int mostrarLista(LISTA lista, FuncionLista funcionMostrarLista);//muestra toda la lista
int insertar(LISTA *lista, DATOS d , FuncionLista funcionInsertar);//Inserta en la lista
int insertarMultiple(LISTA *lista, FuncionLista funcionInsertar,int numero,... );

//int eliminarNumero(ENLACE *lista, int v);//elimina un dato int
/*____________________________________________________________________________
============================================================================*/

    #ifdef	__cplusplus
}
#endif

#endif	/* LISTA_H */
