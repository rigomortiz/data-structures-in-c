#include "grafo.h"
Grafo::Grafo()
{

}
Grafo::Grafo(V v[], E e[], int numero_vertices, DATOS d)
{
    this->crear(v, e, numero_vertices, d);
}
void Grafo::crearMatriz()
{
    int numeroVertices = this->getNumeroVertices();
    
    /*============================================================================*/
    //Crear la matriz M = G(v(), e())
    this->Matriz = (int**)malloc(sizeof(int*)* numeroVertices);
    for (int i = 0; i < numeroVertices; i++){
            this->Matriz[i] = (int*)malloc(sizeof(int)* numeroVertices);
            for (int j = 0; j < numeroVertices; j++)
                    this->Matriz[i][j] = 0;
    }
    /*____________________________________________________________________________ 
      ============================================================================*/
}

void Grafo::crear(V v[], E e[], int numero_vertices, DATOS d)
{
    this->pdatos = d;//se guarda d en pdatos, que es el puntero DATOS que almacena el grafo
    int k = 0;
    Vertice *vertice;//puntero de tipo Vertice que es una clase
    Vertice *verticeTmp;
    Arista *arista, *new_arista;
    int cont =0;
    /*============================================================================*/
    // Se crean los vertices de forma dinamica
    for(int i = 0; i < numero_vertices; i++)
    {
        vertice = new Vertice(v[i].vertice, v[i].numeroAristas, v[i].bloqueado,v[i].distaciaHaciaEl, v[i].dato);// Nuevo objeto tipo Vertice(Clase))
        //printf("\nVertice %d creado.", v[i].vertice);
        for (int j = 0; j < v[i].numeroAristas; j++){
            arista = new Arista( e[cont].verticeB, e[cont].direccion, e[cont].bloqueada, e[cont].tamanio, e[cont].dato);
            vertice->setArista(arista);
            //printf("\n\tArista %d creado.", e[cont].verticeB);
            cont++;
        }
        //vertice->imprimir();
        vertice->crearListaIndexada();
        this->setVertice(vertice);
    }
    /*____________________________________________________________________________ 
      ============================================================================*/
    this->Vertices.crearListaIndexada();
    //Se crean los demás aristas para completar el grafo
    for(int i = 1; i <= numero_vertices; i++){
        vertice = (Vertice*)this->getVertice(i);//retorna cada veŕtice 
        for(int j=1; j<= vertice->getNumeroAristas(); j++){
            arista = (Arista*)this->getArista(i,j);//retorna cada arista de cada vértice
            if(arista != NULL)
            {
                new_arista = new Arista(vertice->getVertice(), arista->getDireccion(), arista->getBloqueada(), arista->getTamanio(), arista->getDatos() );
                verticeTmp = (Vertice*)this->getVertice(arista->getVerticeB());
                
                if(!verticeTmp->aristaEncontrada(new_arista)){
                    verticeTmp->setArista(new_arista);
                    verticeTmp->setNumeroAristas(verticeTmp->getNumeroAristas()+1);
                }
                verticeTmp->crearListaIndexada();
            }
            
        }
    }
}

void Grafo::imprimir()
{
    Vertice *vertice = NULL;
    Arista *arista = NULL;
    Arista **aristas;
    int i = 0, j = 0;
    printf("\nVERTICES\t\tARISTAS\n");
    //this->vertice, this->numeroAristas, this->bloqueado, this->distaciaHaciaEl, this->datos)
    printf("vertice, numAristas, bloqueado, dist, datos\n");
    printf("verticeB, direccion, bloqueada, tamaño, datos\n");//this->verticeA, this->verticeB, this->direccion, this->bloqueada, this->tamanio, this->datos

    for(int i = 1; i <= this->getNumeroVertices(); i++){
        vertice = (Vertice*)this->getVertice(i);
        vertice->imprimir();
        for(int j=1; j<= vertice->getNumeroAristas(); j++){
            arista = (Arista*)this->getArista(i,j);
            if(arista != NULL){
                arista->imprimir();
            }
            
        }
    }
    
}

