#include "grafo.h"
Grafo::Grafo()
{

}
Grafo::Grafo(V v[], E e[], int numero_vertices, DATOS d, bool funcionOrdenamientoArista(DATOS nuevo, DATOS insertado, char tipo_orden), bool funcionOrdenamientoVertice(DATOS nuevo, DATOS insertado, char tipo_orden), Funcion funcionInsertarArista(DATOS d), Funcion funcionInsertarVertice(DATOS d))
{
	this->crear(v, e, numero_vertices, d, funcionOrdenamientoArista, funcionOrdenamientoVertice, funcionInsertarArista, funcionInsertarVertice);
}

void Grafo::crear(V v[], E e[], int numero_vertices, DATOS d, bool funcionOrdenamientoArista(DATOS nuevo, DATOS insertado, char tipo_orden), bool funcionOrdenamientoVertice(DATOS nuevo, DATOS insertado, char tipo_orden), Funcion funcionInsertarArista(DATOS d), Funcion funcionInsertarVertice(DATOS d))
{
	this->pdatos = d;
	int k = 0;
	Vertice **Vertices;
	Vertice *vertice;
	E **es;
	V *ve;
	int numeroVertices;


	for (int i = 0; i < numero_vertices; i++)
	{
		vertice = new Vertice();// Nuevo objeto Vertice
		vertice->insertarDatos(&v[i]);// Insertar datos v en el vertice
		for (int j = 0; j < v[i].numeroAristas; j++){
			vertice->Aristas.insertar(&(e[k++]), funcionInsertarArista, funcionOrdenamientoArista);
		}
		this->Vertices.insertar(vertice, funcionInsertarVertice, funcionOrdenamientoVertice);
	}
	numeroVertices = this->Vertices.Nelementos();

	//Crear la matriz M = G(v(), e())
	this->Matriz = (int**)malloc(sizeof(int*)* numeroVertices);
	for (int i = 0; i < numeroVertices; i++){
		this->Matriz[i] = (int*)malloc(sizeof(int)* numeroVertices);
		for (int j = 0; j < numeroVertices; j++)
			this->Matriz[i][j] = 0;
	}

	/*
	 * Imprime los vertices 
	Vertices = (Vertice**)this->Vertices.mostrar();// se guardan en un array de punteros los vertices
	for (int i = 0; i < numeroVertices; i++){
		ve = (V*)(Vertices[i]->pdatos);// estructura de V de vertice i del array de punteros 
		printf("vertice: %d numero aristas: %d\n", ve->vertice, ve->numeroAristas);
		es = (E**)(Vertices[i]->Aristas.mostrar());
		for (int j = 0; j < Vertices[i]->Aristas.Nelementos(); j++){
			this->Matriz[es[j]->verticeA - 1][es[j]->verticeB - 1] = 1;
			this->Matriz[es[j]->verticeB - 1][es[j]->verticeA - 1] = 1;
			printf("%d %s %d\n", es[j]->verticeA, es[j]->direccion == 'b' ? " <--> " : es[j]->direccion == 'd' ? " --> " : " <-- ", es[j]->verticeB);
		}
	}
	*/
	
	/* 
	 * Imprime la matriz 
	for (int i = 0; i < numeroVertices; i++){
		for (int j = 0; j < numeroVertices; j++){
			printf(" %d ", this->Matriz[i][j]);
		}
		printf("\n");
	}
	*/
	
	this->Vertices.crearListaIndexada();
}

void Grafo::imprimirVertices(Funcion funcionMostrarListaVertice(DATOS d, int respuesta))
{
    this->Vertices.mostrar(funcionMostrarListaVertice);
}

DATOS *Grafo::getVertice(int vertice)
{
    return this->Vertices.getStructIndex(vertice-1);
}

DATOS *Grafo::camino(int vertice1, int vertice2 )
{
    int contador = 0;
    ListaDoble listaCaminosMinimos('a');
    
    this->caminoRecursivo( vertice1, vertice2, &listaCaminosMinimos, 0);
    
    return NULL;
}

