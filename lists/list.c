//
// Created by regoeco on 29/12/16.
//
#include "list.h"
/**
 *
 * @return struct PrivateDataListSimple*
 */
static struct PrivateDataListSimple* createPrivateDataListSimple(){
    struct PrivateDataListSimple *ps = malloc(sizeof(struct PrivateDataListSimple));
    ps->size = 0,
    ps->listADT = NULL,
    ps->bottom = NULL,
    ps->top = NULL;
    return ps;
}

/**
 *
 * @return struct PrivateDataListDouble*
 */
static struct PrivateDataListDouble* createPrivateDataListDouble(){
    struct PrivateDataListDouble *ps = malloc(sizeof(struct PrivateDataListDouble));
    ps->size = 0,
            ps->listADT = NULL,
            ps->bottom = NULL,
            ps->top = NULL;
    return ps;
}

/**
 *
 * @param listType
 * @param linkType
 * @param private
 * @return
 */
static List* createList(ListType listType, LinkType linkType, void *private){
    List *listSimple = malloc(sizeof(List));
    listSimple->insert = _insert_list,
    listSimple->print = _print_list,
    listSimple->get_size = _get_size,
    listSimple->delete = _delete_list,
    listSimple->empty = _empty_list,
    listSimple->update = _update_list,
    listSimple->get = _get_list,
    listSimple->listType = listType,
    listSimple->linkType = linkType,
    listSimple->private = private;

    return listSimple;
}

/**
 *
 * @param listType
 * @param linkType
 * @return
 */
List* newListPtr(ListType listType, LinkType linkType){
    switch (linkType){
        case SIMPLE:{
            struct PrivateDataListSimple *ps = createPrivateDataListSimple();
            List *listSimple = createList(listType, linkType, ps);
            return listSimple;
        }

        case DOUBLE:{
            struct PrivateDataListDouble *ps = createPrivateDataListDouble();
            List *listSimple = createList(listType, linkType, ps);
            return listSimple;
        }
    }
}

/**
 *
 * @param listType
 * @param linkType
 * @return
 */
List newList(ListType listType, LinkType linkType){

    switch (linkType){
        case SIMPLE:{
            struct PrivateDataListSimple *ps = malloc(sizeof(struct PrivateDataListSimple));
            List listSimple = {
                    .insert = _insert_list,
                    .print = _print_list,
                    .get_size = _get_size,
                    .delete = _delete_list,
                    .empty = _empty_list,
                    .update = _update_list,
                    .get = _get_list,
                    .listType = listType,
                    .linkType = linkType,
                    .private = ps,
            };
            ps->size = 0;
            ps->listADT = NULL;
            ps->bottom = NULL;
            ps->top = NULL;
            return listSimple;
        }

        case DOUBLE:{
            struct PrivateDataListDouble *pd = malloc(sizeof(struct PrivateDataListDouble));
            pd->size = 0;
            pd->listADT = NULL;
            pd->bottom = NULL;
            pd->top = NULL;
            List listDouble = {
                    .insert = _insert_list,
                    .print = _print_list,
                    .get_size = _get_size,
                    .delete = _delete_list,
                    .empty = _empty_list,
                    .update = _update_list,
                    .get = _get_list,
                    .listType = listType,
                    .linkType = linkType,
                    .private = pd,
            };
            return listDouble;
        }
    }
}

/**
 *
 * @param this
 * @return
 */
