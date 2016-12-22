/* 
 * File:   lista.h
 * Author: regoeco-debian
 *
 * Created on 20 de septiembre de 2015, 03:14 PM
 */

#ifndef LISTA_H
#define	LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef	__cplusplus
extern "C" {
#endif
	/*============================================================================*/
	//TIPOS DEFINIDOS DE DATOS
	typedef const char *string; //cadena de caracteres
	typedef void *DATOS;//Datos a almacenar
	typedef void Funcion;//funci�n como argumento
	/*____________________________________________________________________________
	============================================================================*/
#ifdef	__cplusplus
}
#endif
class ListaDoble
{
private:
	char orden;//Orden de la lista a(ascendente)|d(descendente)
	DATOS *Struct_Index;//puntero que contiene toda la lista en forma de array
	int numElementosStruct_Index;//numero de elementos de la lista en forma de array
	//Estructura lista 
	struct estructuraListaDoble {
		DATOS pdatos;//Datos que se almacenan en la pila
		struct estructuraListaDoble *siguiente;//puntero hacia el elemento siguiente de la lista
		struct estructuraListaDoble *anterior;//puntero hacia el elemento anterior de la lista
	}*Struct;
	//TIPOS DE DATOS
	typedef struct estructuraListaDoble ELEMENTO;//tipo de dato Elemento
	typedef ELEMENTO *ENLACE;//tipo de dato puntero de tipo elemnto
	int numElementos;//numero de elementos de la lista
	/*____________________________________________________________________________
	============================================================================*/
public:
	//Lista lista = valor1;
	ListaDoble(char orden = 'a');
	~ListaDoble();
	//PRINCIPALES
	bool vacia();//retorna 1 si esta vacia la lista 
	bool vaciar();//vacia la lista
	int Nelementos();//retorna el numero de elementos de la lista
	int mostrar(Funcion funcionMostrar(DATOS d, int r));// muestra la lista 
	DATOS **mostrar();//retorna de forma de arreglo de punteros la lista 
	//inserta en la lista el dato d de forma ordenada
	int insertar(DATOS d, Funcion funcionInsertar(DATOS d), bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char tipo_orden));
	int insertar(DATOS d);
	//SECUNDARIAS
	int crearListaIndexada();//crea una array de la lista
	//insertar de forma multiple Datos d
	DATOS *getStructIndex(int i);//retorna un puntero de tipo DATOS del array de la lista 
	void vaciarStructIndex();//vacia array de la lista
	int insertarMultiple( Funcion funcionInsertar(DATOS d), bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char tipo_orden), int numero, ...);
	int insertarMultiple( int numero, ...);
	/*______________________________________________________________________
	========================================================================*/
	DATOS *buscar(DATOS d, bool funcionBuscarLista(DATOS d, DATOS a_buscar));//busca un dato d en la lista
        int eliminar(DATOS d, bool funcionEliminarLista(DATOS d, DATOS a_eliminar));
};
#endif	/* LISTA_H */