void Grafo::CaminoAlgoritmoThread(int vertice1, int vertice2 )
{
    int contador = 0;
    ListaDoble listaCaminosMinimos;
    
    StructListaCaminos s;
    s.caminos = &listaCaminosMinimos;
    s.vertice = vertice1;
    
    //Crea una lista con los caminos minimos de vertice1 a vertice2 
    //listaCaminosMinimos.insertar(&s);
    this->camino.insertar(&s);
            
    printf("\nCaminos minimos \n");
    this->caminoRecursivo( vertice1, vertice2, &listaCaminosMinimos);
    //imprimirCamino(&listaCaminosMinimos);
    
    //return (ListaDoble)listaCaminosMinimos;
}
void Grafo::imprimirCamino2(ListaDoble *l)
{
//    StructListaCaminos **c, **c2;
//    ListaDoble *ls;
//    ls = l; 
//    
//    while(l != NULL)
//    {
//        c = (StructListaCaminos**)ls->mostrar(); 
//        
//       if(c != NULL){
//            for(int i=0;i< l->Nelementos(); i++)
//            {
//                printf("%d",c[i]->vertice);
//                this->imprimirCamino2(c[i]->caminos);
//                //imprimirCamino2(c[i]->caminos);
//            }
//        }else printf("[null]\n");
//       l = c[]->caminos;
//    }
    
}
void Grafo::imprimirCamino(){
    /*¿¿
    StructListaCaminos **nodo, **sub_nodo;
    ListaDoble *lista = this->camino;
    if(nodo != NULL ){
       // lista = (ListaDoble*)nodo->caminos;
        //printf("%d --> ",nodo->vertice);
        while(lista != NULL){
            sub_nodo = lista->mostrar();
            for(int i = 0; i< lista->Nelementos(); i++){
               printf("%d --> ", sub_nodo->vertice); 
            }
            printf("\n");
            
            lista = sub_nodo->caminos;
        }
        
    }else printf("NULL\n");
    StructListaCaminos **c, **c2;
    c = (StructListaCaminos**)l->mostrar();
    if(c != NULL){
        printf("[");
        for(int i=0;i< l->Nelementos(); i++)
        {
            printf(" %d ",c[i]->vertice);
        }printf("]\n");
        
    }//printf("[null]\n");
    */
}
pthread_mutex_t mutex[16];
void Grafo::caminoRecursivo(int v1, int v2, ListaDoble *listaCamino)
{
    //Hilos
    pthread_t *aPthread;//Puntero de thread 
    thread_parametros *pt;//puntero de parametros de thread
    
    //mutex = (pthread_mutex_t**)calloc(this->getNumeroVertices(), sizeof(pthread_mutex_t));
    //mutex = (pthread_mutex_t**)malloc(sizeof(pthread_mutex_t*)* this->getNumeroVertices());
    
    for(int i = 0; i < getNumeroVertices(); i++)
       pthread_mutex_init(&mutex[i], NULL);
    
    //Vertices y Aristas
    Vertice *vertice1 = NULL;
    Vertice *v = NULL;
    Arista *arista = NULL;
    int jeneracion = 0;//variable que sirve para contar la jeneracion
    int contadorAristas = 0;
    int *aristasNoBloqueadas;
    
    //Lista de caminos minimos
    StructListaCaminos *datosCaminos;
    
    vertice1 = (Vertice*)this->getVertice(v1);//Se crea el vertice1
    aristasNoBloqueadas = (int*)calloc(vertice1->getNumeroAristas(), sizeof(int));//Donde se almacenan los vertices
    datosCaminos = (StructListaCaminos*)calloc(vertice1->getNumeroAristas(), sizeof(StructListaCaminos));//Se crea una estructura para
                                                                                                        //los caminos
    
    vertice1->setBloqueado(true);//se bloquea el vertice actual
    printf("\nvertice, numAristas, bloqueado, dist, datos");
    //vertice1->imprimir();
    this->imprimirCamino();
    //Cuenta cuantas aristas no estan bloquedas
    for(int i = 1; i <= vertice1->getNumeroAristas(); i++ ){
        arista = (Arista*)vertice1->getArista(i);//se obtiene la arista
        v = (Vertice*)this->getVertice(arista->getVerticeB());//Se obtiene el siguiente vertice
        if( !v->getBloqueado() )//Si se encuentra desbloqueado el vertice
        {
            aristasNoBloqueadas[contadorAristas] = v->getVertice();//se agrega al array
            v->setDistaciaHaciaEl(jeneracion + 1);//Se incrementa el numero de jeneracion
            //Bloquear arista 
            datosCaminos[contadorAristas].caminos = new ListaDoble();//Se crea una Lista
            datosCaminos[contadorAristas].vertice = v->getVertice();
            listaCamino->insertar(&datosCaminos[contadorAristas]);//Se inserta en la lista
            contadorAristas++;
        }
    }
    
    //Crea los hilos de pendiendo del numero de aristas
    if(contadorAristas > 0)
    {
        aPthread = (pthread_t*)calloc(contadorAristas, sizeof (pthread_t));//Se crean los threads
        pt = (thread_parametros*)calloc(contadorAristas, sizeof(thread_parametros));//Se crean los parametros de los threads
        
        //Se da valor a los atributos de los threads
        for(int i = 0; i < contadorAristas; i++){
            getDatosThread(&pt[i],aristasNoBloqueadas[i],v2,jeneracion+1,&datosCaminos[i],v,
                    (Vertice*)this->getVertice(aristasNoBloqueadas[i]),this, &mutex[aristasNoBloqueadas[i]-1]);
        }
        //Se crean los threads
        for(int i = 0; i < contadorAristas; i++){
            
            pthread_create(&aPthread[i], NULL, &funcionHilo, (void*)&pt[i]);//thread, parametros, funcion, atributos
        }
        //Se ejecutan los threads
        for(int i = 0; i < contadorAristas; i++)
            pthread_join(aPthread[i], NULL);
        //Se eliminan los threads
        for(int i = 0; i < contadorAristas; i++)
            pthread_exit(&aPthread[i]);
        
        free(pt);
        free(aPthread);
    }
    for(int i = 0; i<16; i++)
        pthread_mutex_destroy(&mutex[i]);
    
    free(aristasNoBloqueadas);
}

