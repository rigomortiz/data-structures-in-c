#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef  __cplusplus
extern "C" {
#endif
typedef struct List List;
typedef struct DoubleADT* DoubleADT, ELEMENT_DOUBLE_LIST;
typedef struct SimpleADT* SimpleADT, ELEMENT_SIMPLE_LIST;
struct SimpleADT{
    void* data;
    SimpleADT next;
};

struct DoubleADT{
    void* data;
    DoubleADT prev;
    DoubleADT next;
};

typedef enum ListType{ LINEAL, CIRCULAR }ListType;
typedef enum LinkType{ SIMPLE, DOUBLE }LinkType;

typedef struct PrivateDataListSimple{
    SimpleADT bottom;
    SimpleADT top;
    SimpleADT listADT;
    unsigned int size;
};

typedef struct PrivateDataListDouble{
    DoubleADT bottom;
    DoubleADT top;
    DoubleADT listADT;
    unsigned int size;
};

typedef struct {
    int (*const top)(const void* data_to_insert, void(*callback)(const void* d));
    int (*const bottom)(const void* data_to_insert, void(*callback)(const void* d));
    int (*const pos)(unsigned int p, const void* data_to_insert, void(*callback)(const void* d));
}InsertList;

typedef struct {
    int (*const top)(void(*callback)(const void* d));
    int (*const bottom)(void(*callback)(const void* d));
    int (*const pos)(unsigned int p, void(*callback)(const void* d));
}DeleteList;

typedef struct{
    void* (*const pos)(unsigned int p);
    void** (*const all)(void);
}GetList;


typedef struct List{
    ListType listType;
    LinkType linkType;
    void* private;
    unsigned  int (*get_size)(List *this);
    InsertList (*insert)(List *this);
    void (*print)(List *this, void(*callback)(const void* d));
    int (*empty)(List *this);
    DeleteList (*delete)(List *this);
    int (*update)(List *this, void *data, unsigned int pos, void(*callback_delete)(const void *d), void(*callback_insert)(const void *d));
    GetList (*get)(List *list);
};

List* newListPtr(ListType listType, LinkType linkType);
List newList(ListType list_type, LinkType linkType);
void destroyList(List *list);
static InsertList _insert_list(List *this);
static void _print_list(List *this, void(*callback)(const void* d));
static unsigned int _get_size(List *this);
static DeleteList _delete_list(List *this);
static int _empty_list(List *this);
static int _update_list(List *this, void *data, unsigned int pos, void(*callback_delete)(const void *d), void(*callback_insert)(const void *d));
static GetList _get_list(List *list);

#ifdef  __cplusplus
}
#endif
#endif