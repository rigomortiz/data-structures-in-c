/* 
 * File:   arbol.h
 * Author: regoeco-debian
 *
 * Created on 7 de octubre de 2015, 11:21 PM
 */

#ifndef ARBOL_H
#define	ARBOL_H


#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include "lista.h"
#ifdef	__cplusplus
extern "C" {
#endif
    /*============================================================================*/
    //ESTRUCTURA DATOS
    typedef const char *string; //cadena de caracteres
    typedef void *DATOS;//Datos a almacena
    
    /*____________________________________________________________________________
    ============================================================================*/
#ifdef	__cplusplus
}
#endif

bool funcionEliminarNodo(DATOS a_eliminar, DATOS insertado);
bool funcionBuscarNodo(DATOS a_buscar, DATOS insertados);

class Rama{
private:
    DATOS datos;
public:
    Rama(DATOS datos_rama){
        this->datos = datos_rama;
    }
    DATOS getDatos(){
        return datos;
    }
    void setDatos(DATOS d){
        this->datos = datos;
    }
};

class Nodo{
private:
    
    int numero;
    int nodo_padre;
    DATOS datos;
    DATOS datos_rama;
    Rama *rama;
    ListaDoble Nodos;
    
public:
    Nodo(int numero, int nodo_padre, DATOS datos_nodo,DATOS datos_rama){
        this->numero = numero;
        this->datos = datos_nodo;
        this->datos_rama = datos_rama;
        //this->rama = new Rama( datos_rama);
        this->nodo_padre = nodo_padre;
    }
    //Metodo para insertar un subnodo
    int insertarSubNodos(Nodo *nodo_nuevo){
        return this->Nodos.insertar(nodo_nuevo);
    }
    //Metodo para devolver el número de nodo
    int getNodo(){
        return this->numero;
    }
    //Metodo para devolver el puntero del nodo
    Nodo *getPntNodo(){
        return this;
    }
    
    int getNodoPadre(){
        return this->nodo_padre;
    }
    void setNodoPadre(int nodo_padre){
        this->nodo_padre = nodo_padre;
    }
    Rama* getRama(){
        return this->rama;
    }
    DATOS getDatos(){
        return this->datos;
    }
    Nodo **getNodos(){
        return (Nodo**)this->Nodos.mostrar();
    }
    int numeroNodos(){
        return this->Nodos.Nelementos();
    }
    int eliminarSubNodos(){
        return this->Nodos.vaciar();
    }
    int eliminarSubNodo(int posicion){
        return this->Nodos.eliminar(posicion);
    }
    int eliminarSubNodo(DATOS d, bool funcionEliminarNodo(DATOS d, DATOS a_eliminar) ){
        return this->Nodos.eliminar(d, funcionEliminarNodo);
    }
    int eliminarRama(){
        delete this->rama;
        return this->rama?1:0;
    }
    ~Nodo(){
        delete this->rama;
    }
    
};

class Arbol
{
private:
    int numero_nodos;
    DATOS d;
    Nodo *nodo_raiz;
   
    Nodo *buscarAnchura(ListaDoble *listaNodos, DATOS a_buscar, bool funcionBuscarNodo(DATOS dato, DATOS a_buscar));
    void mostrarProfundidad(Nodo *nodo, void mostrarArbol(DATOS d, int r));
    void mostrarArchura(ListaDoble *listaNodos, void mostrarArbol(DATOS d, int r));
    
    int vaciarArbol(Nodo *nodo, Nodo *nodo_padre);
       
public:
    Arbol(DATOS arbol, DATOS nodo);
    ~Arbol();
    /*____________________________________________________________________________
    ============================================================================*/
    //FUNCIONES
    void nuevoArbol(DATOS arbol, DATOS nodo);
    //IS
    bool isHoja(int nodo);
    //SET
    int setDatos(DATOS d);
    //GET
    int getNumeroNodos();
    //INSERTAR
    void insertarNodo(int nodo,int nodo_padre, DATOS datos_nodo, DATOS datos_rama);
    //ELIMINAR
    int vaciarArbol();
    int eliminarNodo(int n);
    //MOSTRAR
    DATOS **mostrarAnchura();
    DATOS **mostrarProfundidad();
    
    
    void mostrarAnchura(void mostrarArbol(DATOS d, int r));
    void mostrarProfundidad(void mostrarArbol(DATOS d, int r));
    Nodo *buscarAnchura(DATOS a_buscar, bool funcionBuscarNodo(DATOS dato, DATOS a_buscar));
    //BUSCAR
    /*============================================================================*/
};




/*
 *  FUNCION MOSTRAR ARBOL
    void mostrarArbol(DATOS d, int r)
    {
        DatosNodo *datosNodo = (DatosNodo*)d;
        if(r)
            printf("\n\tCaracter: %c; Número: %d",datosNodo->caracter, datosNodo->numero);
        else 
            printf("\n\tHoja.");
    }
*/
#endif	/* ARBOL_H */

