
/* 
 * File:   arbol.cpp
 * Author: regoeco-debian
 *
 * Created on 7 de octubre de 2015, 11:21 PM
 */
#include "arbol.h"
//==============================================================================
Arbol::Arbol(DATOS arbol, DATOS nodo)
{
    this->nodo_raiz = new Nodo(1, nodo, NULL);
    this->d = arbol;
    this->Nodos.insertar(this->nodo_raiz);
}

void Arbol::nuevoArbol(DATOS arbol, DATOS nodo)
{
    this->nodo_raiz = new Nodo(1, nodo, NULL);
    this->d = arbol;
    this->Nodos.insertar(this->nodo_raiz);
}

//==============================================================================
void Arbol::insertarNodo(int nodo_padre, DATOS datos_nodo,  DATOS datos_rama){
    if(this->Nodos.Nelementos() < nodo_padre){
        printf("\nEl nodo %d no se encuentra", nodo_padre);
    }else{
        Nodo *nodo = (Nodo*)this->Nodos.getStructIndex(nodo_padre - 1);
        Nodo *nodo_nuevo = new Nodo(this->Nodos.Nelementos()+1, datos_nodo, datos_rama);
        nodo->insertarSubNodos(nodo_nuevo);
        this->Nodos.insertar(nodo_nuevo);
    }
}

DATOS** Arbol::getSubNodos(int n){
    Nodo *nodo = (Nodo*)this->Nodos.getStructIndex(n - 1);
    return (DATOS**)nodo->getNodos();
}

int Arbol::getNumeroSubNodos(int n){
    Nodo *nodo = (Nodo*)this->Nodos.getStructIndex(n -1);
    return nodo->numeroNodos();
}

int Arbol::getNumeroNodos(){
    return this->Nodos.Nelementos();
}

bool Arbol::isHoja(int n){
    Nodo *nodo = (Nodo*)this->Nodos.getStructIndex(n - 1);
    return nodo->numeroNodos()?true:false;
}

int Arbol::eliminarNodo(int n){
    printf("Eliminar nodo %d\n", n);
    this->vaciarArbol(n);
    this->Nodos.eliminar(n-1);
}

void Arbol::mostrarArchura(int nodo,void mostrarArbol(DATOS d, int r) )
{
    Nodo **sub_nodos;
    
    if(this->getNumeroSubNodos(nodo)==0)//Si no tiene elementos imprime lo siguiente
    {
        mostrarArbol(NULL, 0);//imprime que es una hoja
    }
    else{
        sub_nodos = (Nodo**)this->getSubNodos(nodo);//Se obtiene todos los sub-nodos
        for(int i = 0; i < this->getNumeroSubNodos(nodo); i++)//Se imprime cada dub nodo
        {
            printf("\tNodo: %d", sub_nodos[i]->getNodo());
            mostrarArbol(sub_nodos[i]->getDatos(), 1);
        }
    }
}

void Arbol::mostrarAnchura(void mostrarArbol(DATOS d, int r))
{
    Nodo *nodo;
    
    if(this->nodo_raiz->numeroNodos() == 0)//Si la raíz no tiene nodos
        printf("Arbol vacio.\n");
    else{
        //Imprime raíz
        printf("Raiz: Nodo %d\n", this->nodo_raiz->getNodo());
        mostrarArbol(this->nodo_raiz->getDatos(), 1);
        //imprime todos los nodos 
        for(int j = 0; j < this->getNumeroNodos(); j++)
        {
            nodo = (Nodo*)this->Nodos.getStructIndex(j);//Se obtiene el nodo inicial 
            printf("Nodo %d :  nodos #: %d\n", nodo->getNodo(),  nodo->numeroNodos());
            this->mostrarArchura(j+1, mostrarArbol);
        }
    }
}

void Arbol::mostrarProfundidad(int nodo, void mostrarArbol(DATOS,int))
{
    Nodo **sub_nodos;
    Nodo *n;
    if(this->getNumeroSubNodos(nodo) == 0)//Si el número de sub-nodos es 0 
    {
    }else{
        sub_nodos = (Nodo**)this->getSubNodos(nodo);//Se obtienen todos los sub nodos
        for(int i = 0; i < this->getNumeroSubNodos(nodo); i++){
            this->mostrarProfundidad(sub_nodos[i]->getNodo(), mostrarArbol);
            mostrarArbol(sub_nodos[i]->getDatos(),1);
        }
        
    }
}

void Arbol::mostrarProfundidad(void mostrarArbol(DATOS,int))
{
    if(this->nodo_raiz->numeroNodos() == 0)//Si la raíz no tiene nodos
    {
        printf("Arbol vacio.\n");
    }else{
        this->mostrarProfundidad(1, mostrarArbol);//Muestra el arbol en profundidad
        mostrarArbol(this->nodo_raiz->getDatos(), 1);//Muestra al último el nodo raíz
    }
}

int Arbol::vaciarArbol(int nodo)
{
    Nodo **sub_nodos;
    Nodo *n;
    
    printf("Nodo: %d\n");
    if(this->getNumeroSubNodos(nodo) == 0)
    {
        n = (Nodo*)this->getNodo(nodo);
        n->eliminarRama();
        this->Nodos.eliminar(nodo-1);
        printf("nodo %d vacio num elementos: %d\n", n->getNodo(), n->numeroNodos() );
    }else
    {
        sub_nodos = (Nodo**)this->getSubNodos(nodo);
        printf("nodo %d, num elementos: %d\n", nodo, this->getNumeroSubNodos(nodo) );
        for(int i = 0; i < this->getNumeroSubNodos(nodo); i++){
            
            printf("\tnodo %d num elementos: %d\n", sub_nodos[i]->getNodo(), sub_nodos[i]->numeroNodos() );
            if(sub_nodos[i]->numeroNodos() == 0){
                n = (Nodo*)this->getNodo(nodo);
                n->eliminarSubNodo(i);
                delete sub_nodos[i];
            }else 
                 this->vaciarArbol(sub_nodos[i]->getNodo());
            //this->Nodos.eliminar(sub_nodos[i]->getNodo());
        }
        n = (Nodo*) this->Nodos.getStructIndex(nodo);
        n->eliminarSubNodos();
        printf("nodo %d num elementos: ,%d\n", n->getNodo(), n->numeroNodos() );
        this->Nodos.eliminar(n->getNodo());
    }
}
int Arbol::vaciarArbol()
{
    Nodo *nodo;
    if(this->getNumeroNodos()==0){
        printf("Arbol vacio.\n");
    }else{
        vaciarArbol(1); 
        this->Nodos.vaciar();
        this->nodo_raiz = NULL;
    }
}

//==============================================================================
Arbol::~Arbol()
{
    delete this->nodo_raiz;
    Nodo **nodos = (Nodo**)this->Nodos.mostrar();
    for(int j = 1; j< this->getNumeroNodos(); j++){
        delete nodos[j];
    }
}
