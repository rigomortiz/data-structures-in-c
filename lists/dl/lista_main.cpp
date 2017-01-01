/* 
 * File:   lista_main.cpp
 * Author: regoeco-debian
 *
 * Created on 14 de octubre de 2015, 11:58 PM
 */

#include <cstdlib>
#include "lista.h"
using namespace std;
/*************************************************************
FUNCIONES LISTA DOBLE ENLACE
/************************************************************/
void listaDobleInsertar(DATOS datosNuevos);
void listaDobleMostrar(DATOS d, int respuesta);
bool listaDobleOrdenamiento(DATOS nuevo, DATOS insertardo, char tipo_orden);

typedef struct{
    int numero;
    char letra;
}myStruct;
int main(int argc, char** argv) {
    ListaDoble lista;
    myStruct e[8];
    e[0].letra = e[0].numero = 112;
    e[1].letra = e[1].numero = 44;
    e[2].letra = e[2].numero = 88;
    e[3].letra = e[3].numero = 67;
    e[4].letra = e[4].numero = 33;
    e[5].letra = e[5].numero = 72;
    e[6].letra = e[6].numero = 100;
    e[7].letra = e[7].numero = 39;
    
    lista.insertar(&e[0], listaDobleInsertar, listaDobleOrdenamiento );
    lista.insertar(&e[1], listaDobleInsertar, listaDobleOrdenamiento );
    lista.insertar(&e[2], listaDobleInsertar, listaDobleOrdenamiento );
    lista.insertar(&e[3], listaDobleInsertar, listaDobleOrdenamiento );
    lista.insertar(&e[4], listaDobleInsertar, listaDobleOrdenamiento );
    lista.insertar(&e[5], listaDobleInsertar, listaDobleOrdenamiento );
    lista.insertar(&e[6], listaDobleInsertar, listaDobleOrdenamiento );
    lista.insertar(&e[7], listaDobleInsertar, listaDobleOrdenamiento );
    
    lista.mostrar(listaDobleMostrar);
    getchar();
    return 0;
}
/*************************************************************
FUNCIONES LISTA DPOBLE ENLACE
/************************************************************/
bool listaDobleOrdenamiento(DATOS nuevo, DATOS insertado, char t)
{
    myStruct *i = (myStruct*)insertado;
    myStruct *n = (myStruct*)nuevo;
    return (( t=='a' && n->numero <= i->numero ) || ( t=='d' && n->numero >= i->numero ))?true:false;
	
}
void listaDobleInsertar (DATOS datosNuevos)
{
    myStruct *s = (myStruct*)datosNuevos;
    printf("Datos insertados: %c, %d .\n", s->letra, s->numero);
}
void listaDobleMostrar(DATOS d, int respuesta)
{
    if (respuesta) {
        myStruct *s = (myStruct*)d;
        printf("( %c, %d ) ---> ", s->letra, s->numero);
    }
    else
        printf("\nLista vacia.\n");
}
