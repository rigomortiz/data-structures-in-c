
#ifndef PUZZLE_H
#define	PUZZLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#ifdef	__cplusplus
extern "C" {
#endif
	/*============================================================================*/
	//ESTRUCTURA DATOS
	typedef void *DATOS;//Datos a almacenar
	typedef void funcionPuzzle;//funci�n como argumento
	/*____________________________________________________________________________
	============================================================================*/
#ifdef	__cplusplus
}
#endif
//template <class Lista>
class Puzzle//(Lista valor1, Lista valor2)
{
private:
	struct estructuraPuzzle {
		DATOS pdatos;//Datos que se almacenan en la casilla
		struct estructuraPuzzle *derecha;//puntero hacia la casilla derecha
		struct estructuraPuzzle *izquierda;//puntero hacia la casilla izquierda
		struct estructuraPuzzle *arriba;//puntero hacia la casilla arriba
		struct estructuraPuzzle *abajo;//puntero hacia la casilla abbajo
		int numero;
	}*Struct;
	//TIPOS DE DATOS
	typedef struct estructuraPuzzle CASILLA;//tipo de dato Elemento
	typedef CASILLA *ENLACE;//tipo de dato puntero de tipo elemnto
	int numElementos;
	/*____________________________________________________________________________
	============================================================================*/
public:
	//Lista lista = valor1;
	Puzzle(int numero = 3);
	~Puzzle();
	//PRINCIPALES
	int Nelementos();
	/*
	int vacia();
	int vaciar();

	int mostrar(funcionLista funcionMostrar(DATOS d, int r));
	DATOS **mostrar();
	int insertar(DATOS d, funcionLista funcionInsertar(DATOS d), bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char tipo_orden));
	int insertar(DATOS d);
	//SECUNDARIAS
	
	int insertarMultiple(funcionLista funcionInsertar(DATOS d), bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char tipo_orden), int numero, ...);
	int insertarMultiple( int numero, ...);
	*/
	/*____________________________________________________________________________
	============================================================================*/
};
#endif	/* PUZZLE_H */
