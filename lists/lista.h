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
	typedef void funcionLista;//funci�n como argumento
	typedef void void_funcionArbol;//funci�n como argumento
	typedef int int_funcionArbol;
	/*____________________________________________________________________________
	============================================================================*/
#ifdef	__cplusplus
}
#endif
//template <class Lista>
class ListaDoble//(Lista valor1, Lista valor2)
{
private:
	char orden[2];
	struct estructuraListaDoble {
		DATOS pdatos;//Datos que se almacenan en la pila
		struct estructuraListaDoble *siguiente;//puntero hacia el elemento siguiente de la lista
		struct estructuraListaDoble *anterior;//puntero hacia el elemento anterior de la lista
	}*Struct;
	//TIPOS DE DATOS
	typedef struct estructuraListaDoble ELEMENTO;//tipo de dato Elemento
	typedef ELEMENTO *ENLACE;//tipo de dato puntero de tipo elemnto
	int numElementos;
	/*____________________________________________________________________________
	============================================================================*/
public:
	//Lista lista = valor1;
	ListaDoble(char orden = 'a');
	~ListaDoble();
	//PRINCIPALES
	int vacia();
	int vaciar();
	int Nelementos();
	int mostrar(funcionLista funcionMostrar(DATOS d, int r));
	DATOS **mostrar();
	int insertar(DATOS d, funcionLista funcionInsertar(DATOS d), bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char tipo_orden));
	int insertar(DATOS d);
	//SECUNDARIAS
	
	int insertarMultiple(funcionLista funcionInsertar(DATOS d), bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char tipo_orden), int numero, ...);
	int insertarMultiple( int numero, ...);
	/*____________________________________________________________________________
	============================================================================*/
};
#endif	/* LISTA_H */
