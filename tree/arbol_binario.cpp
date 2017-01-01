
#include "arbol_binario.h"
/*============================================================================*/
ArbolBinario::ArbolBinario(int orden)
{
	this->Struct = NULL;
	this->numElementos = 0;
	this->orden = (Orden)orden;
}

/*============================================================================*/
ArbolBinario::~ArbolBinario()
{
	this->vaciar();
}


/*==============================================================================
 *PRIVATE
 */
 
/*============================================================================*/
int ArbolBinario::insertar(BTREE *rama, void_funcionArbol insertar(DATOS d), int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado) , DATOS datos_insertar)
{
	BTREE nuevo;
	int r;
	
	if( *rama == NULL)
	{
		// CODIGO AQUI --->
		nuevo = (BTREE)malloc(sizeof(NODO));
		insertar(datos_insertar);
		nuevo->pdatos = datos_insertar;
		nuevo->hijoDerecho = nuevo->hijoIzquierdo = NULL;
		*rama = nuevo;//asignacion a lista el primer elemento
		// <---------------
		this->numElementos++;
		
		return 1;
	}else{
	
		r = ordenamiento(datos_insertar, (*rama)->pdatos );
		if( r == -1) this->insertar( &((*rama)->hijoDerecho), insertar, ordenamiento, datos_insertar);
		else if( r == 1) this->insertar( &((*rama)->hijoIzquierdo), insertar, ordenamiento, datos_insertar);
		else if (r == 0) (*rama)->repeticion++;
		
		return 1;
	}
}

/*============================================================================*/
int ArbolBinario::insertar(BTREE *rama,  int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado) , DATOS datos_insertar)
{
	BTREE nuevo;
	int r;
	
	if( *rama == NULL)
	{
		// CODIGO AQUI --->
		nuevo = (BTREE)malloc(sizeof(NODO));
		nuevo->pdatos = datos_insertar;
		nuevo->hijoDerecho = nuevo->hijoIzquierdo = NULL;
		*rama = nuevo;//asignacion a lista el primer elemento
		// <---------------
		this->numElementos++;
		return 1;
	}else{
	
		r = ordenamiento(datos_insertar, (*rama)->pdatos);
		if( r == -1) this->insertar( &((*rama)->hijoDerecho), ordenamiento, datos_insertar);
		else if( r == 1) this->insertar( &((*rama)->hijoIzquierdo), ordenamiento, datos_insertar);
		else if (r == 0) (*rama)->repeticion++;
		
		return 1;
	}
}

/*============================================================================*/
int ArbolBinario::inorden(void_funcionArbol mostrar(DATOS d, int r), BTREE hijo)
{
	if(hijo != NULL){
		inorden(mostrar, hijo->hijoIzquierdo);
		mostrar(hijo->pdatos,1);
		inorden(mostrar, hijo->hijoDerecho);
	}
    return 1;
}

/*============================================================================*/
int ArbolBinario::preorden(void_funcionArbol mostrar(DATOS d, int r), BTREE hijo)
{
	if(hijo != NULL){
		mostrar(hijo->pdatos,1);
		preorden(mostrar, hijo->hijoIzquierdo);
		preorden(mostrar, hijo->hijoDerecho);
	}
    return 1;
}

/*============================================================================*/
int ArbolBinario::postorden(void_funcionArbol mostrar(DATOS d, int r), BTREE hijo)
{
	if(hijo != NULL){
		postorden(mostrar, hijo->hijoIzquierdo);
		postorden(mostrar, hijo->hijoDerecho);
		mostrar(hijo->pdatos,1);
	}
    return 1;
}

/*============================================================================*/
int ArbolBinario::vaciar( BTREE *hijo)
{
	if( *hijo != NULL){
		vaciar(&(*hijo)->hijoIzquierdo);
		vaciar(&(*hijo)->hijoDerecho);
		free(*hijo);
		*hijo = NULL;
	}
    return 1;
}


/*==============================================================================
 *PUBLIC
 */
 
 
 /*============================================================================*/
