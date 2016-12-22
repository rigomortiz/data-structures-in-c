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
    /*____________________________________________________________________________
    ============================================================================*/

    /*============================================================================*/
    //ESTRUCTURA DATOS Veritice
    typedef struct
    {
        int vertice;//numero de vertice
        int numeroAristas;//numero de aristas
        DATOS dato;//puntero de DATOS
        bool bloqueado;//estado de vertice
        int distaciaHaciaEl;
    }V;
    /*____________________________________________________________________________
    ============================================================================*/

    /*============================================================================*/
    //ESTRUCTURA DATOS Arista
    typedef struct
    {
        int verticeB;//numero de vertice B
        char direccion; //L|R|B
        DATOS dato;//puntero de DATOS
        bool bloqueada;//estado de la arista
        int tamanio;
    }E;
    /*____________________________________________________________________________
      ============================================================================*/
#ifdef	__cplusplus
}
#endif



/*============================================================================*/
class Arista{
private:
    int verticeB;//numero de vertice B
    char direccion; //L|R|B
    DATOS datos;//puntero de DATOS
    bool bloqueada;//estado de la arista
    int tamanio;
public:
    Arista(){
        
    }
    Arista(int verticeB, char direccion, bool bloqueada, int tamanio, DATOS datos){
        this->verticeB = verticeB;
        this->direccion = direccion;
        this->bloqueada = bloqueada;
        this->tamanio = tamanio;
        this->datos = datos;
    }
    void setDatos(DATOS d){
        this->datos = d;
    }
    DATOS getDatos(){
        return (DATOS)this->datos;
    }
    void setVerticeB(int verticeB){
        this->verticeB = verticeB;
    }
    int getVerticeB(){
        return this->verticeB;
    }
    void setDireccion(char direccion){
        this->direccion = direccion;
    }
    char getDireccion(){
        return this->direccion;
    }
    void setTamanio(int tamanio){
        this->tamanio = tamanio;
    }
    int getTamanio(){
        return this->;
    }
    void setBloqueada(bool bloqueada){
        this->bloqueada = bloqueada;
    }
    bool getBloqueada(){
        return this->bloqueada;
    }
    void imprimir(){
        printf("[%d, %c, %d, %d, %X]->",this->verticeB, this->direccion, this->bloqueada, this->tamanio, this->datos);
    }
    ~Arista(){
    }
};
/*____________________________________________________________________________
  ============================================================================*/
/*************************************************************
FUNCIONES GRAFO
/************************************************************/
void funcionInsertarArista(DATOS datosNuevos);
void funcionMostrarListaArista(DATOS d, int respuesta);
void funcionInsertarVertice(DATOS datosNuevos);
void funcionMostrarListaVertice(DATOS d, int respuesta);
bool funcionOrdenamientoArista(DATOS nuevo, DATOS insertardo, char tipo_orden);
bool funcionOrdenamientoVertice(DATOS nuevo, DATOS insertardo, char tipo_orden);


//Clase vertice 
class Vertice{	
private:
    ListaDoble Aristas;//Lista con doble enlace, que son las aristas
    int vertice;//numero de vertice
    int numeroAristas;//numero de aristas
    DATOS datos;//puntero de DATOS
    bool bloqueado;//estado de vertice
    int distaciaHaciaEl;
    
public:
    Vertice(){
        
    }
    Vertice(int vertice, int numeroAristas, bool bloqueado, int distaciaHaciaEl, DATOS d){
        this->vertice = vertice;
        this->numeroAristas = numeroAristas;
        this->bloqueado = bloqueado;
        this->distaciaHaciaEl = distaciaHaciaEl;
        this->datos = d;
    }
    void setDatos(DATOS d){
        this->datos = d;
    }
    DATOS getDatos(){
        return (DATOS)this->datos;
    }
    void setVertice(int vertice){
        this->vertice = vertice;
    }
    int getVertice(){
        return this->vertice;
    }
    void setNumeroAristas(int numeroAristas){
        this->numeroAristas = numeroAristas;
    }
    int getNumeroAristas(){
        return this->numeroAristas;
    }
    void setBloqueado(bool bloqueado){
        this->bloqueado = bloqueado;
    }
    bool getBloqueado(){
        return this->bloqueado;
    }
    void setDistaciaHaciaEl(int distacia){
        this->distaciaHaciaEl = distacia;
    }
    int getDistaciaHaciaEl(){
        return this->distaciaHaciaEl;
    }
    void setArista(DATOS d){
        //this->Aristas.insertar(d);
        this->Aristas.insertar(d, funcionOrdenamientoArista);
    }
    DATOS *getArista(int a){
        return (DATOS*)this->Aristas.getStructIndex(a-1);
    }
    DATOS **getAristas(){
        return (DATOS**)this->Aristas.mostrar();
    }
    void imprimir(){
        printf("\n(%d, %d, %d, %d, %X)-->", this->vertice, this->numeroAristas, this->bloqueado, this->distaciaHaciaEl, this->datos);
    }
    void crearListaIndexada(){
        this->Aristas.crearListaIndexada();
    }
    void vaciarListaIndexada(){
        this->Aristas.vaciarStructIndex();
    }
    bool aristaEncontrada(DATOS d){
        //Datos d es el dato almacenado en la lista
        Arista *arista;
        bool r = 0;
        /**********************************************/
        Arista *datoBuscar = (Arista*)d;
        
        for(int i = 1; i<=this->Aristas.Nelementos();i++){
            arista = (Arista*)this->getArista(i);
            r = r || (arista->getVerticeB()==datoBuscar->getVerticeB()&&arista->getDireccion()==datoBuscar->getDireccion())?true:false;
        }
        return r;
    }
    ~Vertice(){
        this->Aristas.vaciar();
    }
   
};
/*____________________________________________________________________________
  ============================================================================*/
