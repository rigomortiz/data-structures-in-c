

#ifndef ARBOLBINARIO_H_
#define ARBOLBINARIO_H_

#include <cstdio>
#include <cstdlib>
#include <cstdarg>

#ifdef	__cplusplus
extern "C" {
#endif
	/*============================================================================*/
	//ESTRUCTURA DATOS
	typedef const char *string; //cadena de caracteres
	typedef void *DATOS;//Datos a almacenar
	typedef void void_funcionArbol;//funci�n como argumento
	typedef int int_funcionArbol;
	/*____________________________________________________________________________
	============================================================================*/
#ifdef	__cplusplus
}
#endif
class ArbolBinario//(Lista valor1, Lista valor2)
{
private:
	typedef enum {
			simetrico, previo, posterior,
		}Orden;
	struct estructuraArbolBinario {
		DATOS pdatos;//Datos que se almacenan en la pila
		int repeticion;
		struct estructuraArbolBinario *hijoIzquierdo;
		struct estructuraArbolBinario *hijoDerecho;
	}*Struct;
	//TIPOS DE DATOS
	typedef struct estructuraArbolBinario NODO;//tipo de dato Elemento
	typedef NODO *BTREE;//tipo de dato puntero de tipo elemnto
	int numElementos;
	Orden orden;
	/*____________________________________________________________________________
	============================================================================*/
	//FUNCIONES
	//Mostrar
	int inorden(void_funcionArbol mostrar(DATOS d, int r), BTREE hijo);
	int preorden(void_funcionArbol mostrar(DATOS d, int r), BTREE hijo);
	int postorden(void_funcionArbol mostrar(DATOS d, int r), BTREE hijo);
	int vaciar(BTREE *hijo);
	//Insertar
	int insertar(BTREE *rama, void_funcionArbol insertar(DATOS d), int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado), DATOS nuevo );
	int insertar(BTREE *rama, int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado), DATOS nuevo );
	
public:
	
	ArbolBinario(int orden = 0 );
	~ArbolBinario();
	//PRINCIPALES
	int vacia();
	int vaciar();
	int Nelementos();
	//Devolver
	//const ArbolBinario &mostrar();              //encadenamiento
	ArbolBinario &mostrar();
	DATOS **mostrar(int tipo_orden);
	
	int inorden(void_funcionArbol mostrar(DATOS d, int r));
    int preorden(void_funcionArbol mostrar(DATOS d, int r));
    int postorden(void_funcionArbol mostrar(DATOS d, int r));
	//Insertar
	int insertar(DATOS datos_insertar, void_funcionArbol insertar(DATOS d), int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado) );
	int insertarMultiple(void_funcionArbol insertar(DATOS d), int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado) ,  int numero, ...);
	int insertar(DATOS datos_insertar,  int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado) );
	int insertarMultiple( int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado) , int numero, ...);
	//Eliminar
	//Buscar
     

		/*____________________________________________________________________________
	============================================================================*/
};

#endif /* ARBOLBINARIO_H_ */