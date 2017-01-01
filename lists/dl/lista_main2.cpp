/* 
 * File:   lista_main.cpp
 * Author: regoeco-debian
 *
 * Created on 14 de octubre de 2015, 11:58 PM
 */

#include <cstdlib>
#include "lista.h"
using namespace std;
/*************************************************************/
//FUNCIONES LISTA DOBLE ENLACE
/************************************************************/
void funcionInsertar(DATOS datosNuevos);
void funcionMostrar(DATOS d, int respuesta);
bool funcionOrdenamiento(DATOS nuevo, DATOS insertardo, char tipo_orden);
bool funcionEliminar(DATOS eliminar, DATOS insertado);
bool funcionBuscar(DATOS buscar, DATOS insertado);
typedef struct{
    int numero;
    char letra;
}myStruct;
typedef struct{
    string title;
    string campo1;
    string campo2;
}datosLista;
int main(int argc, char** argv) {
    ListaDoble lista;
    myStruct e[16];
    myStruct **arrayMyStruct = NULL;
    myStruct struct_a_buscar;
    datosLista d;
    
    int nElementos = 0;
    d.campo1 = "Letra";
    d.campo2 = "Numero";
    d.title = "Texto";
   
    
    
    lista.setDatosLista(&d);
    e[0].letra = 'a' ;e[0].numero = 112;
    e[1].letra = 'b' ;e[1].numero = 44;
    e[2].letra = 'r' ;e[2].numero = 88;
    e[3].letra = 'm' ;e[3].numero = 647;
    e[4].letra = 'q' ;e[4].numero = 33;
    e[5].letra = 's' ;e[5].numero = 72;
    e[6].letra = 'z' ;e[6].numero = 100;
    e[7].letra = 'c' ;e[7].numero = 39;
    e[8].letra = 'i' ;e[8].numero = 112;
    e[9].letra = 'o' ;e[9].numero = 23;
    e[10].letra = 'a' ;e[10].numero = 45;
    e[11].letra = 'e' ;e[11].numero = 98;
    e[12].letra = 'c' ;e[12].numero = 10;
    e[13].letra = 'x' ;e[13].numero = 213;
    e[14].letra = 'z' ;e[14].numero = 400;
    e[15].letra = 'b' ;e[15].numero = 309;
    
    lista.insertarMultiple(funcionInsertar, funcionOrdenamiento, 16, &e[0], &e[1], &e[2], &e[3], &e[4], &e[5], &e[6], &e[7], &e[8],
                                                                     &e[9], &e[10], &e[11], &e[12], &e[13], &e[14], &e[15], &e[16], &e[17]);
    
    /*
    //MOSTRAR TODA LA LISTA
    arrayMyStruct = (myStruct**)lista.mostrar();
    printf("\n\n+-----------------+");
    printf("\n| #  Letra  Numero|\n");
    printf(" ----------------- \n");
    for(int i = 0; i < lista.Nelementos(); i++)
        printf("%3d %3c %5d\n",i, arrayMyStruct[i]->letra, arrayMyStruct[i]->numero);
    printf("+-----------------+\n\n");
    */
     
    //BUSCAR VARIOS ELEMNETOS 
    struct_a_buscar.letra = 'b';
    struct_a_buscar.numero = 100;
    nElementos = lista.buscarAll(&struct_a_buscar, (DATOS**)arrayMyStruct, funcionBuscar);
    printf("\nElementos %d",nElementos);
    printf("\n\n+-----------------+");
    printf("\n| #  Letra  Numero|\n");
    printf(" ----------------- \n");
    for(int i = 0; i < nElementos; i++)
        printf("%3d %3c %5d\n",i, arrayMyStruct[i]->letra, arrayMyStruct[i]->numero);
    printf("+-----------------+\n\n");
    
    
    //lista.mostrar(listaDobleMostrar);
    lista.eliminar(&e[0],funcionEliminar);
    printf("\nElementos %d",lista.Nelementos());
    lista.mostrar(funcionMostrar);
    getchar();
    return 0;
}
/************************************************************/
//FUNCIONES LISTA DPOBLE ENLACE
/************************************************************/
bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char t)
{
    myStruct *i = (myStruct*)insertado;
    myStruct *n = (myStruct*)nuevo;
    return (( t=='a' && n->letra <= i->letra ) || ( t=='d' && n->letra >= i->letra ))?true:false;
	
}
void funcionInsertar (DATOS datosNuevos)
{
    myStruct *s = (myStruct*)datosNuevos;
    printf("Datos insertados: %c, %d .\n", s->letra, s->numero);
}
void funcionMostrar(DATOS d, int respuesta)
{
    if (respuesta) {
        myStruct *s = (myStruct*)d;
        printf("( %c, %d ) ---> ", s->letra, s->numero);
    }
    else
        printf("\nLista vacia.\n");
}
bool funcionEliminar(DATOS eliminar, DATOS insertado)
{
    myStruct *i = (myStruct*)insertado;
    myStruct *n = (myStruct*)eliminar;
    return (n->numero == i->numero )?true:false;
}
bool funcionBuscar(DATOS a_buscar, DATOS insertado)
{
    myStruct *i = (myStruct*)insertado;
    myStruct *b = (myStruct*)a_buscar;
    return (b->letra == i->letra)?true:false;
}