void Grafo::caminoRecursivo(int vertice1, int vertice2, ListaDoble *listaCamino, int jeneracion)
{
    pthread_t *aPthread;//Puntero de thread 
    thread_parametros *pt;//puntero de parametros de thread
    
    Vertice *v = (Vertice*)this->getVertice(vertice1), *vtmp;//e VerticeClase Vertice
    V *vdatos = (V*)v->pdatos, *vdatostmp;//Estructura V, Vertice
    E **etmp, **e = (E**)v->Aristas.mostrar(); //Estructura E, Arista
    
    int contadorAristas = 0, numeroAristas = vdatos->numeroAristas, aristasNoBloqueadas[4];
    vdatos->bloqueada = true;//Se bloquea el vertice actual
    
    ListaDoble listaPosiblesCaminos('a'), *lpc;//Se crea una lista
    VerticeLista vLista, *vListaN;//Datos que almacena la sub-lista
    DatoStructMultiple dMultiple, *dMultipleN;//Datos que almacena la lista
    //Datos que almacena la lista multiple
    vLista.v = v;//vertice
    vLista.vertice = vdatos->vertice;//numero de vertice
    dMultiple.datos = &vLista;//estructura de datos que almacena la lista
    dMultiple.lista = &listaPosiblesCaminos;//Sub-lista
    listaCamino->insertar(&dMultiple);//Inserta en la lista la estructura dMultiple
    
    printf("\nVertice Inicial:%d   ", vdatos->vertice );
    //printf("Numero aristas: %d,   Bloqueada: %s\n", vdatos->numeroAristas, vdatos->bloqueada == true?"true":"false");
    //Cuenta cuantas aristas no estan bloquedas
    for(int i = 0; i < numeroAristas; i++ ){
        vtmp = (Vertice*)this->getVertice(e[i]->verticeB);
        vdatostmp = (V*)vtmp->pdatos;
        etmp = (E**)vtmp->Aristas.mostrar();
         printf("Vertice B: %d\tBloqueada: %s   \n", vdatostmp->vertice, vdatostmp->bloqueada == true?"true":"false" );
        if( !vdatostmp->bloqueada ){
            vListaN = (VerticeLista*)malloc(sizeof(VerticeLista));
            dMultipleN = (DatoStructMultiple*)malloc(sizeof(DatoStructMultiple));
            lpc = new ListaDoble;
            vListaN->v = vtmp;
            vListaN->vertice vdatostmp->vertice;
            dMultipleN->datos = vListaN;
            dMultipleN->lista = lpc;
            aristasNoBloqueadas[contadorAristas++] = vdatostmp->vertice;
            vdatostmp->distaciaHaciaEl = jeneracion + 1;
            listaPosiblesCaminos.insertar(dMultipleN);
        }
    }
    
    //Crea los hilos de pendiendo del numero de aristas
    if(contadorAristas > 0){
        aPthread = (pthread_t*)calloc(contadorAristas, sizeof (pthread_t));
        pt = (thread_parametros*)calloc(contadorAristas, sizeof(thread_parametros));
        for(int i = 0; i < contadorAristas; i++)
        {   
            pt[i].vertice1 = aristasNoBloqueadas[i];
            pt[i].vertice2 = vertice2;
            pt[i].jeneracion = jeneracion + 1;
            pt[i].listaVerticesHijos = &listaPosiblesCaminos;
            pt[i].padre = v;
            pt[i].yo = (Vertice*)this->getVertice(aristasNoBloqueadas[i]);
            pt[i].g = this;
        }
        for(int i = 0; i < contadorAristas; i++){
            pthread_create(&aPthread[i], NULL, &funcionHilo, (void*)&pt[i]);
        }
        for(int i = 0; i < contadorAristas; i++){
            pthread_join(aPthread[i], NULL);
        }
        for(int i = 0; i < contadorAristas; i++){
            pthread_exit(&aPthread[i]);
        }
        free(pt);
        free(aPthread);
    }
}

DATOS *Grafo::buscarDatoVertice( DATOS d, bool funcionBuscarLista(DATOS d, DATOS a_buscar))
{
    return (DATOS*)this->Vertices.buscar(d,funcionBuscarLista);
}

