#include "stack.h"
/**
 *
 * @param stack1
 */
void init_push(stack *stack1){
    stack1->stack_adt = NULL;
    stack1->size = 0;
    stack1->push = push;
    stack1->pop = pop;
    stack1->peek = peek;
}

/**
 *
 * @param stack1
 */
void destroy_push(stack *stack1){
    long double i = 0, l = stack1->size;
    for (i = 0; i < l; i++) {
        stack1->pop(stack1, NULL);
    }
}

/**
 *
 * @details Removing (accessing) an element from the stack.
 * @param this_stack stack self
 * @param function_pop function to execute
 * @return int
 */
int pop(stack *this_stack, void (*callback)(DATA))
{
    pstack p = this_stack->stack_adt;
    if(this_stack->size > 0){
        DATA *d = p->data;
        //CODE HERE
        if(callback != NULL)
            callback(p->data);
        //*d = *dn;
        //END
        this_stack->stack_adt = p->next;
        free(p);
        this_stack->size--;
        return 1;
    }else return 0;
}

/**
 *
 * @details Pushing (storing) an element on the stack.
 * @param this_stack stack self
 * @param d DATA
 * @param function_push function to execute
 * @return int
 */
int push(stack *this_stack, DATA d, void (*callback)(DATA))
{
    pstack pstack_new = (pstack)malloc(sizeof(ELEMENT));
    if(pstack_new != NULL){
        /* CODE HERE ---> */
        if(callback != NULL)
            callback(d);
        pstack_new->data = d;
        /* <--------------- */
        pstack_new->next = this_stack->stack_adt;
        this_stack->stack_adt = pstack_new;
        this_stack->size++;
        return 1;
    }else {
        return 0;
    }
}

/**
 *
 * @param pila
 * @param funcionTop
 * @return
 */
DATA *peek(stack *this_stack)
{
    pstack p = this_stack->stack_adt;
    if(this_stack->size > 0){
        DATA *dn = p->data;
        return dn;
    }else {
        return NULL;
    }
}

/**
 *
 */
void print(void){
    printf("hello");
}

/*

//Devuelve el valor del tope de la pila sin sacarlo; ademas de una pila como 
//argumento es necesario 2 argumentos mas una estructura tipo atos y una 
//funcion como argumento FuncionPila definida por ti.
//returna: int
//parametros: TOPE *pila, DATOS *d, FuncionPila funcionTop
DATOS* top(TOPE *pila, FuncionPila funcionTop)
{
    TOPE p = *pila;
    if(!vaciaPila(p)){
    	DATOS *dn = p->datos;
        //CODE HERE
        funcionTop(p->datos);
        //END
        return dn;
    }else {
        return NULL;
    }
}

//Vacia la pila, retorna TRUE si se vació la pila.
//returna: int
//parametro: TOPE *pila
int vaciarPila(TOPE *pila)
{
    if(pila == NULL){
        return 0;
    }else{
        while(!vaciaPila(*pila)){
            (*pila)->siguiente = NULL;
            free(*pila);
            *pila = (*pila)->siguiente;
        }
        //free(pila);
        return 1;
    }
}


//Muestra todos los valores de la pila,necesita una funcion como argumento
//en la cual se muestran los datos.
//retorna: int 
//parametros: TOPE pila, FuncionPila funcionMostrarPila
int mostrarPila(TOPE pila, FuncionPila funcionMostrarPila)
{
    if(pila == NULL){
    	printf("\nPila vacia.\n");
        return 0;
    }
    else{
        while(pila != NULL){
            funcionMostrarPila(pila->datos);
            pila = pila->siguiente;
        }
        printf(" NULL.\n");
        return 1;
    }
}


int pushMultiple(TOPE *pila, FuncionPila funcionPush, int numero,... )
{
	int i=0;
	int r=1;
    va_list lista;
    va_start(lista,numero);

    for(i=0;i<numero;i++){
    	r = r && push(pila,va_arg(lista,DATOS),funcionPush);
    }
    va_end(lista);
    return r;
}

 */
