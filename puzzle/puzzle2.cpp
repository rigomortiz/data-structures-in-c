#include "puzzle.h"
Puzzle::Puzzle( int numero, DATOS d, bool funcionOrdenamientoArista(DATOS nuevo, DATOS insertado, char tipo_orden), bool funcionOrdenamientoVertice(DATOS nuevo, DATOS insertado, char tipo_orden), Funcion funcionInsertarArista(DATOS d), Funcion funcionInsertarVertice(DATOS d))
{
    //DATOS Vertice
    int numero_de_la_casilla[numero]= {3, 11, 13, 4, 5, 9, 1, 10, 12, 7, 2, 8, 6, 14, 15, 0};
    for (int i = 0; i < numero; i++){
        this->datosVertice[i].bloqueado = false;
        this->datosVertice[i].en_lugar_correcto = false;
        this->datosVertice[i].numero_de_la_casilla = numero_de_la_casilla[i];
    }
    //DATOS Arista
    //char horientacion[] = { 'h', 'v', 'h', 'v', 'h', 'v', 'v', 'h', 'v', 'h', 'v', 'h', 'v', 'v', 'h', 'v', 'h', 'v', 'h', 'v', 'v', 'h', 'h', 'h' };
    for (int i = 0; i < 48; i++){
        this->datosArista[i].bloqueado = false;
        this->datosArista[i].direccion = 'n';
        this->datosArista[i].horientacion = 'n';
        this->datosArista[i].numero_transito = 0;
    }
    //Struct E Aristas
    int verticeA[] = { 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 13, 13, 14, 14, 14, 15, 15, 15, 16, 16 };
    int verticeB[] = { 2, 5, 1, 3, 6, 2, 4, 7, 3, 8, 1, 6, 9, 2, 5, 7, 10, 3, 6, 8, 11, 4, 7, 12, 5, 10, 13, 6, 9, 11, 14, 7, 10, 12, 15, 8, 11, 16, 9, 14, 10, 13, 15, 11, 14, 16, 12, 15 };
    for (int i = 0; i < 48; i++){
        this->e[i].direccion = 'b';// b|l|r
        this->e[i].verticeA = verticeA[i];
        this->e[i].verticeB = verticeB[i];
        //DATOS que se guarda en la arista
        this->e[i].dato = &datosArista[i];
        this->e[i].bloqueada = false;
    }
    //Struct V vertices
    int numeroAristas[] = { 2, 3, 3, 2, 3, 4, 4, 3, 3, 4, 4, 3, 2, 3, 3, 2 };
    for (int i = 0; i < numero; i++){
        this->v[i].numeroAristas = numeroAristas[i];
        this->v[i].vertice = i + 1;
        //DATOS que se guarda en el vertice
        this->v[i].dato = &datosVertice[i];
        this->v[i].bloqueada = false;
        this->v[i].distaciaHaciaEl = 0;
    }

    //Se crear el grafo que modela el puzzle 
    this->g.crear(this->v, this->e, numero, NULL, funcionOrdenamientoArista, funcionOrdenamientoVertice, funcionInsertarArista, funcionInsertarVertice);
}

void Puzzle::imprimirVertices(Funcion funcionMostrarListaVertice(DATOS d, int respuesta))
{
    this->g.imprimirVertices(funcionMostrarListaVertice);

    Vertice *v = (Vertice*)this->g.getVertice(3);
    V *vs = (V*)v->pdatos;
    printf("numero vertice %d", vs->vertice);
}

int Puzzle::buscar()
{
    
}

Puzzle::~Puzzle()
{
	
} 


bool funcionBuscarLista(DATOS d, DATOS a_buscar)
{
	
    //Datos d es el dato almacenado en la lista
    Vertice *s = (Vertice*)d;
    V *v = (V*)s->pdatos;
    DatosVertice *dVertice = (DatosVertice*)v->dato;
    /**********************************************/
    DatosVertice *datoBuscar = (DatosVertice*)a_buscar;

    return (dVertice->numero_de_la_casilla == datoBuscar->numero_de_la_casilla) ? true : false;
}

void Puzzle::camino(int a, int b)
{
    this->g.camino(a, b);
}