InsertList _insert_list(List *this){
    static  List* static_this;
    static_this = this;

    int top(const void* data_to_insert, void(*callback)(const void* d)){
        switch(static_this->linkType){
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)static_this->private;
                SimpleADT new_simple = (SimpleADT) malloc(sizeof(ELEMENT_SIMPLE_LIST));
                if (new_simple != NULL) {
                    if (callback != NULL)
                        callback(data_to_insert);
                    if( static_this->linkType == CIRCULAR ){
                        new_simple->next = private->bottom;
                    } else if(static_this->linkType == LINEAL){
                        new_simple->next = NULL;
                    }
                    new_simple->data = (void *) data_to_insert;
                    if(private->listADT == NULL){
                        private->listADT = new_simple;
                        private->bottom = new_simple;
                    } else
                        private->top->next = new_simple;
                    private->top = new_simple;
                    private->size++;
                    return 1;
                } else {
                    return 0;
                }
            }
            case DOUBLE: {
                struct PrivateDataListDouble *private = (struct PrivateDataListDouble*)this->private;
                DoubleADT new_double = (DoubleADT) malloc(sizeof(ELEMENT_DOUBLE_LIST));
                if (new_double != NULL) {
                    if (callback != NULL)
                        callback(data_to_insert);
                    if( static_this->linkType == CIRCULAR ){
                        new_double->next = private->bottom;
                    } else if(static_this->linkType == LINEAL){
                        new_double->next = NULL;
                    }
                    new_double->prev = private->top;
                    new_double->data = (void *) data_to_insert;
                    if(private->listADT == NULL){
                        private->listADT = new_double;
                        private->bottom = new_double;
                    } else
                        private->top->next = new_double;
                    private->top = new_double;
                    private->size++;
                    return 1;
                } else {
                    return 0;
                }
                break;
            }
        }
        return 0;
    }

    int bottom(const void* data_to_insert, void(*callback)(const void* d)){
        switch(static_this->linkType){
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)static_this->private;
                SimpleADT new_simple = (SimpleADT) malloc(sizeof(ELEMENT_SIMPLE_LIST));
                if (new_simple != NULL) {
                    if (callback != NULL)
                        callback(data_to_insert);
                    new_simple->next = private->bottom;
                    new_simple->data = (void *) data_to_insert;
                    private->listADT = new_simple;
                    private->bottom = new_simple;
                    private->size++;
                    return 1;
                } else {
                    return 0;
                }
            }
            case DOUBLE: {
                struct PrivateDataListDouble *private = (struct PrivateDataListDouble*)this->private;
                DoubleADT new_double = (DoubleADT) malloc(sizeof(ELEMENT_DOUBLE_LIST));
                if (new_double != NULL) {
                    if (callback != NULL)
                        callback(data_to_insert);
                    new_double->next = private->bottom;
                    if( static_this->linkType == CIRCULAR ){
                        new_double->prev = private->top;
                    } else if(static_this->linkType == LINEAL){
                        new_double->prev = NULL;
                    }
                    new_double->data = (void *) data_to_insert;
                    private->listADT = new_double;
                    private->bottom = new_double;
                    private->size++;
                    return 1;
                } else {
                    return 0;
                }
                break;
            }
        }
        return 0;
    }

    int pos(unsigned int p, const void* data_to_insert, void(*callback)(const void* d)){
        switch(static_this->linkType){
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)static_this->private;
                if(p<0 || p>private->size){
                    return 0;
                }else if(p == private->size-1){
                    return static_this->insert(static_this).top(data_to_insert, callback);
                }else if(p == 0){
                    return static_this->insert(static_this).bottom(data_to_insert, callback);
                }else {
                    SimpleADT simpleADT = private->listADT;
                    int i = 1;
                    while (i < p) {
                        simpleADT = simpleADT->next;
                        i++;
                    }
                    SimpleADT new_simple = (SimpleADT) malloc(sizeof(ELEMENT_SIMPLE_LIST));
                    if (new_simple != NULL) {
                        if (callback != NULL)
                            callback(data_to_insert);
                        new_simple->data = (void *) data_to_insert;
                        new_simple->next = simpleADT->next;
                        simpleADT->next = new_simple;
                        private->size++;
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
            case DOUBLE: {
                struct PrivateDataListDouble *private = (struct PrivateDataListDouble*)static_this->private;
                if(p<0 || p>private->size){
                    return 0;
                }else if(p == 0){
                    return static_this->insert(static_this).bottom(data_to_insert, callback);
                }else {
                    DoubleADT doubleADT = private->listADT;
                    int i = 1;
                    while (i < p) {
                        doubleADT = doubleADT->next;
                        i++;
                    }
                    DoubleADT new_double = (DoubleADT) malloc(sizeof(ELEMENT_DOUBLE_LIST));
                    if (new_double != NULL) {
                        if (callback != NULL)
                            callback(data_to_insert);
                        new_double->data = (void *) data_to_insert;
                        new_double->next = doubleADT->next;
                        new_double->prev = doubleADT;
                        doubleADT->next = new_double;
                        private->size++;
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
        return 0;
    }

    InsertList insert = {
        .top = top,
        .bottom = bottom,
        .pos = pos
    };


    return insert;
}

/**
 *
 * @param this
 * @param callback
 */
void _print_list(List *this, void(*callback)(const void* d)){

    switch (this->linkType){
        case SIMPLE:{
            struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;

            if(private->size > 0) {
                SimpleADT simpleADT = private->listADT;
                unsigned int size = private->size;
                unsigned int i;
                for(i=0; i< size; i++){
                    if (callback != NULL)
                        callback(simpleADT->data);
                    simpleADT = simpleADT->next;
                }
            }
            break;
        }
        case DOUBLE:{
            struct PrivateDataListDouble *private = (struct PrivateDataListDouble*)this->private;
            if(private->size > 0) {
                DoubleADT doubleADT = private->listADT;
                unsigned int size = private->size;
                unsigned int i;
                for(i=0; i< size; i++){
                    if (callback != NULL)
                        callback(doubleADT->data);
                    doubleADT = doubleADT->next;
                }
            }
            break;
        }
    }

}

/**
 *
 * @param this
 * @return
 */
unsigned int _get_size(List *this){
    switch(this->linkType){
        case SIMPLE:{
            struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
            return private->size;
        }
        case DOUBLE:{
            struct PrivateDataListDouble *private = (struct PrivateDataListDouble*)this->private;
            return private->size;
        }
        default:{
            return 0;
        }
    }
}

/**
 *
 * @param this
 * @return
 */
DeleteList _delete_list(List *this){

    static List* static_this;
    static_this = this;

    int top(void(*callback)(const void* d)){
        switch (static_this->linkType) {
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)static_this->private;
                if(private->size > 0) {
                    SimpleADT simpleADT = private->listADT;
                    int i = 1;
                    for (i = 1; i < private->size - 1; simpleADT = simpleADT->next, i++);
                    if (callback != NULL)
                        callback(simpleADT->data);
                    free(private->top->data);
                    free(private->top);
                    simpleADT->next = NULL;
                    private->top = simpleADT;
                    private->size--;
                    return 1;
                }
            }
            case DOUBLE: {
                struct PrivateDataListDouble *private = (struct PrivateDataListDouble*)static_this->private;
                if(private->size > 0) {
                    if (callback != NULL)
                        callback(private->top->data);
                    private->top->prev->next = NULL;
                    private->top = private->top->prev;
                    free(private->top->data);
                    free(private->top);
                    private->size--;
                    return 1;
                }
            }
            default:{
                return 0;
            }
        }
    }

    int bottom(void(*callback)(const void* d)){
        switch (static_this->linkType) {
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)static_this->private;
                if(private->size > 0) {
                    if (callback != NULL)
                        callback(private->bottom->data);
                    private->listADT = private->bottom->next;
                    free(private->bottom->data);
                    free(private->bottom);
                    private->bottom = private->listADT;
                    private->size--;
                    return 1;
                }
            }
            case DOUBLE: {
                struct PrivateDataListDouble *private = (struct PrivateDataListDouble*)static_this->private;
                if(private->size > 0) {
                    if (callback != NULL)
                        callback(private->bottom->data);
                    private->listADT = private->bottom->next;
                    free(private->bottom->data);
                    free(private->bottom);
                    private->bottom = private->listADT;
                    private->size--;
                    return 1;
                }
            }
            default:{
                return 0;
            }
        }
    }
    
    int pos(unsigned int p, void(*callback)(const void* d)){
        switch (static_this->linkType) {
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)static_this->private;
                if(private->size > 0) {
                    if (p < 0 || p > private->size) {
                        return 0;
                    } else if (p == 0) {
                        return static_this->delete(static_this).bottom(callback);
                    } else if (p == private->size) {
                        return static_this->delete(static_this).top(callback);
                    } else {
                        SimpleADT simpleADT = private->listADT;
                        int i = 1;
                        for (i = 1; i < p; simpleADT = simpleADT->next, i++);
                        if (callback != NULL)
                            callback(simpleADT->next->data);
                        free(simpleADT->data);
                        free(simpleADT->next);
                        simpleADT->next = simpleADT->next->next;
                        private->size--;
                        return 1;
                    }
                }
            }
            case DOUBLE: {
                struct PrivateDataListDouble *private = (struct PrivateDataListDouble*)static_this->private;
                if(private->size > 0) {
                    if (p < 0 || p > private->size) {
                        return 0;
                    } else if (p == 0) {
                        return static_this->delete(static_this).bottom(callback);
                    } else if (p == private->size) {
                        return static_this->delete(static_this).top(callback);
                    } else {
                        DoubleADT doubleADT = private->listADT;
                        int i = 1;
                        for (i = 1; i < p; doubleADT = doubleADT->next, i++);
                        if (callback != NULL)
                            callback(doubleADT->next->data);
                        free(doubleADT->next->data);
                        free(doubleADT->next);
                        doubleADT->next = doubleADT->next->next;
                        private->size--;
                        return 1;
                    }
                }
            }
        }
        return 0;
    }

    DeleteList deleteList = {
        .bottom = bottom,
        .pos = pos,
        .top = top
    };

    return deleteList;
}

