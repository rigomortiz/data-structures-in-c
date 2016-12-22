//Estructura lista doble enlace
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
typedef struct{
    int numero;
    char letra;
    float flotante;
}D;
void funcionInsertar(DATOS d);
void funcionMostrar(DATOS datos_a_imprimir, int respuesta);
bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char t);
bool funcionBuscar(DATOS d, DATOS a_buscar);
bool funcionBuscarALL(DATOS d, DATOS a_buscar);
bool funcionEliminar(DATOS d, DATOS a_eliminar);
bool funcionEliminarAll(DATOS d, DATOS a_eliminar);

int main(int argc, char** argv)
{
    char x;
    ListaDoble ld('a');
    D d[7], *dtmp, dato_a_buscar, dato_eliminar, **buscarAll;
    int i =0;
    d[0].numero = 1; d[0].letra = 'a'; d[0].flotante = 23.212;
    d[1].numero = 2; d[1].letra = 'b'; d[1].flotante = 121.2;
    d[2].numero = 3; d[2].letra = 'c'; d[2].flotante = 2.562;
    d[3].numero = 4; d[3].letra = 'd'; d[3].flotante = 54.23;
    d[4].numero = 5; d[4].letra = 'e'; d[4].flotante = 0.12;
    d[5].numero = 6; d[5].letra = 'f'; d[5].flotante = 0.12;
    d[6].numero = 7; d[6].letra = 'f'; d[6].flotante = 0.12;
    dato_a_buscar.numero  = 7; dato_a_buscar.letra = 'f'; dato_a_buscar.flotante = 0.12;
    dato_eliminar.letra = 'f';
    
    ld.mostrar(funcionMostrar);
    ld.insertarMultiple(funcionInsertar, funcionOrdenamiento, 7, &d[0], &d[1], &d[2], &d[3], &d[4], &d[5], &d[6]);
    ld.mostrar(funcionMostrar);
    if(ld.crearListaIndexada()){
        printf("\nSe creo la lista indexada:\n");
        dtmp = (D*)ld.getStructIndex(5);
        if(dtmp != NULL){
            printf("f:%f, l:%c, n:%d", dtmp->flotante, dtmp->letra, dtmp->numero);
        }else
            printf("\nIndice no permitido\n");
    }
    
    //Buscar Todos
    buscarAll = (D**)ld.buscarAll(&dato_a_buscar, funcionBuscar);
    while(buscarAll[i] != NULL){
         printf("\nEncontrado: %d, %f, %c\n", buscarAll[i]->numero, buscarAll[i]->flotante, buscarAll[i]->letra);
         i++;
    }
    /*
    if( (dtmp = (D*)ld.buscar(&dato_a_buscar, funcionBuscar)) != NULL){
        printf("\nEncontrado: %d, %f, %c\n", dtmp->numero, dtmp->flotante, dtmp->letra);
    }else 
        printf("\nno encontrado\n");
    */
   // printf("Eliminado: %d\n", ld.eliminar(&dato_eliminar, funcionEliminar));
    printf("Eliminados N: %d", ld.eliminarAll(&dato_eliminar, funcionEliminarAll));
    
    ld.mostrar(funcionMostrar);
    
    
    ld.vaciar() ? printf("1") : printf("0");
    ld.mostrar(funcionMostrar);
    scanf("%c", &x);
    return 1;
}
void funcionInsertar(DATOS datos_nuevos)
{
    D *d = (D*)datos_nuevos;
    printf("Datos insertados: %d, %c, %f.\n", d->numero, d->letra, d->flotante );
}
void funcionMostrar(DATOS datos_a_imprimir, int respuesta)
{
    if (respuesta) {
        D *d= (D*)datos_a_imprimir;
        printf("(%d, %c, %f ) ---> ", d->numero, d->letra, d->flotante);
    }
    else
        printf("\nLista vacia.\n");
}
bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char t)
{
    D *i = (D*)insertado;
    D *n = (D*)nuevo;
    //regla de ordenamineto
    return ((t == 'a' && n->flotante <= i->flotante) //ascendente
        || (t == 'd' && n->flotante >= i->flotante)) ? true : false; //descendente
}
bool funcionBuscar(DATOS d, DATOS a_buscar)
{
    //Datos d es el dato almacenado en la lista
    D *dato = (D*)d;
    /**********************************************/
    D *datoBuscar = (D*)a_buscar;

    return (dato->letra == datoBuscar->letra) ? true : false;
}
bool funcionBuscarAll(DATOS d, DATOS a_buscar)
{
    //Datos d es el dato almacenado en la lista
    D *dato = (D*)d;
    /**********************************************/
    D *datoBuscar = (D*)a_buscar;

    return (dato->letra == datoBuscar->letra) ? true : false;
}
bool funcionEliminar(DATOS d, DATOS a_eliminar)
{
    //Datos d es el dato almacenado en la lista
    D *s = (D*)d;
    D *s1 = (D*)a_eliminar;
    /**********************************************/

    return (s->letra == s1->letra) ? true : false;
}
bool funcionEliminarAll(DATOS d, DATOS a_eliminar)
{
    //Datos d es el dato almacenado en la lista
    D *s = (D*)d;
    D *s1 = (D*)a_eliminar;
    /**********************************************/

    return (s->letra == s1->letra) ? true : false;
}