int ArbolBinario::insertar(DATOS datos_insertar, void_funcionArbol insertar(DATOS d), int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado) )
{
	BTREE nuevo;
	int r;
	if( this->Struct == NULL)
	{
		// CODIGO AQUI --->
		nuevo = (BTREE)malloc(sizeof(NODO));
		insertar(datos_insertar);
		nuevo->pdatos = datos_insertar;
		nuevo->hijoDerecho = nuevo->hijoIzquierdo = NULL;
		this->Struct = nuevo;//asignacion a lista el primer elemento
		this->numElementos++;
		// <---------------
		return 1;
	}else{
		//retorna -1 si el primer parametro es mayor, 0 si son iguales, 1 si el segundo es mayor
		r = ordenamiento(datos_insertar, this->Struct->pdatos);
		
		if( r == -1) this->insertar(&(this->Struct->hijoDerecho), insertar, ordenamiento, datos_insertar);
		else if( r == 1) this->insertar(&(this->Struct->hijoIzquierdo), insertar, ordenamiento, datos_insertar);
		else if (r == 0) this->Struct->repeticion++;
		
		return 1;
	}
}

/*============================================================================*/
int ArbolBinario::insertar(DATOS datos_insertar,  int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado) )
{
	BTREE nuevo, a = this->Struct ;
	int r;
	if( a == NULL)
	{
		// CODIGO AQUI --->
		nuevo = (BTREE)malloc(sizeof(NODO));
		nuevo->pdatos = datos_insertar;
		nuevo->hijoDerecho = nuevo->hijoIzquierdo = NULL;
		a = nuevo;//asignacion a lista el primer elemento
		// <---------------
		this->numElementos++;
		return 1;
	}else{
		//retorna -1 si el primer parametro es mayor, 0 si son iguales, 1 si el segundo es mayor
		r = ordenamiento(datos_insertar, a->pdatos);
		if( r == -1) this->insertar( &(this->Struct->hijoDerecho), ordenamiento, datos_insertar);
		else if( r == 1) this->insertar( &(this->Struct->hijoIzquierdo),  ordenamiento, datos_insertar);
		else if (r == 0) this->Struct->repeticion++;
		
		return 1;
	}
}

/*============================================================================*/
int ArbolBinario::insertarMultiple(void_funcionArbol insertar(DATOS d), int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado) ,  int numero, ...)
{
	int i = 0;
	int r = 1;
	va_list lt;
	va_start(lt, numero);

	for (i = 0;i<numero;i++)
		r = r && this->insertar( va_arg(lt, DATOS), insertar, ordenamiento );
	va_end(lt);

	return r;
}

/*============================================================================*/
int ArbolBinario::insertarMultiple( int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado) , int numero, ...)
{
	int i = 0;
	int r = 1;
	va_list lt;
	va_start(lt, numero);

	for (i = 0;i<numero;i++)
		r = r && this->insertar(va_arg(lt, DATOS), ordenamiento );
	va_end(lt);

	return r;
}

/*============================================================================*/
ArbolBinario& ArbolBinario::mostrar()
{
	return *this;
}
	
/*============================================================================*/	
int ArbolBinario::inorden(void_funcionArbol mostrar(DATOS d, int r))
{   
	return (this->Struct != NULL)? (this->inorden(mostrar, this->Struct)? 1: 0) : 0 ;
}
/*____________________________________________________________________________
==============================================================================*/

/*============================================================================*/
int ArbolBinario::preorden(void_funcionArbol mostrar(DATOS d, int r))
{
	return (this->Struct != NULL)? (this->preorden(mostrar, this->Struct)? 1: 0) : 0 ;
}
/*____________________________________________________________________________
==============================================================================*/

/*============================================================================*/
int ArbolBinario::postorden(void_funcionArbol mostrar(DATOS d, int r))
{
	
	return (this->Struct != NULL)? (this->postorden(mostrar, this->Struct)? 1: 0) : 0 ;
}
/*____________________________________________________________________________
==============================================================================*/

/*============================================================================*/
int ArbolBinario::Nelementos()
{
	return this->numElementos;
}
/*____________________________________________________________________________
==============================================================================*/

/*============================================================================*/
int ArbolBinario::vacia()
{
	return (this->Struct == NULL && this->numElementos==0);
}
/*____________________________________________________________________________
==============================================================================*/

/*============================================================================*/
int ArbolBinario::vaciar()
{
	if( this->Struct != NULL )
	{
	   this->vaciar(&(this->Struct));
	   free(this->Struct);
	   this->Struct = NULL;
	   this->numElementos = 0;
	   
	} else return 0;
	
}
/*____________________________________________________________________________
==============================================================================*/

