/* 
 * File:   grafo.h
 * Author: regoeco-debian
 *
 * Created on 20 de septiembre de 2015, 04:09 PM
 */

#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "lista.h"
#include "pthread.h"

#ifdef	__cplusplus
extern "C" {
#endif
	/*============================================================================*/
	//TIPOS DEFINIDOS DATOS
	typedef const char *string; //cadena de caracteres
	typedef void *DATOS;//Datos a almacenar
	typedef void Funcion;//función como argumento
	/*____________________________________________________________________________
	============================================================================*/

	/*============================================================================*/
	//ESTRUCTURA DATOS Veritice
	typedef struct
	{
            int vertice;//numero de vertice
            int numeroAristas;//numero de aristas
            DATOS dato;//puntero de DATOS
            bool bloqueada;//estado de vertice
            int distaciaHaciaEl;
	}V;
	/*____________________________________________________________________________
	============================================================================*/

	/*============================================================================*/
	//ESTRUCTURA DATOS Arista
	typedef struct
	{
            int verticeA;//numero de vertice A
            int verticeB;//numero de vertice B
            char direccion; //L|R|B
            DATOS dato;//puntero de DATOS
            bool bloqueada;//estado de la arista
	}E;
	/*____________________________________________________________________________
	============================================================================*/
	
#ifdef	__cplusplus
}
#endif
class Vertice{
		
    public:
        DATOS pdatos;
        ListaDoble Aristas;
        Vertice(){
        }
        void insertarDatos(DATOS d){
                this->pdatos = d;
        }
        ~Vertice(){
                this->Aristas.vaciar();
        }
};

class Grafo{
    
    private:
        DATOS pdatos;
        ListaDoble Vertices;
        int **Matriz;
        
    public:
        Grafo();
        Grafo(V v[], E e[], int numero_vertices, DATOS d, bool funcionOrdenamientoArista(DATOS nuevo, DATOS insertado, char tipo_orden), bool funcionOrdenamientoVertice(DATOS nuevo, DATOS insertado, char tipo_orden), Funcion funcionInsertarArista(DATOS d), Funcion funcionInsertarVertice(DATOS d));
        ~Grafo(){
                this->Vertices.vaciar();
                //Libera Array
                for (int x = 0; x<this->Vertices.Nelementos(); x++)
                        free(this->Matriz[x]);
                free(this->Matriz);
        }
        void imprimirVertices(Funcion funcionMostrarListaVertice(DATOS d, int respuesta));
        void crear(V v[], E e[], int numero_vertices, DATOS d, bool funcionOrdenamientoArista(DATOS nuevo, DATOS insertado, char tipo_orden), bool funcionOrdenamientoVertice(DATOS nuevo, DATOS insertado, char tipo_orden), Funcion funcionInsertarArista(DATOS d), Funcion funcionInsertarVertice(DATOS d));
        DATOS *getVertice(int vertice);
        /*********************************************************************************/
        DATOS *buscarDatoVertice(DATOS d, bool funcionBuscarLista(DATOS d, DATOS a_buscar));
        DATOS *camino(int verticeA, int verticeB);
        void caminoRecursivo( int vertice1, int vertice2, ListaDoble *lista, int j);
};


typedef struct{
    Vertice *v;
    int vertice;
}VerticeLista;

typedef struct{
    DATOS datos;
    ListaDoble *lista;
}DatoStructMultiple;

/*============================================================================*/
//ESTRUCTURA DATOS
typedef struct{
    int vertice1;//numero del vertice1 
    int vertice2;//numero del vertice2
    Vertice *yo;
    Vertice *padre;
    ListaDoble *listaVerticesHijos;
    int jeneracion;
    Grafo *g;
}thread_parametros;
/*____________________________________________________________________________
============================================================================*/
void *funcionHilo(void *p);
#endif	/* GRAFO_H */
