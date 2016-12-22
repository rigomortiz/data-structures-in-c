
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
    this->nodo_raiz = new Nodo(1, 0, nodo, NULL);
    this->d = arbol;
    this->numero_nodos = 0;
}

void Arbol::nuevoArbol(DATOS arbol, DATOS nodo)
{
    this->nodo_raiz = new Nodo(1, 0, nodo, NULL);
    this->d = arbol;
    this->numero_nodos = 0;
}
//==============================================================================
void Arbol::insertarNodo(int nodo, int nodo_padre, DATOS datos_nodo,  DATOS datos_rama)
{    
    Nodo *Nodo_a_buscar = new Nodo(nodo_padre, -1, NULL, NULL);
    Nodo *Nodo_padre = this->buscarAnchura( Nodo_a_buscar, funcionBuscarNodo);
    
    if(Nodo_padre != NULL){
        //insertar
        Nodo *Nodo_nuevo = new Nodo(nodo, nodo_padre, datos_nodo, datos_rama);
        Nodo_padre->insertarSubNodos(Nodo_nuevo);
        this->numero_nodos++;
        
        printf("Nodo Padre:   ");
        printf("Nodo: %d; Numero de Sub Nodos: %d\n",Nodo_padre->getNodo(), Nodo_padre->numeroNodos());
        printf("\tNodo hijo:\n");
        printf("\tNodo: %d; Numero de Sub Nodos: %d\n",Nodo_nuevo->getNodo(), Nodo_nuevo->numeroNodos());
    }else
        printf("\nEl nodo: %d no se encuentra.\n", nodo_padre);
    
    //nodo->insertarSubNodos(nodo_nuevo);
    //this->Nodos.insertar(nodo_nuevo);
        
}

Nodo* Arbol::buscarAnchura( ListaDoble *listaNodos, DATOS a_buscar, bool funcionBuscarNodo(DATOS a_buscar, DATOS insertado))
{
    Nodo **Nodos_matriz;
    Nodo *Nodo_encontrado;
    Nodo *nodo;
    int encontrado = 0;
    ListaDoble *l_nodos = new ListaDoble();
    //Se busca en los demás nodos
    for(int j = 0; j < listaNodos->Nelementos(); j++)
    {   nodo = (Nodo*)listaNodos->getStructIndex(j); 
        if(nodo->numeroNodos())
        {
            Nodos_matriz = nodo->getNodos();
            for(int i = 0; i < nodo->numeroNodos(); i++)
            {
                if(funcionBuscarNodo(a_buscar, Nodos_matriz[i]))
                {
                    Nodo_encontrado = Nodos_matriz[i];
                    encontrado = 1;
                    break;
                }
                if(Nodos_matriz[i]->numeroNodos()>0)
                    l_nodos->insertar( Nodos_matriz[i]);
            }
        }
    }
    
    if(encontrado)
        return Nodo_encontrado;
    else if(l_nodos->Nelementos())
        return this->buscarAnchura(l_nodos, a_buscar, funcionBuscarNodo);
    else 
        return NULL;
    delete l_nodos;
        
}

Nodo* Arbol::buscarAnchura( DATOS a_buscar, bool funcionBuscarNodo(DATOS a_buscar, DATOS insertado))
{
    Nodo **Nodos_matriz, *Nodo_encontrado = NULL;
    ListaDoble *listaNodos = new ListaDoble();
    
    //Se busca en la raiz
    if(funcionBuscarNodo(a_buscar, this->nodo_raiz))
        return this->nodo_raiz;
    else{
        //Se busca en los demás nodos
        if(this->nodo_raiz->numeroNodos()){
            //Se busca en los demás nodos
            Nodos_matriz = this->nodo_raiz->getNodos();
            for(int j = 0; j < this->nodo_raiz->numeroNodos(); j++){
                if(funcionBuscarNodo(a_buscar, Nodos_matriz[j])){
                    Nodo_encontrado  = Nodos_matriz[j];
                    break;
                }
                if(Nodos_matriz[j]->numeroNodos()>0)
                    listaNodos->insertar(Nodos_matriz[j]);
            }
           
        }
    }
    
    if(Nodo_encontrado != NULL)
        return Nodo_encontrado;
    else if(listaNodos->Nelementos())
        return this->buscarAnchura(listaNodos, a_buscar, funcionBuscarNodo);
    else 
        return NULL;
    delete listaNodos;
}

