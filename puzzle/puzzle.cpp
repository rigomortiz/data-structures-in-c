#include "puzzle.h"
Puzzle::Puzzle( int numero_vertices,int digitos[], DATOS d)
{
    
    numero_vertices = 16;
    int numero_aristas = 24;
    
    //Se asigna memoria de forma dinamica
    this->e = (E*)calloc(numero_aristas, sizeof(E));
    this->v = (V*)calloc(numero_vertices, sizeof(V));
    this->datosVertice = (DatosVertice*)calloc(numero_vertices, sizeof(DatosVertice));
    this->datosArista = (DatosArista*)calloc(numero_aristas, sizeof(DatosArista));
    
    /*============================================================================*/
    //Estructuras para poder resolver el puzzle 
    //DATOS Vertice: se uttiliza para saber el estado de cada vertice
    for (int i = 0; i < numero_vertices; i++){
        this->datosVertice[i].bloqueado = false;
        this->datosVertice[i].en_lugar_correcto = false;
        this->datosVertice[i].numero_de_la_casilla = digitos[i];
    }
    //DATOS Arista: se utiliza para saber el estado de cada arista
    for (int i = 0; i < numero_aristas; i++){
        this->datosArista[i].bloqueado = false;
        this->datosArista[i].numero_transito = 0;
    }
    /*____________________________________________________________________________ 
      ============================================================================*/
    
    /*============================================================================*/
    //Estructuras para modelizar el puzzle en forma de un grafo matemático G(V,E)
    //Struct E Aristas: para crear las aristas del grafo
    int verticeA[] = { 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6,  7,  7,  8,  9, 9,  10, 10, 11, 11, 12, 13, 14, 15 };
    int verticeB[] = { 2, 5, 3, 6, 4, 7, 8, 6, 9, 7, 10, 8, 11, 12, 10, 13, 11, 14, 12, 15, 16, 14, 15, 16 };
    for (int i = 0; i < numero_aristas; i++){
        this->e[i].direccion = 'b';// b:bidirectional|l:left|r:right
        //conexiones de vertices para esa arista
        this->e[i].verticeB = verticeB[i];
        this->e[i].dato = &datosArista[i];//DATOS que se guarda en la arista
        this->e[i].bloqueada = false;
        this->e[i].tamanio = 1;
    }
    
    //Struct V vertices: para crear los vertices del grafo G
    int numeroAristas[] = { 2, 2, 2, 1,
                            2, 2, 2, 1, 
                            2, 2, 2, 1, 
                            1, 1, 1, 0 };
    for (int i = 0; i < numero_vertices; i++){
        this->v[i].numeroAristas = numeroAristas[i];
        this->v[i].vertice = i + 1;
        //DATOS que se guarda en el vertice
        this->v[i].dato = &datosVertice[i];
        this->v[i].bloqueado = false;
        this->v[i].distaciaHaciaEl = 0;
    }
    /*____________________________________________________________________________
      ============================================================================*/
    
    //Se crear el grafo que modela el puzzle 
    this->g.crear(this->v, this->e, numero_vertices, NULL);
}

void Puzzle::imprimirGrafo()
{
    this->g.imprimir();
}

void Puzzle::camino(int a, int b)
{
    this->g.CaminoAlgoritmoThread(a, b);
}


Puzzle::~Puzzle()
{
	
} 

/*
bool funcionBuscarLista(DATOS d, DATOS a_buscar)
{
	
    //Datos d es el dato almacenado en la lista
    Vertice *s = (Vertice*)d;
    V *v = (V*)s->pdatos;
    DatosVertice *dVertice = (DatosVertice*)v->dato;
    //*********************************************
    DatosVertice *datoBuscar = (DatosVertice*)a_buscar;

    return (dVertice->numero_de_la_casilla == datoBuscar->numero_de_la_casilla) ? true : false;
}
*/