/* 
 * File:   puzzle.h
 * Author: regoeco-debian
 *
 * Created on 20 de septiembre de 2015, 04:11 PM
 */
#ifndef PUZZLE_H
#define	PUZZLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include "grafo.h"


#ifdef	__cplusplus
extern "C" {
#endif
    /*============================================================================*/

    typedef struct{
            int numero_de_la_casilla;// n
            bool en_lugar_correcto;//true|false
            bool bloqueado;//true|false
    }DatosVertice;

    typedef struct{
            int numero_transito;// n
            char direccion;//u|d|r|l|n
            bool bloqueado;//true|false 
    }DatosArista;

    typedef void *DATOS;//Datos a almacenar
    /*____________________________________________________________________________
    ============================================================================*/
    //bool funcionBuscarLista(DATOS d, DATOS a_buscar);
	
#ifdef	__cplusplus
}
#endif

class Puzzle 
{
private:
    V *v;
    E *e;
    DatosVertice *datosVertice;
    DatosArista *datosArista;
    int numeroCasillas;
    Grafo g;
    /*____________________________________________________________________________
    ============================================================================*/
public:
    //Lista lista = valor1;
    Puzzle( int numero, int digitos[], DATOS d);
    ~Puzzle();
    /*============================================================================*/
    void imprimirGrafo();
    void camino(int a, int b);
    /*____________________________________________________________________________
    ============================================================================*/
};
#endif	/* PUZZLE_H */