void *funcionHilo(void *pthread)
{
    getchar();
    pthread_t *aPthread;//Puntero de hilos  
    thread_parametros *pt; 
    thread_parametros *p = (thread_parametros*)pthread;//puntero de para metros de hilo
    Vertice *v = (Vertice*)p->yo, *vtmp;//Clase Vertice
    V *vdatos = (V*)v->pdatos, *vdatostmp;//Estructura V, Vertice
    E **etmp, **e = (E**)v->Aristas.mostrar();//Estructura E, Arista
    int contadorAristas = 0,  numeroAristas = vdatos->numeroAristas,  aristasNoBloqueadas[4];
    vdatos->bloqueada = true;// Se bloque el vertice actual 
    
    ListaDoble listaPosiblesCaminos('a');//Se crea una lista
    VerticeLista vLista;//Datos que almacena la sub-lista
    DatoStructMultiple dMultiple;//Datos que almacena la lista
    //Datos que almacena la lista multiple
    vLista.v = v;//vertice
    vLista.vertice = vdatos->vertice;//numero de vertice
    dMultiple.datos = &vLista;//estructura de datos que almacena la lista
    dMultiple.lista = listaPosiblesCaminos;//Sub-lista
    
    
    
    printf("\nVertice Inicial:%d   ",vdatos->vertice );
    printf("Numero aristas: %d   Bloqueada: %s\n", vdatos->numeroAristas, vdatos->bloqueada?"true":"false");
    for(int i = 0; i < numeroAristas; i++ ){
        vtmp = (Vertice*)p->g->getVertice(e[i]->verticeB);
        vdatostmp = (V*)vtmp->pdatos;
        etmp = (E**)vtmp->Aristas.mostrar();
        printf("Vertice B: %d\tBloqueada: %s   \n", vdatostmp->vertice, vdatostmp->bloqueada == true?"true":"false" );
        if( !vdatostmp->bloqueada ){
           aristasNoBloqueadas[contadorAristas++] = vdatostmp->vertice;
           //Se analiza el camino minimo
            if( p->jeneracion <= vdatos->distaciaHaciaEl ){
                vdatos->distaciaHaciaEl = p->jeneracion;
                p->listaVerticesHijos->insertar(&dMultiple);
            }
        }
    }
    
    printf("Numero de aristas Total: %d\n", contadorAristas);
    if(contadorAristas > 0){
        aPthread = (pthread_t*)calloc(contadorAristas, sizeof (pthread_t));
        pt = (thread_parametros*)calloc(contadorAristas, sizeof(thread_parametros));
        for(int i = 0; i < contadorAristas; i++)
        {   
            pt[i].vertice1 = aristasNoBloqueadas[i];
            pt[i].vertice2 = p->vertice2;
            pt[i].jeneracion = p->jeneracion+1;
            pt[i].listaVerticesHijos = &listaPosiblesCaminos;
            pt[i].padre = v;
            pt[i].yo = (Vertice*)p->g->getVertice(aristasNoBloqueadas[i]);
            pt[i].g = p->g;
        }
        for(int i = 0; i< contadorAristas; i++){
            printf("\tHilo numero %d creado;", i+1);
            pthread_create(&aPthread[i], NULL, &funcionHilo, (void*)&pt[i]);
            printf("\tVertice a: %d;\tVertice b: %d;", pt[i].vertice1, pt[i].vertice2);
            printf("\tJeneracion: %d\n", pt[i].jeneracion);
        }
        
        for(int i = 0; i< contadorAristas; i++){
            printf("\tHilo enlazado %d creado;\n", i+1);
            pthread_join(aPthread[i], NULL);
            printf("\tVertice a: %d;\tVertice b: %d;", pt[i].vertice1, pt[i].vertice2);
            printf("\tJeneracion: %d\n", pt[i].jeneracion);
        }
        
        for(int i = 0; i< contadorAristas; i++){	
            printf("\tHilo numero %d eleminado;\n", i+1 );
            pthread_exit(&aPthread[i]);
            printf("\tVertice a: %d;\tVertice b: %d;", pt[i].vertice1, pt[i].vertice2);
            printf("\tJeneracion: %d\n", pt[i].jeneracion);
        }
        free(pt);
        free(aPthread);
    }
    return 0;
}