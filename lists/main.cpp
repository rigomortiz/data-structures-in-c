#include <stdio.h>
#include <stdlib.h>
#include "arbol_binario.h"
#include "lista.h"
#include "pila.h"

/*************************************************************
FUNCIONES LISTA DOBLE ENLACE
/************************************************************/

funcionLista listaDobleInsertar(DATOS datosNuevos);
funcionLista listaDobleMostrar(DATOS d, int respuesta);
bool funcionOrdenamiento(DATOS nuevo, DATOS insertardo, char tipo_orden);

/*************************************************************
FUNCIONES ARBOL
/************************************************************/

int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado);
void_funcionArbol insertar(DATOS d);
void_funcionArbol mostrar(DATOS d, int r);

/*************************************************************
FUNCIONES PILA
/************************************************************/
funcionPila pilaPush(DATOS datosNuevos);
funcionPila pilaValorPop(DATOS datosEliminados);
funcionPila pilaTop(DATOS datosTope);
funcionPila pilaMostrar(DATOS d, int r);
typedef struct
{
	char caracter;
	int numero;
}myStruct;
typedef struct
{
	char caracter; 
	float flotante; 
	int numero; 
	string texto;

}myStruct2;
typedef struct
{
	unsigned char uchar;
	unsigned int uint;
	unsigned long ulong;
	unsigned short ushort;
}myStruct3;
int main(int argc, char** argv)
{
	//Estructura Arbol
	myStruct e, e1, e2, e3, e4, e5, e6, e7 ,e8, e9;
	//Estructura lista doble enlace
	myStruct2 f, f1, f2, f3, f4, f5;
	//Estructura pila
	myStruct3 g, g1, g2, g3, g4, g5, *pstruct, **Ptr;
	char x;
	
	e.caracter = e.numero = 'G';
	e1.caracter = e1.numero = 'D';
	e2.caracter = e2.numero = 'I';
	e3.caracter = e3.numero = 'B';
	e4.caracter = e4.numero = 'F';
	e5.caracter = e5.numero = 'H';
	e6.caracter = e6.numero = 'J';
	e7.caracter = e7.numero = 'A';
	e8.caracter = e8.numero = 'C';
	e9.caracter = e9.numero = 'E';
	
	f.caracter = 'd'; f.flotante=12.87; f.numero = 89; f.texto = "hello";
	f1.caracter = 'b'; f1.flotante=58.39; f1.numero = 46; f1.texto = "yes";
	f2.caracter = 'k'; f2.flotante=14.90; f2.numero = 67; f2.texto = "si";
	f3.caracter = 'u'; f3.flotante=123.098; f3.numero = 23; f3.texto = "no";
	f4.caracter = 'p'; f4.flotante=98.76; f4.numero = 59; f4.texto = "world";

	g.uchar = 65;g.uint = 1283;g.ulong = 1323232;g.ushort = 132;
	g1.uchar = 66;g1.uint = 1284;g1.ulong = 1323233;g1.ushort = 133;
	g2.uchar = 67;g2.uint = 1285;g2.ulong = 1323234;g2.ushort = 134;
	g3.uchar = 68;g3.uint = 1286;g3.ulong = 1323235;g3.ushort = 135;
	g4.uchar = 69;g4.uint = 1287;g4.ulong = 1323236;g4.ushort = 136;
	g5.uchar = 70;g5.uint = 1288;g5.ulong = 1323237;g5.ushort = 137;
	
	//Arbol binario
	ArbolBinario a(0);
	a.insertarMultiple( insertar, ordenamiento, 10, &e, &e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8, &e9 );
	printf("\nnumero elementos:%d", a.Nelementos());
	printf("\nInorden:\n");
	a.mostrar().inorden(mostrar);
	printf("\nPreorden:\n");
	a.mostrar().preorden(mostrar);
	printf("\nPostorden:\n\n");
	a.mostrar().postorden(mostrar);
	a.vaciar();

	//Lista doble enlace
	ListaDoble ld('a');
	ld.mostrar(listaDobleMostrar);
	ld.insertarMultiple(listaDobleInsertar, funcionOrdenamiento, 5, &f, &f1, &f2, &f3, &f4);
	ld.mostrar(listaDobleMostrar);
	ld.vaciar() ? printf("1") : printf("0");
	ld.mostrar(listaDobleMostrar);

	//Pila
	Pila p;
	p.mostrar(pilaMostrar);
	p.pushMultiple(pilaPush, 6, &g, &g1, &g2, &g3, &g4, &g5);
	p.mostrar(pilaMostrar);
	pstruct = (myStruct3*)p.valorPop(pilaValorPop);
	printf("\nDato elimminado %c\n", pstruct->uchar);
	p.mostrar(pilaMostrar);
	p.pop();
	p.mostrar(pilaMostrar);
	pstruct = (myStruct3*)p.top(pilaTop);
	printf("\nDato tope %c\n", pstruct->uchar);
	p.mostrar(pilaMostrar);
	Ptr = (myStruct3**)p.mostrar();
	printf("\n %c, %c, %c, %c:", Ptr[0]->uchar, Ptr[1]->uchar, Ptr[2]->uchar, Ptr[3]->uchar);
	Ptr = (myStruct3**)ld.mostrar();
	p.vaciar() ? printf("1") : printf("0");
	p.mostrar(pilaMostrar);


	scanf("%c", &x);
	
	return 1;
}
/*************************************************************
FUNCIONES ARBOL
/************************************************************/
void_funcionArbol insertar (DATOS datosNuevos)
{
	myStruct *s = (myStruct*)datosNuevos;
	printf("Datos insertados: %c, %d.\n", s->caracter, s->numero );
}
int_funcionArbol ordenamiento(DATOS nuevo, DATOS insertado)
{
	myStruct *i = (myStruct*)insertado;
    myStruct *n = (myStruct*)nuevo;
	if( n->numero > i->numero) return -1;
    else if(i->numero > n->numero) return 1;
    else// (n->numero == i->numero) 
		return 0;	
}
void_funcionArbol mostrar(DATOS d, int r)
{
	if (r) {
		myStruct *s = (myStruct*)d;
		printf("%c[%d] \n", s->caracter, s->numero);
	}
	else
		printf("\nLista vacia.\n");
}
/*************************************************************
FUNCIONES LISTA DPOBLE ENLACE
/************************************************************/
bool funcionOrdenamiento(DATOS nuevo, DATOS insertado, char t)
{
	myStruct2 *i = (myStruct2*)insertado;
    myStruct2 *n = (myStruct2*)nuevo;
	return ((t=='a'&&n->numero<=i->numero)||(t=='d'&&n->numero>=i->numero))?true:false;
	
}
funcionLista listaDobleInsertar (DATOS datosNuevos)
{
	myStruct2 *s = (myStruct2*)datosNuevos;
	printf("Datos insertados: %c, %f, %d, %s .\n", s->caracter, s->flotante, s->numero, s->texto);
}
funcionLista listaDobleMostrar(DATOS d, int respuesta)
{
	if (respuesta) {
		myStruct2 *s = (myStruct2*)d;
		printf("( %c, %f, %d, %s ) ---> ", s->caracter, s->flotante, s->numero, s->texto);
	}
	else
		printf("\nLista vacia.\n");
}
/*************************************************************
FUNCIONES PILA
/************************************************************/
funcionPila pilaPush(DATOS d)//(DATOS datosNuevos)//insertar en la pila
{
	myStruct3 *s = (myStruct3*)d;
	printf("Datos insertados; Uchar : %c ushort: %d.\n", s->uchar, s->ushort);
}
funcionPila pilaValorPop(DATOS datosEliminados)//muestra y elimina el top de la pila
{
	myStruct3 *s = (myStruct3*)datosEliminados;
	printf("Datos eliminados;Uchar : %c \t ushort: %d.\n", s->uchar, s->ushort);
}
funcionPila pilaTop(DATOS datoTope)//muestra el valor top de la pila
{
	myStruct3 *s = (myStruct3*)datoTope;
	printf("Datos tope; Uchar : %c \t ushort: %d.\n", s->uchar, s->ushort);
}
funcionPila pilaMostrar(DATOS d, int resultado)//muestra la pila
{
	if (resultado) {
		myStruct3 *s = (myStruct3*)d;
		printf("(%c,%d,%f,%d) --> ", s->uchar, s->uint, s->ulong, s->ushort);
	}
	else printf("\nCola vacia.\n");
}
