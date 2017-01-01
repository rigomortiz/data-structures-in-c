//
// Created by regoeco on 29/12/16.
//
#include "list.h"
List newList(ListType listType, LinkType linkType){

    switch (linkType){
        case SIMPLE:{
            struct PrivateDataListSimple *ps = malloc(sizeof(struct PrivateDataListSimple));
            ps->size = 0;
            ps->listADT = NULL;
            ps->bottom = NULL;
            ps->top = NULL;
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
                    .private = ps
            };
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
                    .listType = listType,
                    .linkType = linkType,
                    .private = pd
            };
            return listDouble;
        }
    }
}
InsertList _insert_list(List *this_binary_tree){
    InsertList insert;
    static  List* this;
    this = this_binary_tree;

    int top(const void* data_to_insert, void(*callback)(const void* d)){
        switch(this->linkType){
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
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
                break;
            }
        }
        return 0;
    }

    int bottom(const void* data_to_insert, void(*callback)(const void* d)){
        switch(this->linkType){
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
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
                break;
            }
        }
        return 0;
    }

    int pos(unsigned int pos, const void* data_to_insert, void(*callback)(const void* d)){
        switch(this->linkType){
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
                if(pos<0 || pos>private->size){
                    return 0;
                }else if(pos == 0){
                    return this->insert(this).bottom(data_to_insert, callback);
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
                break;
            }
        }
        return 0;
    }

    insert.top = top;
    insert.bottom = bottom;
    insert.pos = pos;

    return insert;
}

void _print_list(List *this_binary_tree, void(*callback)(const void* d)){
    switch (this_binary_tree->linkType){
        case SIMPLE:{
            struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this_binary_tree->private;
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

        }
        default:{
            return 0;
        }
    }

}

DeleteList _delete_list(List *this_binary_tree){
    DeleteList deleteList;

    static List* this;
    this = this_binary_tree;

    int top(void(*callback)(const void* d)){
        switch (this->linkType) {
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
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
                break;
            }
            default:{
                return 0;
            }
        }
    }

    int bottom(void(*callback)(const void* d)){
        switch (this->linkType) {
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
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
                break;
            }
        }
    }
    
    int pos(unsigned int pos, void(*callback)(const void* d)){
        switch (this->linkType) {
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
                if(private->size > 0) {
                    if (pos < 0 || pos > private->size) {
                        return 0;
                    } else if (pos == 0) {
                        return this->delete(this).bottom(callback);
                    } else if (pos == private->size) {
                        return this->delete(this).top(callback);
                    } else {
                        SimpleADT simpleADT = private->listADT;
                        int i = 1;
                        for (i = 1; i < pos; simpleADT = simpleADT->next, i++);
                        if (callback != NULL)
                            callback(simpleADT->data);
                        free(simpleADT->next);
                        simpleADT->next = simpleADT->next->next;
                        private->size--;
                        return 1;
                    }
                }
            }
            case DOUBLE: {
                break;
            }
        }
        return 0;
    }

    deleteList.bottom = bottom;
    deleteList.pos = pos;
    deleteList.top = top;

    return deleteList;
}

int _empty_list(List *this){
    switch (this->linkType){
        case SIMPLE:{
            struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
            if(private->size > 0){
                unsigned int i = 0;
                int r = 1;
                unsigned long int size = private->size;
                for(i; i < size; i++){
                    r = r && this->delete(this).pos(i, NULL);
                }
                return 1;
            }
        }
        case DOUBLE:{

        }
        default:
            return 0;
    }
}

int _replace_list(List *this, void* data, unsigned int pos, void(*callback_delete)(const void* d), void(*callback_insert)(const void* d)){
    this->delete(this).pos(pos, callback_delete);
    this->insert(this).pos(pos, data, callback_insert);
    return 1;
}

GetList _get_list(List *list){
    GetList getList;
    static List *this;
    this = list;

    void* pos(unsigned int pos){
        switch (this->linkType) {
            case SIMPLE: {
                void* data = NULL;
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
                if(private->size > 0) {
                    SimpleADT simpleADT = private->listADT;
                    int i;
                    for (i = 1; i < pos; simpleADT = simpleADT->next, i++);
                    return simpleADT->data;
                }else{
                    return data;
                }
            }
            case DOUBLE: {
                break;
            }
            default:
                return NULL;
        }
    }

    void** all(void){
        switch (this->linkType) {
            case SIMPLE: {
                struct PrivateDataListSimple *private = (struct PrivateDataListSimple*)this->private;
                static void** data;
                unsigned int i = 0;
                if(private->size > 0){
                    SimpleADT simpleADT = private->listADT;
                    while (simpleADT != NULL) {
                        data[i++] = simpleADT->data;
                        simpleADT = simpleADT->next;
                    }
                    return data;
                }else{
                    return NULL;
                }
            }
            case DOUBLE: {
                break;
            }
            default:
                return NULL;
        }
    }

    getList.pos = pos;
    getList.all = all;

    return getList;
}

void destroyList(List *this){
    this->empty(this);
    free(this->private);
}

