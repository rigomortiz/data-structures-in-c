/* 
 * File:   arbol_main.cpp
 * Author: regoeco-debian
 *
 * Created on 11 de octubre de 2015, 01:53 PM
 */

#include <cstdlib>
#include "arbol.h"

using namespace std;

void mostrarArbol(DATOS d, int r);

typedef struct{
    string texto;
}DatosArbol;
typedef struct{
    int numero;
    char caracter;
}DatosNodo;
typedef struct{
    bool tipo_rama;
    int tamanio;
}DatosRama;


int main(int argc, char** argv) {
    DatosArbol a;
    DatosNodo n[10], *datosNodo;
    Nodo **datos;
    DatosRama r[10];
    
    a.texto ="Un árbol de ejemplo.\n";
    n[0].caracter = n[0].numero = 'a';
    r[0].tamanio = 1; r[0].tipo_rama = 1;
   
    Arbol arbol(&a, &n[0]);
    
    n[1].caracter = n[1].numero = 'b';
    r[1].tamanio = 2; r[1].tipo_rama = 1;
    arbol.insertarNodo(1, &n[1] , &r[1]);
    
    n[2].caracter = n[2].numero = 'c';
    r[2].tamanio = 2; r[2].tipo_rama = 1;
    arbol.insertarNodo(1, &n[2] , &r[2]);
    
    n[3].caracter = n[3].numero = 'd';
    r[3].tamanio = 3; r[3].tipo_rama = 0;
    arbol.insertarNodo(2, &n[3] , &r[3]);
    
    n[4].caracter = n[4].numero = 'e';
    r[4].tamanio = 3; r[4].tipo_rama = 0;
    arbol.insertarNodo(2, &n[4] , &r[4]);
    
    n[5].caracter = n[5].numero = 'f';
    r[5].tamanio = 3; r[5].tipo_rama = 0;
    arbol.insertarNodo(3, &n[5] , &r[5]);
    
    n[6].caracter = n[6].numero = 'g';
    r[6].tamanio = 4; r[6].tipo_rama = 1;
    arbol.insertarNodo(6, &n[6] , &r[6]);
   
    n[7].caracter = n[7].numero = 'h';
    r[7].tamanio = 4; r[7].tipo_rama = 1;
    arbol.insertarNodo(6, &n[7] , &r[7]);
    
    n[8].caracter = n[8].numero = 'i';
    r[8].tamanio = 5; r[8].tipo_rama = 0;
    arbol.insertarNodo(8, &n[8] , &r[8]);
    
    n[9].caracter = n[9].numero = 'j';
    r[9].tamanio = 5; r[9].tipo_rama = 0;
    arbol.insertarNodo(8, &n[9] , &r[9]);
    
    
    printf("numero nodos %d.\n", arbol.getNumeroNodos());
    //arbol.mostrarAnchura(mostrarArbol);
    //arbol.mostrarProfundidad(mostrarArbol);
    
    arbol.eliminarNodo(3);
    //printf("\nVaciar Arbol.");
    //arbol.vaciarArbol();
    printf("\n\nnumero nodos %d\n.", arbol.getNumeroNodos());
    
    datos = (Nodo**)arbol.mostrarNodos();
    for(int i = 0; i < arbol.getNumeroNodos(); i++){
        //datosNodo = (DatosNodo)datos[i]->getDatos();
        printf("(nodo:%d)-->", datos[i]->getNodo());
        
    }
    
    arbol.mostrarAnchura(mostrarArbol);
    arbol.mostrarProfundidad(mostrarArbol);
    getchar();
    return 0;
}


void mostrarArbol(DATOS d, int r)
{
    DatosNodo *datosNodo = (DatosNodo*)d;
    if(r)
        printf("\tCaracter: %c; Número: %d\n",datosNodo->caracter, datosNodo->numero);
    else 
        printf("\tHoja.\n");
}