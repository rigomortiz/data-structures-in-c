#ifndef LIST_H
#define LIST_H
/*
 * Lista simple
 *
 *  adt -->  A1 --> A2 --> ... --> An --> NULL
 *           |                     |
 *           Bottom                Top
 *
 * Insert Top                      An --> new --> NULL;   Top = new
 *
 * Insert Bottom                  adt == new --> bottom; Bottom = new
 */
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
    SimpleADT bottom;
    DoubleADT top;
    DoubleADT listADT;
    unsigned int size;
};

typedef struct {
    int (*top)(const void* data_to_insert, void(*callback)(const void* d));
    int (*bottom)(const void* data_to_insert, void(*callback)(const void* d));
    int (*pos)(unsigned int pos, const void* data_to_insert, void(*callback)(const void* d));
}InsertList;

typedef struct {
    int (*top)(void(*callback)(const void* d));
    int (*bottom)(void(*callback)(const void* d));
    int (*pos)(unsigned int pos, void(*callback)(const void* d));
}DeleteList;

typedef struct{
    void* (*pos)(unsigned int pos);
    void** (*all)(void);
}GetList;

typedef struct List{
    const ListType listType;
    const LinkType linkType;
    void* const private;
    unsigned  int (*const get_size)(List *this);
    InsertList (*const insert)(List *this);
    void (*const print)(List *this, void(*callback)(const void* d));
    int (*const empty)(List *this);
    DeleteList (*const delete)(List *this);
    int (*const replace)(List *this, void* data, unsigned int pos, void(*callback_delete)(const void* d), void(*callback_insert)(const void* d));
    GetList (*const get)(List *list);

    //Find (*find)(BinaryTree *this_binary_tree, const void* d, int(*callback)(const void* d1, const void* d2));
    //ChainingGet (*get)(const BinaryTree* this_binary_tree);
    //ChainingPrint (*print)(const BinaryTree* this_binary_tree);
};

List newList(ListType list_type, LinkType linkType);
void destroyList(List *list);
static InsertList _insert_list(List *this);
static void _print_list(List *this, void(*callback)(const void* d));
static unsigned int _get_size(List *this);
static DeleteList _delete_list(List *this);
static int _empty_list(List *this);
static int _replace_list(List *this, void* data, unsigned int pos, void(*callback_delete)(const void* d), void(*callback_insert)(const void* d));
static GetList _get_list(List *list);

#ifdef  __cplusplus
}
#endif
#endif