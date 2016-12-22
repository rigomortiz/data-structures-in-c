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
    DATOS datos;
    int numero;
    Rama *rama;
    ListaDoble Nodos;
public:
    Nodo(int numero, DATOS datos_nodo,DATOS datos_rama){
        this->numero = numero;
        this->datos = datos_nodo;
        this->rama = new Rama( datos_rama);
    }
    int insertarSubNodos(Nodo *nodo_nuevo){
        return this->Nodos.insertar(nodo_nuevo);
    }
    int getNodo(){
        return this->numero;
    }
    Rama* getRama(){
        return this->rama;
    }
    DATOS getDatos(){
        return this->datos;
    }
    DATOS **getNodos(){
        return this->Nodos.mostrar();
    }
    int numeroNodos(){
        return this->Nodos.Nelementos();
    }
    int eliminarSubNodos(){
        this->Nodos.vaciar();
    }
    int eliminarSubNodo(int posicion){
        this->Nodos.eliminar(posicion);
    }
    int eliminarRama(){
        delete this->rama;
    }
    ~Nodo(){
        delete this->rama;
    }
    
};

class Arbol
{
private:
    DATOS d;
    ListaDoble Nodos;
    Nodo *nodo_raiz;
    
    void mostrarArchura(int nodo, void mostrarArbol(DATOS d, int r));
    void mostrarProfundidad(int nodo, void mostrarArbol(DATOS d, int r));
    int vaciarArbol(int nodo);
    
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
    DATOS **getSubNodos(int nodo);
    int getNumeroNodos();
    int getNumeroSubNodos(int nodo);
    DATOS *getNodo(int nodo){
        return this->Nodos.getStructIndex(nodo -1);
    }
    //INSERTAR
    void insertarNodo(int nodo, DATOS datos_nodo, DATOS datos_rama);
    //ELIMINAR
    int vaciarArbol();
    int eliminarNodo(int n);
    //MOSTRAR
    DATOS **mostrarAnchura();
    DATOS **mostrarProfundidad();
    void mostrarAnchura(void mostrarArbol(DATOS d, int r));
    void mostrarProfundidad(void mostrarArbol(DATOS d, int r));
    
    DATOS **mostrarNodos(){
        return this->Nodos.mostrar();
    }
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

