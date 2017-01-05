//
// Created by regoeco on 29/12/16.
//
#include "list.h"

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
                    .replace = _replace_list,
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
                    .replace = _replace_list,
                    .get = _get_list,
                    .listType = listType,
                    .linkType = linkType,
                    .private = pd,
            };
            return listDouble;
        }
    }
}

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
                    new_simple->next = NULL;
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
                    new_double->next = NULL;
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
                    new_double->prev = NULL;
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
                if(pos<0 || pos>private->size){
                    return 0;
                }else if(pos == 0){
                    return static_this->insert(static_this).bottom(data_to_insert, callback);
                }else {
                    SimpleADT simpleADT = private->listADT;
                    int i = 1;
                    while (i < pos) {
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
                if(pos<0 || pos>private->size){
                    return 0;
                }else if(pos == 0){
                    return static_this->insert(static_this).bottom(data_to_insert, callback);
                }else {
                    DoubleADT doubleADT = private->listADT;
                    int i = 1;
                    while (i < pos) {
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

void _print_list(List *this, void(*callback)(const void* d)){

    switch (this->linkType){
        case SIMPLE:{
            struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;

            if(private->size > 0) {
                SimpleADT simpleADT = private->listADT;
                while (simpleADT != NULL) {
                    if (callback != NULL) {
                        callback(simpleADT->data);
                    }
                    simpleADT = simpleADT->next;
                }
            }
            break;
        }
        case DOUBLE:{
            struct PrivateDataListDouble *private = (struct PrivateDataListDouble*)this->private;
            if(private->size > 0) {
                DoubleADT doubleADT = private->listADT;
                while (doubleADT != NULL) {
                    if (callback != NULL) {
                        callback(doubleADT->data);
                    }
                    doubleADT = doubleADT->next;
                }
            }
            break;
        }
    }

}

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

int _replace_list(List *this, void* data, unsigned int p, void(*callback_delete)(const void* d), void(*callback_insert)(const void* d)){
    this->delete(this).pos(p, callback_delete);
    this->insert(this).pos(p, data, callback_insert);
    return 1;
}

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
                    int i;
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

    void** all(void){
        switch (this->linkType) {
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
                void** data  = calloc(private->size , sizeof(void*));
                unsigned int i = 0;
                if(private->size > 0){
                    SimpleADT simpleADT = private->listADT;
                    while (simpleADT != NULL) {
                        data[i++] = simpleADT->data;
                        simpleADT = simpleADT->next;
                    }
                    return data;
                }
            }
            case DOUBLE: {
                struct PrivateDataListDouble *private = (struct PrivateDataListDouble*)this->private;
                void** data  = calloc(private->size , sizeof(void*));
                unsigned int i = 0;
                if(private->size > 0){
                    DoubleADT doubleADT = private->listADT;
                    while (doubleADT != NULL) {
                        data[i++] = doubleADT->data;
                        doubleADT = doubleADT->next;
                    }
                    return data;
                }
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

void destroyList(List *this){
    this->empty(this);
    free(this->private);
}

