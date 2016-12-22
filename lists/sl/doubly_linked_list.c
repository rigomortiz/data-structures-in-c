#include "doubly_linked_list.h"

/*============================================================================*/
//Devuelve el numero de elementos
//retorna: int
//parametro: ENLACE lista
int NelementosLista(LISTA lista)
{
    int elementos  =0;
    if(lista.Lista == NULL){
        return elementos;
    }else{
        while(lista.Lista != NULL){
            elementos++;
            lista.Lista = lista.Lista->siguiente;
        }
    }
    return elementos;
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Devuelve true si la lista esta vacia
//retorna: int
//parametro: ENLACE lista
int vaciaLista(ENLACE *lista)
{
    return ( lista == NULL );
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Devuelve TRUE si la lista se vació y retorna FALSE si la lista esta vacia
//retorna: int
//parametro: ENLACE *lista
int vaciarLista(LISTA *lista)
{
	ENLACE tmp;
    if(lista->Lista == NULL){
		return 0;
    }else{
		while (lista->Lista->siguiente != NULL) {
			tmp = lista->Lista->siguiente->siguiente;
			free(lista->Lista->siguiente);
			lista->Lista->siguiente = tmp;
        }
		free(lista->Lista);
		lista->Lista = NULL;
		return 1;
    }
}
/*____________________________________________________________________________
 ============================================================================*/

 /*
  * ============================================================================*/
 //Inserta en la lista de forma descendente
 //retorna: int
 //parametro: ENLACE *lista, DATOS d, FuncionLista funcionInsertar
int insertar(LISTA *lista, DATOS datos_insertar, FuncionLista funcionInsertar)
{
	ENLACE nuevo;
	ENLACE head, tmp;
	unsigned int gethead = 0, r = 0;

	if (!strcmp(lista->orden, "des"))
	{
		tmp = head = lista->Lista;
		if (vaciaLista((ENLACE *)lista->Lista)) {
			nuevo = (ENLACE)malloc(sizeof(ELEMENTO));
			// CODIGO AQUI --->
			funcionInsertar(datos_insertar);
			nuevo->pdatos = datos_insertar;
			// <---------------
			nuevo->siguiente = NULL;//asignacion de direccion de elemento siguiente
			nuevo->anterior = NULL;//asignacion de direcion de elemento anterior
			lista->Lista = nuevo;//asignacion a lista el primer elemento
			r = 1;
		}
		else
			while (1) {
				if (vaciaLista((ENLACE *)tmp) || (datos_insertar >= tmp->pdatos))
				{
					nuevo = (ENLACE)malloc(sizeof(ELEMENTO));
					// CODIGO AQUI --->
					funcionInsertar(datos_insertar);
					// <---------------
					if (vaciaLista((ENLACE *)tmp)) {
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
							lista->Lista = nuevo;
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
	else if (!strcmp(lista->orden, "asc"))
	{
		tmp = head = lista->Lista;
		if (vaciaLista((ENLACE *)lista->Lista)) {
			nuevo = (ENLACE)malloc(sizeof(ELEMENTO));
			// CODIGO AQUI --->
			funcionInsertar(datos_insertar);
			nuevo->pdatos = datos_insertar;
			// <---------------
			nuevo->siguiente = NULL;//asignacion de direccion de elemento siguiente
			nuevo->anterior = lista->Lista;//asignacion de direcion de elemento anterior
			lista->Lista = nuevo;//asignacion a lista el primer elemento
			r = 1;
		}
		else
			while (1)
			{
				//si el numero a insertar es menor o igual al que se encuentra en la
				//cabeza de la lista
				if (vaciaLista((ENLACE *)tmp) || (datos_insertar <= tmp->pdatos))
				{
					nuevo = (ENLACE)malloc(sizeof(ELEMENTO));
					// CODIGO AQUI --->
					funcionInsertar(datos_insertar);
					nuevo->pdatos = datos_insertar;
					// <---------------
					if (vaciaLista((ENLACE *)tmp)) {
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
							lista->Lista = nuevo;
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
	return r;
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Muestra la lista
//retorna: void
//parametro: ENLACE lista
int mostrarLista(LISTA lista, FuncionLista funcionMostrarLista)
{
	if (lista.Lista == NULL)
		printf("\nLista vacia.\n");
	else {
		while (lista.Lista != NULL) {
			/* CODIGO AQUI ---> */
			funcionMostrarLista(lista.Lista->pdatos);
			/* <--------------- */
			lista.Lista = lista.Lista->siguiente;
		}
		printf("NULL\n\n");
	}
	return 1;
}
/*____________________________________________________________________________
============================================================================*/


int insertarMultiple(LISTA *lista, FuncionLista funcionInsertar,int numero,... )
{
	int i=0;
	int r=1;
    va_list lt;
    va_start(lt,numero);

    for(i=0;i<numero;i++){
    	r = r && insertar(lista, va_arg(lt,DATOS), funcionInsertar);
    }
    va_end(lt);
    return r;
}
