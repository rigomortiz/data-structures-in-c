/**
 * PROFUNDIDAD
 * En el recorrido en profundidad, el proceso exige un camino desde el raíz a través de un
 * hijo, al descendiente más lejano del primer hijo antes de proseguir a un segundo hijo. En otras
 * palabras, en el recorrido en profundidad, todos los descendientes de un hijo se procesan antes
 * del siguiente hijo.
 *
 * ANCHURA
 * En el recorrido en anchura, el proceso se realiza horizontalmente desde el raíz a todos
 * sus hijos, a continuación a los hijos de sus hijos y así sucesivamente hasta que todos los nodos
 * han sido procesados. En el recorrido en anchura, cada nivel se procesa totalmente antes de que
 * comience el siguiente nivel.
 *
 *      N
 *   /    \
 *  I      D
 *
 *  PREORDEN: NID
 *  1.- Visita el nodo raíz N
 *  2.- Recorrer el subárbol izquierdo I en preorden
 *  3.- Recorrer el subárbol derecho D en preorden
 *
 *  ENORDEN IND
 *  1.- Recorrer el subárbol izquierdo I en enorden
 *  2.- Visitar el nodo raíz N
 *  3.- Recorrer el subárbol derecho D en enorden
 *
 *  POSTORDEN IDN
 *  1.- Recorrer el subárbol derecho D en postorden
 *  2.- Recorrer el subárbol izquierdo I en postorden
 *  3.- Visitar el nodo raíz N
 */
#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef struct BinaryTree BinaryTree;

typedef struct{
    void (*asc)(void);
    void (*des)(void);
}InorderPrint;

typedef struct{
    void (*left)(void);
    void (*right)(void);
}PreorderPrint;

typedef struct{
    void (*left)(void);
    void (*right)(void);
}PostorderPrint;

typedef struct{
    void** (*asc)(void);
    void** (*des)(void);
}InorderGet;

typedef struct{
    void** (*left)(void);
    void** (*right)(void);
}PreorderGet;

typedef struct{
    void** (*left)(void);
    void** (*right)(void);
}PostorderGet;

typedef struct {
    InorderGet (*inorder)(void);
    PostorderGet (*postorder)(void);
    PreorderGet (*preorder)(void);
}ChainingGet;

typedef struct {
    InorderPrint (*inorder)(const void(*callback)(const void* d));
    PostorderPrint (*postorder)(const void(*callback_insert)(const void* d));
    PreorderPrint (*preorder)(const void(*callback_insert)(const void* d));
}ChainingPrint;

typedef struct Binary_Tree_ADT{
    void* data;
    unsigned long int repeat;
    unsigned long int level;
    struct Binary_Tree_ADT *father;
    struct Binary_Tree_ADT *left_leaf;
    struct Binary_Tree_ADT *right_leaf;
}*pbinary_tree_adt, ELEMENT_BINARY_TREE ;

struct BinaryTree{
    pbinary_tree_adt binary_tree_adt;
    long unsigned int number_elements;
    unsigned long int depth;

    int (*insert)(BinaryTree *this_binary_tree, const void* data_to_insert, const  void (*callback_insert)(const void* d), int (*callback_order)(const void* new, const void* inserted) );
    int (*insert_multiple)(BinaryTree *this_binary_tree, const void (*callback_insert)(const void* d), const int(*callback_order)(const void* new, const void* inserted),  int count, ...);
    ChainingGet (*get)(const BinaryTree* this_binary_tree);
    ChainingPrint (*print)(const BinaryTree* this_binary_tree);
    //void (*print)(const BinaryTree* this_binary_tree, const void (*callback)(const void*));

    int (*delete)(BinaryTree *this_binary_tree, const void* d, const void (*callback)(const void*));
    pbinary_tree_adt (*search)(const BinaryTree *this_binary_tree, const void* d, int (*callback)(const void* d1, const void* d2));
    int (*empty)(BinaryTree *this_binary_tree);
};

BinaryTree newBinaryTree();
void destroyBinaryTree(BinaryTree *this_binary_tree);
static int _insert_binary_tree(BinaryTree *this_binary_tree, const void* data_to_insert, const void (*callback_insert)(const void* d), const int (*callback_order)(const void* new, const void* inserted) );
static int _insert_multiple_binary_tree(BinaryTree *this_binary_tree, const void (*callback_insert)(const void* d), const int(*callback_order)(const void* new, const void* inserted),  int count, ...);
static ChainingGet _get_binary_tree(const BinaryTree *this_binary_tree);
static ChainingPrint _print_binary_tree(const BinaryTree *this_binary_tree);
//static void _print_binary_tree(const BinaryTree *this_binary_tree, const void (*callback)(const void*));
static int _delete_binary_tree(BinaryTree *this_binary_tree, const void* d, const void (*callback)(const void*));
static pbinary_tree_adt _search_binary_tree(const BinaryTree *this_binary_tree, const void* d, int (*callback)(const void* d1, const void* d2));
static int _empty_binary_tree(BinaryTree *this_binary_tree);


#ifdef __cplusplus
}
#endif

#endif /* BINARY_TREE_H_ */
