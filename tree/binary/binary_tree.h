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
#include <search.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef struct BinaryTree BinaryTree;
typedef struct BinaryTreeADT* BinaryTreeADT, ELEMENT_BINARY_TREE;
struct InorderPrint{
    void (*const asc)(void);
    void (*const des)(void);
};

struct PreorderPrint{
    void (*const left)(void);
    void (*const right)(void);
};

struct PostorderPrint{
    void (*const left)(void);
    void (*const right)(void);
};

struct InorderGet{
    void** (*const asc)(void);
    void** (*const des)(void);
};

struct PreorderGet{
    void** (*const left)(void);
    void** (*const right)(void);
};

struct PostorderGet{
    void** (*const left)(void);
    void** (*const right)(void);
};

struct ChainingGet{
    struct InorderGet (*const inorder)(void);
    struct PostorderGet (*const postorder)(void);
    struct PreorderGet (*const preorder)(void);
};

struct ChainingPrint{
    struct InorderPrint (*const inorder)(void(*callback)(const void* data));
    struct PostorderPrint (*const postorder)(void(*callback)(const void* data));
    struct PreorderPrint (*const preorder)(void(*callback)(const void* data));
};

struct BinaryTreeADT{
    void* data;
    unsigned int repeat;
    unsigned int level;
    BinaryTreeADT father;
    BinaryTreeADT left_leaf;
    BinaryTreeADT right_leaf;
};

struct Find{
    BinaryTreeADT (*const get)(void);
    int (*const remove)(void);
};

struct PrivateDataBinaryTree{
    BinaryTreeADT binary_tree_adt;
    unsigned int num_elements;
    unsigned int depth;
};
typedef struct BinaryTree{
    void* const private;
    unsigned  int (*const get_num_elements)(BinaryTree *this);
    int (*const insert)(BinaryTree *this, const void* data, void(*const callback_insert)(const void* data), int(*const callback_order)(const void* new, const void* inserted));
    int (*const insert_multiple)(BinaryTree *this, void(*const callback_insert)(const void* data), int(*const callback_order)(const void* new, const void* inserted),  int count, ...);
    struct Find (*const find)(BinaryTree *this, const void* data, int(*const callback)(const void* d1, const void* d2));
    int (*const empty)(BinaryTree *this);
    struct ChainingGet (*const get)(const BinaryTree* this);
    struct ChainingPrint (*const print)(const BinaryTree* this);
};

BinaryTree newBinaryTree();
void destroyBinaryTree(BinaryTree *this);

static int _insert_binary_tree(BinaryTree *this, const void* data, void(*const callback_insert)(const void* data), int(*const callback_order)(const void* new, const void* inserted) );
static int _insert_multiple_binary_tree(BinaryTree *this, void(*const callback_insert)(const void* data), int(*const callback_order)(const void* new, const void* inserted),  int count, ...);
static struct ChainingGet _get_binary_tree(const BinaryTree *this);
static struct ChainingPrint _print_binary_tree(const BinaryTree *this);
static struct Find _find_binary_tree(BinaryTree *this, const void* data, int (*const callback)(const void* d1, const void* d2));
static int _empty_binary_tree(BinaryTree *this);
unsigned int _get_num_elements(BinaryTree *this);



#ifdef __cplusplus
}
#endif

#endif /* BINARY_TREE_H_ */