void Arbol::mostrarProfundidad(Nodo *nodo, void mostrarArbol(DATOS,int))
{
    if(nodo->numeroNodos() == 0)//Si el número de sub-nodos es 0 
    {
    }else{
        Nodo **SubNodosArray = (Nodo**)nodo->getNodos();
        for(int i = 0; i < nodo->numeroNodos(); i++){
            this->mostrarProfundidad(SubNodosArray[i]->getPntNodo(), mostrarArbol);
            printf("Nodo %d", SubNodosArray[i]->getNodo());
            mostrarArbol(SubNodosArray[i]->getDatos(),1);
        }
        
    }
}

void Arbol::mostrarProfundidad(void mostrarArbol(DATOS,int))
{
    if(this->nodo_raiz->numeroNodos() == 0)//Si la raíz no tiene nodos
    {
        printf("\nArbol vacio.\n");
    }else{
        this->mostrarProfundidad(this->nodo_raiz, mostrarArbol);//Muestra el arbol en profundidad
        mostrarArbol(this->nodo_raiz->getDatos(), 1);//Muestra al último el nodo raíz
    }
}

void Arbol::mostrarArchura(ListaDoble *listaNodos,void mostrarArbol(DATOS,int) )
{
    printf("<<1>>");
    Nodo **Nodos_matriz;
    ListaDoble *l_nodos = new ListaDoble();
    Nodo **nodos;
    
    if(listaNodos->Nelementos()){
        //Se busca en los demás nodos
        Nodos_matriz = (Nodo**)listaNodos->mostrar();
        for(int i = 0; i < listaNodos->Nelementos(); i++ ){
            nodos = (Nodo**)Nodos_matriz[i]->getNodos();
            for(int j = 0; j < nodos[i]->numeroNodos(); j++){
                mostrarArbol(nodos[j]->getDatos(), 1);
                if(nodos[j]->numeroNodos())
                    l_nodos->insertar(nodos[j]);
            }
            this->mostrarArchura(l_nodos, mostrarArbol);
        }
    }
    delete l_nodos;
}

void Arbol::mostrarAnchura(void mostrarArbol(DATOS d, int r))
{
    Nodo **Nodos_matriz = (Nodo**)this->nodo_raiz->getNodos();
    ListaDoble *listaNodos = new ListaDoble();
    int n = this->nodo_raiz->numeroNodos();
    //Imprime la raíz
    mostrarArbol(this->nodo_raiz->getDatos(), 1);
    if(n){
        for(int j = 0; j < n; j++){
            printf("<%d>", Nodos_matriz[j]->numeroNodos());
            mostrarArbol(Nodos_matriz[j]->getDatos(), 1);
            
            //if(Nodos_matriz[j]->numeroNodos()>0)
              listaNodos->insertar(Nodos_matriz[j]);
            
        }
        //printf("<<2>>");
        this->mostrarArchura(listaNodos, mostrarArbol);
    }
    
    delete listaNodos;
}