void *funcionHilo(void *pthread)
{
    getchar();
    //Threads
    pthread_t *aPthread;//Puntero de hilos  
    thread_parametros *pt; 
    thread_parametros *p = (thread_parametros*)pthread;//puntero de parametros de hilo
    //Vertices y Aristas
    Vertice *vertice = (Vertice*)p->yo, *vtmp;//Clase Vertice
    
    Arista *arista = NULL;
    int contadorAristas = 0, *aristasNoBloqueadas;
    StructListaCaminos *datosCaminos;
    int cont = 0;
    bool crearThreads = true;
   
    
    aristasNoBloqueadas = (int*)calloc(vertice->getNumeroAristas(), sizeof(int));//Se crea el arreglo de aristas
    datosCaminos = (StructListaCaminos*)calloc(vertice->getNumeroAristas(), sizeof(StructListaCaminos));// Se crea la estructura 
    //para los datos en la lista
    
    p->g->imprimirCamino();
    pthread_mutex_lock(p->mutex_acceso);//semaforo 
    vertice->setBloqueado(true);//Se bloquea el vertice para que otro hilo no lo utilice
    vertice->imprimir();
    for(int i = 1; i <= vertice->getNumeroAristas(); i++ ){
        arista = (Arista*)vertice->getArista(i);//Se crea una arista
        vtmp = (Vertice*)p->g->getVertice(arista->getVerticeB());//Se crea un vertice 
        
        if( !vtmp->getBloqueado() ){
           //Se analiza el camino minimo
            if(p->vertice2 == vtmp->getVertice()){
                //printf("encontrado: %d", p->jeneracion+1);
                //vtmp->imprimir();
               crearThreads = false;
            }else{
                if( p->jeneracion + 1 <= vtmp->getDistaciaHaciaEl() || vtmp->getDistaciaHaciaEl() == 0 ){
                    aristasNoBloqueadas[contadorAristas] = vtmp->getVertice();
                    vtmp->setDistaciaHaciaEl(p->jeneracion+1);
                    datosCaminos[contadorAristas].caminos = new ListaDoble();
                    datosCaminos[contadorAristas].vertice = vtmp->getVertice();
                    p->listaVerticesHijos->caminos->insertar(&datosCaminos);//Se inserta en la lista
                    contadorAristas++;
                }else{
                    //p->listaVerticesHijos = NULL;
                }
            }
        }else{
            //p->listaVerticesHijos = NULL;
        }
    }
    pthread_mutex_unlock(p->mutex_acceso);
    
    //printf("Numero de aristas Total: %d\n", contadorAristas);
    if(contadorAristas > 0 && crearThreads){
        aPthread = (pthread_t*)calloc(contadorAristas, sizeof (pthread_t));
        pt = (thread_parametros*)calloc(contadorAristas, sizeof(thread_parametros));
        for(int i = 0; i < contadorAristas; i++)
        {   
            getDatosThread(&pt[i],aristasNoBloqueadas[i],p->vertice2,p->jeneracion+1,&(datosCaminos[i]),vertice,
                    (Vertice*)p->g->getVertice(aristasNoBloqueadas[i]),p->g, &mutex[aristasNoBloqueadas[i]-1] );
        }
        for(int i = 0; i< contadorAristas; i++){
            pthread_create(&aPthread[i], NULL, &funcionHilo, (void*)&pt[i]);
        }
        
        for(int i = 0; i< contadorAristas; i++){
            pthread_join(aPthread[i], NULL);
        }
        
        for(int i = 0; i< contadorAristas; i++){	
            pthread_exit(&aPthread[i]);
        }
        free(pt);
        free(aPthread);
        
    }
    
    
    free(aristasNoBloqueadas);
    return 0;
}
   