void *funcionHilo(void *p);
typedef struct{
    ListaDoble *caminos;
    int vertice;
}StructListaCaminos;


//Clase Grafo

class Grafo{
    
private:
    DATOS pdatos;//Datos que almacena
    ListaDoble Vertices;//Lista de Clases tipo Vertice
    int **Matriz;//Matriz de referencia del grafo
    int numeroAristas;
    int numerovertices;
    
    
public:
    ListaDoble camino;
    Grafo();
    Grafo(V v[], E e[], int numero_vertices, DATOS d);
    ~Grafo(){
        this->Vertices.vaciar();
        //Libera Array
        for (int x = 0; x< this->Vertices.Nelementos(); x++)
                free(this->Matriz[x]);
        //free(this->Matriz);
        //free(this->mutex);
    }
    //Insertar un vertice en la lista de vertices
    //pthread_mutex_t *getMutex(int i){
      //  return this->mutex[i];
    //}
    void setVertice(DATOS d){
        //this->Vertices.insertar(d);
        this->Vertices.insertar(d, funcionOrdenamientoVertice);
    }
    //Muestra todos los vertices
    DATOS **getVertices(){
        return this->Vertices.mostrar();
    }
    //Número vertices
    int getNumeroVertices(){
        return this->Vertices.Nelementos();
    }
    //Retorna un vertice en especifico 
    DATOS *getVertice(int vertice)
    {
        return this->Vertices.getStructIndex(vertice-1);
    }
    //Inserta una arista en un vertice en especifico
    void setArista(int vertice, DATOS d){
        Vertice *v = (Vertice*)this->Vertices.getStructIndex(vertice-1);
        v->setArista(d);
    }
    //Muestra todos las aristas de un vertice en especifico
    DATOS **getAristas(int vertice){
        Vertice *v = (Vertice*)this->Vertices.getStructIndex(vertice-1);
        return (DATOS**)v->getAristas();
    }
    //Retorna el numero de aristas de un vertice en especifico
    int getNumeroAristas(int vertice){
        Vertice *v = (Vertice*)this->Vertices.getStructIndex(vertice-1);
        return v->getNumeroAristas();
    }
    //Retorna una arista en especifico
    DATOS *getArista(int vertice, int arista)
    {
        Vertice *v = (Vertice*)this->Vertices.getStructIndex(vertice-1);
        return v->getArista(arista);
    }
    //imprime lista vertices
    void imprimeListaVertices(){
        this->Vertices.mostrar(funcionMostrarListaVertice);
    }
    
    /*============================================================================*/
    void crearMatriz();
    void crear(V v[], E e[], int numero_vertices, DATOS d);
    void imprimir();
    /*____________________________________________________________________________
      ============================================================================*/
    
    /*============================================================================*/
    //Algoritmo para encontrar el camino minimo
    void CaminoAlgoritmoThread(int verticeA, int verticeB);
    void caminoRecursivo(int vertice1, int vertice2, ListaDoble *lista);
    void imprimirCamino();
    void imprimirCamino2(ListaDoble *l);
    /*____________________________________________________________________________
      ============================================================================*/
};
#endif	/* GRAFO_H */

/*============================================================================*/
//ESTRUCTURA DATOS PARA EL HILO

typedef struct{
    int vertice1;//numero del vertice1 
    int vertice2;//numero del vertice2
    Vertice *yo;//Vertice 
    Vertice *padre;
    StructListaCaminos *listaVerticesHijos;
    int jeneracion;
    Grafo *g;
    pthread_mutex_t *mutex_acceso;
}thread_parametros;
void getDatosThread(thread_parametros *datos, int vertice1, int vertice2, int jeneracion, StructListaCaminos *camino, 
        Vertice *padre, Vertice *yo, Grafo *g, pthread_mutex_t *mutex);

/*____________________________________________________________________________
============================================================================*/