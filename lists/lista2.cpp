#include "lista.h"
ListaDoble::ListaDoble(char orden)
{
	this->Struct = NULL;
	this->numElementos = 0;
	this->orden = orden;
}

ListaDoble::~ListaDoble()
{
	vaciar();
	vaciarStructIndex();
}

/*============================================================================*/
//Devuelve el numero de elementos
//retorna: int
//parametros: LISTA lista
int ListaDoble::Nelementos()
{
	return this->numElementos;
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Devuelve TRUE si la lista esta vacia
//retorna: bool
//parametros: LISTA lista
bool ListaDoble::vacia()
{
	return (this->Struct == NULL && this->numElementos==0);
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Devuelve TRUE si la lista se vació o retorna FALSE si la lista esta vacia
//retorna: bool
//parametro: LISTA *lista
bool ListaDoble::vaciar()
{
    ENLACE tmp;
    if (this->Struct == NULL)
            return false;
    else {
        while (this->Struct->siguiente != NULL) {
            tmp = this->Struct->siguiente->siguiente;
            free(this->Struct->siguiente);
            this->Struct->siguiente = tmp;
        }
        free(this->Struct);
        this->numElementos = 0;
        this->Struct = NULL;
        return true;
    }
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Inserta en la lista 
//retorna: int
//parametros: LISTA *lista, DATOS d, FuncionLista funcionInsertar
int ListaDoble::insertar(DATOS datos_insertar, Funcion funcionInsertar(DATOS d), bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char tipo_orden))
{
	ENLACE nuevo;
	ENLACE head, tmp;
	unsigned int r = 0;


    //ORDENAMIENTO DESCENDENTE
	if (this->orden == 'd')
	{
		tmp = head = this->Struct;
		if (this->Struct == NULL) {
			// CODIGO AQUI --->
			nuevo = (ENLACE)malloc(sizeof(ELEMENTO));
			funcionInsertar(datos_insertar);
			nuevo->pdatos = datos_insertar;
			nuevo->siguiente = nuevo->anterior = NULL;
			this->Struct = nuevo;//asignacion a lista el primer elemento
			// <---------------
			r = 1;
		}
		else {
			while (1) {
				if (tmp == NULL || funcionOrdenamiento(datos_insertar ,tmp->pdatos, this->orden))
				{
					// CODIGO AQUI --->
					nuevo = (ENLACE)malloc(sizeof(ELEMENTO));
					funcionInsertar(datos_insertar);
					// <---------------
					if (tmp == NULL) {
						nuevo->anterior = head;//asignacion de direccion de elemento siguiente
						nuevo->siguiente = NULL;//asignacion de direcion de elemento anterior
						head->siguiente = nuevo;
					}
					else {
						nuevo->siguiente = tmp;
						nuevo->anterior = tmp->anterior;
						tmp->anterior = nuevo;
						if (nuevo->anterior == NULL)
						{
							nuevo->siguiente = tmp;
							this->Struct = nuevo;
						}
						else nuevo->anterior->siguiente = nuevo;
						
					}
					r = 1;
					break;
				}
				else {
					head = tmp;
					tmp = tmp->siguiente;
				}
			}
		}
	}
	//ORDENAMIENTO ASCENDENTE
	else if (this->orden == 'a')
	{
		tmp = head = this->Struct;
		if (this->Struct == NULL) {
			// CODIGO AQUI --->
			nuevo = (ENLACE)malloc(sizeof(ELEMENTO));
			funcionInsertar(datos_insertar);
			nuevo->pdatos = datos_insertar;
			nuevo->siguiente = NULL;//asignacion de direccion de elemento siguiente
			nuevo->anterior = this->Struct;//asignacion de direcion de elemento anterior
			this->Struct = nuevo;//asignacion a lista el primer elemento
			// <---------------
			r = 1;
		}
		else{
			while (1)
			{
				if (tmp == NULL || funcionOrdenamiento(datos_insertar ,tmp->pdatos, this->orden)) 
				{
					// CODIGO AQUI --->
					nuevo = (ENLACE)malloc(sizeof(ELEMENTO));
					funcionInsertar(datos_insertar);
					nuevo->pdatos = datos_insertar;
					// <---------------
					if (tmp == NULL) {
						nuevo->siguiente = NULL;//asignacion de direccion de elemento siguiente
						nuevo->anterior = head;//asignacion de direcion de elemento anterior
						head->siguiente = nuevo;
					}
					else {
						nuevo->anterior = tmp->anterior;
						nuevo->siguiente = tmp;
						tmp->anterior = nuevo;
						if (nuevo->anterior == NULL)
						{
							nuevo->siguiente = tmp;
							this->Struct = nuevo;
						}
						else nuevo->anterior->siguiente = nuevo;
					}
					r = 1;
					break;
				}
				else {
					head = tmp;
					tmp = tmp->siguiente;
				}
			}
		}
	}

	if (r)this->numElementos++;
	return r;
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Inserta en la lista 
//retorna: int
//parametros: DATOS datos_insertar
int ListaDoble::insertar(DATOS datos_insertar)
{
	ENLACE nuevo;
	ENLACE head, tmp;
	unsigned int r = 0;

	if (this->orden == 'd')
	{
		tmp = head = this->Struct;
		if (this->Struct == NULL) {
			nuevo = (ENLACE)malloc(sizeof(ELEMENTO));
			nuevo->pdatos = datos_insertar;
			nuevo->siguiente = nuevo->anterior = NULL;
			this->Struct = nuevo;//asignacion a lista el primer elemento
			r = 1;
		}
		else
			while (1) {
				if (tmp == NULL || (datos_insertar >= tmp->pdatos))
				{
					nuevo = (ENLACE)malloc(sizeof(ELEMENTO));
					if (tmp == NULL) {
						nuevo->anterior = head;//asignacion de direccion de elemento siguiente
						nuevo->siguiente = NULL;//asignacion de direcion de elemento anterior
						head->siguiente = nuevo;
					}
					else {
						nuevo->siguiente = tmp;
						nuevo->anterior = tmp->anterior;
						tmp->anterior = nuevo;
						if (nuevo->anterior == NULL)
						{
							nuevo->siguiente = tmp;
							this->Struct = nuevo;
						}
						else {
							nuevo->anterior->siguiente = nuevo;
						}
					}
					r = 1;
					break;
				}
				else {
					head = tmp;
					tmp = tmp->siguiente;
				}
			}
	}
	else if (this->orden == 'a')
	{
		tmp = head = this->Struct;
		if (this->Struct == NULL) {
			nuevo = (ENLACE)malloc(sizeof(ELEMENTO));
			nuevo->pdatos = datos_insertar;
			nuevo->siguiente = NULL;//asignacion de direccion de elemento siguiente
			nuevo->anterior = this->Struct;//asignacion de direcion de elemento anterior
			this->Struct = nuevo;//asignacion a lista el primer elemento
			r = 1;
		}
		else
			while (1)
			{
				//si el numero a insertar es menor o igual al que se encuentra en la
				//cabeza de la lista
				if (tmp == NULL || (datos_insertar <= tmp->pdatos))
				{
					nuevo = (ENLACE)malloc(sizeof(ELEMENTO));
					nuevo->pdatos = datos_insertar;
					if (tmp == NULL) {
						nuevo->siguiente = NULL;//asignacion de direccion de elemento siguiente
						nuevo->anterior = head;//asignacion de direcion de elemento anterior
						head->siguiente = nuevo;
					}
					else {
						nuevo->anterior = tmp->anterior;
						nuevo->siguiente = tmp;
						tmp->anterior = nuevo;
						if (nuevo->anterior == NULL)
						{
							nuevo->siguiente = tmp;
							this->Struct = nuevo;
						}
						else {
							nuevo->anterior->siguiente = nuevo;
						}
					}
					r = 1;
					break;
				}
				else {
					head = tmp;
					tmp = tmp->siguiente;
				}
			}
	}
	if (r)this->numElementos++;
	return r;
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Muestra la lista
//retorna: int
//parametro: LISTA lista, FuncionLista funcionMostrarLista
int ListaDoble::mostrar(Funcion funcionMostrarLista(DATOS d, int r))
{
	estructuraListaDoble *p = this->Struct;
	if (this->Struct == NULL)
		funcionMostrarLista(NULL, 0);
	else {
		while (p != NULL) {
			/* CODIGO AQUI ---> */
			funcionMostrarLista(p->pdatos, 1);
			/* <--------------- */
			p = p->siguiente;
		}
		printf("NULL\n\n");
	}
	return 1;
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Muestra la lista
//retorna: int
//parametro: LISTA lista, FuncionLista funcionMostrarLista
DATOS **ListaDoble::mostrar()
{
	estructuraListaDoble *p = this->Struct;
	DATOS **arra = NULL;
	int i = 0;

	if (this->Struct == NULL)
		return NULL;
	else {
		arra = (DATOS**)calloc(this->Nelementos(), sizeof (DATOS));
		while (p != NULL) {
			arra[i++] = (DATOS*)(p->pdatos);
			p = p->siguiente;
		}
		return arra;
		free(arra);
		arra = NULL;
	}
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Insercion multiple
//retorna: int
//parametro: LISTA *lista, FuncionLista funcionInsertar, int numero, ...
int ListaDoble::insertarMultiple(Funcion funcionInsertar(DATOS d),bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char tipo_orden), int numero, ...)
{
	int i = 0;
	int r = 1;
	va_list lt;
	va_start(lt, numero);

	for (i = 0;i<numero;i++)
		r = r && this->insertar(va_arg(lt, DATOS), funcionInsertar, funcionOrdenamiento);
	va_end(lt);

	return r;
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Insercion multiple
//retorna: int
//parametro: LISTA *lista, FuncionLista funcionInsertar, int numero, ...
int ListaDoble::insertarMultiple( int numero, ...)
{
	int i = 0;
	int r = 1;
	va_list lt;
	va_start(lt, numero);

	for (i = 0;i<numero;i++)
		r = r && this->insertar(va_arg(lt, DATOS));
	va_end(lt);

	return r;
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Crea un array de la lista
//retorna: int
//parametro:
int ListaDoble::crearListaIndexada()
{
	estructuraListaDoble *p = this->Struct;
	DATOS **arra = NULL;
	int i = 0;

	if (this->Struct == NULL)
		return false;
	else {
		arra = (DATOS**)calloc(this->Nelementos(), sizeof (DATOS));
		this->Struct_Index = (DATOS*)malloc(sizeof(DATOS)*this->numElementos);
		while (p != NULL) {
			this->Struct_Index[i++] = p->pdatos;
			p = p->siguiente;
		}
		this->numElementosStruct_Index = i;
		return true;
	}
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Retorna un elemento de la lista con indice i
//retorna: DATOS *
//parametro: int i
DATOS *ListaDoble::getStructIndex(int i)
{
	return (DATOS*)this->Struct_Index[i];
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Libera la lista de la memoria
//retorna: 
//parametro:
void ListaDoble::vaciarStructIndex()
{
    free(this->Struct_Index);
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Busca un DATOS d en la lista y retorna el DATO
//retorna: DATOS buscado o null
//parametro: DATOS d, bool funcionBuscarLista(DATOS d, Datos buscar)
DATOS *ListaDoble::buscar(DATOS d, bool funcionBuscarLista(DATOS d, DATOS buscar))
{
    estructuraListaDoble *p = this->Struct;
    if (this->Struct == NULL)
        return NULL;
    else {
        while (p != NULL) {
            /* CODIGO AQUI ---> */
            if(funcionBuscarLista(p->pdatos, d)){
                    return (DATOS*)p->pdatos;
                    break;
            }
            /* <--------------- */
            
            p = p->siguiente;
        }
    }
}
/*____________________________________________________________________________
============================================================================*/
int ListaDoble::eliminar(DATOS d, bool funcionEliminarLista(DATOS d, DATOS a_eliminar))
{
    estructuraListaDoble *p = this->Struct;
    if (this->Struct == NULL)
        return 0;
    else {
        while (p != NULL) {
            /* CODIGO AQUI ---> */
            if(funcionEliminarLista(p->pdatos, d)){
                if(this->numElementos > 0) {   
                    if(p->anterior == NULL){
                        p->siguiente->anterior = NULL;
                    }else if(p->siguiente == NULL){
                        p->anterior->siguiente = NULL;
                    }else{
                        p->anterior->siguiente = p->siguiente;
                        p->siguiente->anterior = p->anterior;
                    }
                }
                free(p);
                return 1;
                break;
            }
            /* <--------------- */
            p = p->siguiente;
        }
    }
}