/**
 *
 * @param this
 * @return
 */
int _empty_list(List *this){
    switch (this->linkType){
        case SIMPLE:{
            struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
            if(private->size > 0){
                unsigned int i = 0;
                int r = 1;
                unsigned  int size = private->size;
                for(i = 0; i < size; i++){
                    r = r && this->delete(this).pos(i, NULL);
                }
                return 1;
            }
        }
        case DOUBLE:{
            struct PrivateDataListDouble *private = (struct PrivateDataListDouble*)this->private;
            if(private->size > 0){
                unsigned int i = 0;
                int r = 1;
                unsigned int size = private->size;
                for(i = 0; i < size; i++){
                    r = r && this->delete(this).pos(i, NULL);
                }
                return 1;
            }
        }
        default:
            return 0;
    }
}

/**
 *
 * @param this
 * @param data
 * @param p
 * @param callback_delete
 * @param callback_insert
 * @return
 */
int _update_list(List *this, void *data, unsigned int p, void(*callback_delete)(const void *d), void(*callback_insert)(const void *d)){
    this->delete(this).pos(p, callback_delete);
    this->insert(this).pos(p, data, callback_insert);
    return 1;
}

/**
 *
 * @param list
 * @return
 */
GetList _get_list(List *list){
    static List *this;
    this = list;

    void* pos(unsigned int p){
        switch (this->linkType) {
            case SIMPLE: {
                void* data = NULL;
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
                if(private->size > 0) {
                    SimpleADT simpleADT = private->listADT;
                    int i;
                    for (i = 0; i < p; simpleADT = simpleADT->next, i++);
                    return simpleADT->data;
                }else{
                    return data;
                }
            }
            case DOUBLE: {
                void* data = NULL;
                struct PrivateDataListDouble *private = (struct PrivateDataListDouble*)this->private;
                if(private->size > 0) {
                    DoubleADT doubleADT = private->listADT;
                    unsigned int size = private->size;
                    int i;
                    if(p>size/2){
                        for (i = 0; i < p; doubleADT = doubleADT->prev, i++);
                    }else
                        for (i = 0; i < p; doubleADT = doubleADT->next, i++);
                    return doubleADT->data;
                }else{
                    return data;
                }
            }
            default:
                return NULL;
        }
    }

    void** all(void) {
        switch (this->linkType) {
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
                void** data  = calloc(private->size , sizeof(void*));
                SimpleADT simpleADT = private->listADT;
                unsigned int size = private->size;
                unsigned int i;
                for(i=0; i< size; i++){
                    data[i] = simpleADT->data;
                    simpleADT = simpleADT->next;
                }
                return data;
            }
            case DOUBLE: {
                struct PrivateDataListDouble *private = (struct PrivateDataListDouble *) this->private;
                void **data = calloc(private->size, sizeof(void *));
                DoubleADT doubleADT = private->listADT;
                unsigned int size = private->size;
                unsigned int i;
                for (i = 0; i < size; i++) {
                    data[i] = doubleADT->data;
                    doubleADT = doubleADT->next;
                }
                return data;
            }
            default:
                return NULL;
        }
    }

    GetList getList = {
        .pos = pos,
        .all = all
    };

    return getList;
}

/**
 *
 * @param this
 */
void destroyList(List *this){
    this->empty(this);
    free(this->private);
}