int Arbol::getNumeroNodos(){
    return this->numero_nodos;
}
/*
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
 * 
DATOS** Arbol::getSubNodos(int n){
    Nodo *nodo = (Nodo*)this->Nodos.getStructIndex(n - 1);
    return (DATOS**)nodo->getNodos();
}

int Arbol::getNumeroSubNodos(int n){
    Nodo *nodo = (Nodo*)this->Nodos.getStructIndex(n -1);
    return nodo->numeroNodos();
}



bool Arbol::isHoja(int n){
    Nodo *nodo = (Nodo*)this->Nodos.getStructIndex(n - 1);
    return nodo->numeroNodos()?true:false;
}

int Arbol::eliminarNodo(int n){
    Nodo *nodo = (Nodo*)this->getNodo(n);
    Nodo *np = (Nodo*)this->getNodo(nodo->getNodoPadre());
    printf("\nSe eliminará el nodo: %d", n);
    this->vaciarArbol(nodo, np);
}





int Arbol::vaciarArbol(Nodo *nodo, Nodo* nodo_padre)
{
    Nodo **sub_nodos;
    int numeroElementos;
    getchar();
    
    printf("\nNodo:%d elementos: %d padre: %d", nodo->getNodo(), nodo->numeroNodos(), nodo_padre->getNodo() );
    numeroElementos = nodo->numeroNodos();
    if( numeroElementos == 0)
    {
        
        if( nodo_padre->eliminarSubNodo(nodo, funcionEliminarNodo)){
        }else printf("\nNo se pudo eliminar el nodo %d", nodo->getNodo());
        printf("\nNodo eliminado %d", nodo->getNodo());
        printf("\nNodo padre %d numero nodos: %d", nodo_padre->getNodo(), nodo_padre->numeroNodos());
        this->Nodos.eliminar(nodo->getNodo()-1);
        delete nodo;
    }
    else
    {
        sub_nodos = (Nodo**)nodo->getNodos();
        while(  numeroElementos > 0 )//1//1
        {
            printf("\nNodo %d padre %d elementos %d;", sub_nodos[0]->getNodo(), nodo->getNodo(), numeroElementos);
            this->vaciarArbol(sub_nodos[0], nodo );
            printf("\nEliminar nodo: %d ; nodo padre: %d. ", sub_nodos[0]->getNodo(), sub_nodos[0]->getNodoPadre());
            sub_nodos = (Nodo**)nodo->getNodos();
            numeroElementos = nodo->numeroNodos();
        }
    }
}
int Arbol::vaciarArbol()
{
    Nodo *nodo;
    if(this->getNumeroNodos()==0){
        printf("Arbol vacio.\n");
    }else{
       // vaciarArbol(1); 
        this->Nodos.vaciar();
        this->nodo_raiz = NULL;
    }
}
*/
//==============================================================================
Arbol::~Arbol()
{
    delete this->nodo_raiz;
}

bool funcionEliminarNodo(DATOS a_eliminar, DATOS insertado)
{
    
    Nodo *i = (Nodo*)insertado;
    Nodo *n = (Nodo*)a_eliminar;
    return ( i->getNodo() == n->getNodo() )?true:false;
}

bool funcionBuscarNodo(DATOS a_buscar, DATOS insertado)
{
    
    Nodo *i = (Nodo*)insertado;
    Nodo *n = (Nodo*)a_buscar;
    
    return ( i->getNodo() == n->getNodo() )?true:false;
}
/*
ARBOL 
*->(Nodo 1)
|\
| \.--(Nodo 2)
|  |\
|  | \_:~{Nodo 5}
|  |\
|  | \_:~{Nodo 6}
|   \
|    \_:~{Nodo 7}
|\
| \.--(Nodo 3)
|  |\
|  | \_:~{Nodo 8}
|   \
|    \_:~{Nodo 9}
 \ 
  \.--(Nodo 4)
   \
    \.--(Nodo 10)
     \
      \.--(Nodo 11)
       |\
       | \_:~{Nodo 12}
        \ 
         \_:~{Nodo 13}

PUZZLE
 ================
|[01][02][03][04]|
|[05][06][07][08]|
|[09][10][11][12]|
|[13][14]    [15]|
 ================
 
 
 
 GRAFO
  
  (01)--->(02)----(03)----(04)
   |       |       ^       |
   |       V       |       |
  (05)----(06)--->(07)----(08)
   |       |       |       |
   |       |       |       |
  (09)----(10)----(11)----(12)
   |       |       |       |
   |       |       |       |
  (13)----(15)----(15)----(16)
  
  
 * 
 *
  */                   