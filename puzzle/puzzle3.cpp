#include "puzzle3.h"
Puzzle::Puzzle(int numero, int array[][])
{
	this->Struct = NULL;
	this->numElementos = numero;
}

Puzzle::~Puzzle()
{
	vaciar();
}
/*============================================================================*/
//Devuelve el numero de elementos
//retorna: 
//parametros: 
int Puzzle::Puzzle()
{
	return this->numElementos;
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Devuelve TRUE si la lista esta vacia
//retorna: int
//parametros: LISTA lista
int Puzzle::vacia()
{
	return (this->Struct == NULL && this->numElementos==0);
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Devuelve TRUE si la lista se vaci� y retorna FALSE si la lista esta vacia
//retorna: int
//parametro: LISTA *lista
int Puzzle::vaciar()
{
	ENLACE tmp;
	if (this->Struct == NULL)
		return 0;
	else {
		while (this->Struct->siguiente != NULL) {
			tmp = this->Struct->siguiente->siguiente;
			free(this->Struct->siguiente);
			this->Struct->siguiente = tmp;
		}
		free(this->Struct);
		this->numElementos = 0;
		this->Struct = NULL;
		return 1;
	}
}
/*____________________________________________________________________________
============================================================================*/

/*============================================================================*/
//Inserta en la lista 
//retorna: int
//parametros: LISTA *lista, DATOS d, FuncionLista funcionInsertar
int Puzzle::insertar(DATOS datos_insertar, funcionLista funcionInsertar(DATOS d), bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char tipo_orden))
{
	ENLACE nuevo;
	ENLACE head, tmp;
	unsigned int r = 0;


    //ORDENAMIENTO DESCENDENTE
	if (this->orden[0] == 'd')
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
				if (tmp == NULL || funcionOrdenamiento(datos_insertar ,tmp->pdatos, this->orden[0]))
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
	else if (this->orden[0] == 'a')
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
				if (tmp == NULL || funcionOrdenamiento(datos_insertar ,tmp->pdatos, this->orden[0])) 
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

int Puzzle::insertar(DATOS datos_insertar)
{
	ENLACE nuevo;
	ENLACE head, tmp;
	unsigned int r = 0;

	if (this->orden[0] == 'd')
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
	else if (this->orden[0] == 'a')
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
int Puzzle::mostrar(funcionLista funcionMostrarLista(DATOS d, int r))
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
DATOS **Puzzle::mostrar()
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
int Puzzle::insertarMultiple(funcionLista funcionInsertar(DATOS d),bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char tipo_orden), int numero, ...)
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
int Puzzle::insertarMultiple( int numero, ...)
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
