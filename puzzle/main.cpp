/* 
 * File:   main.cpp
 * Author: regoeco-debian
 *
 * Created on 20 de septiembre de 2015, 03:13 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "puzzle.h"

using namespace std;
int main(int argc, char** argv)
{
    //crear el grafo que modela el puzzle
    int numero_de_la_casilla[]= {3, 11, 13, 4, 5, 9, 1, 10, 12, 7, 2, 8, 6, 14, 15, 0};
    Puzzle p(16, numero_de_la_casilla, NULL);
    p.imprimirGrafo();
    
    //p.camino(6, 16);
    //printf("\nnuevo");
    //p.imprimirGrafo();
    
    getchar();
    return 1;
}