void getDatosThread(thread_parametros *datos, int vertice1, int vertice2, int jeneracion, StructListaCaminos *camino,
        Vertice *padre, Vertice *yo, Grafo *g, pthread_mutex_t *mutex)
{
    datos->vertice1 = vertice1;
    datos->vertice2 = vertice2;
    datos->jeneracion = jeneracion;
    datos->listaVerticesHijos = camino;
    datos->padre = padre;
    datos->yo = yo;
    datos->g = g;
    datos->mutex_acceso = mutex;
}

/*************************************************************
FUNCIONES GRAFO
/************************************************************/

bool funcionOrdenamientoVertice(DATOS nuevo, DATOS insertado, char t)
{
    Vertice *i, *n;
    i = (Vertice*)insertado;
    n = (Vertice*)nuevo;
    return ((t == 'a' && n->getVertice() <= i->getVertice()) || (t == 'd' && n->getVertice() >= i->getVertice())) ? true : false;
    
}
bool funcionOrdenamientoArista(DATOS nuevo, DATOS insertado, char t)
{
    Arista *i = (Arista*)insertado;
    Arista *n = (Arista*)nuevo;
    return ((t == 'a' && n->getVerticeB() <= i->getVerticeB()) || (t == 'd' && n->getVerticeB() >= i->getVerticeB() )) ? true : false;
}
void funcionInsertarArista(DATOS datosNuevos)
{
    Arista *s = (Arista*)datosNuevos;
    printf("Arista insertada:\t q%d <-->  .\n", s->getVerticeB());
}
void funcionMostrarListaArista(DATOS d, int respuesta)
{
    if (respuesta) {
        Arista *s = (Arista*)d;
        printf("(VB: %d, Tam: %d, Dir: %c, Bloqueada: %d) --> ", s->getVerticeB(), s->getTamanio(), s->getDireccion(), s->getBloqueada() );
    }
    else
        printf("\nLista vacia.\n");
}
void funcionInsertarVertice(DATOS datosNuevos)
{
    Vertice *s = (Vertice*)datosNuevos;
    printf("Vertice insertados: q%d, # aristas: %d .\n", s->getVertice() , s->getNumeroAristas());
}
void funcionMostrarListaVertice(DATOS d, int respuesta)
{
    if (respuesta) {
        Vertice *vertice = (Vertice*)d;
        printf("( q%d, #Aristas: %d, Bloqueado: %d) --> ", vertice->getVertice(), vertice->getNumeroAristas(), vertice->getBloqueado());
    }
    else
        printf("\nLista vacia.\n");
}
/*============================================================================*/