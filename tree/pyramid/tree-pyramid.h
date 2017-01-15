//
// Created by regoeco on 15/01/17.
//

#ifndef TREE_PYRAMID_H
#define TREE_PYRAMID_H
#ifdef __cplusplus
extern "C" {
#endif
typedef struct PyramidTree PyramidTree;
typedef struct PyramidTreeADT* PyramidTreeADT, ELEMENT_PYRAMID_TREE;

struct ChainingPrint{
    struct InorderPrint (*const inorder)(void(*callback)(const void* data));
};

struct PyramidTreeADT{
    void* data;
    unsigned int level;
    PyramidTreeADT father;
    PyramidTreeADT left_leaf;
    PyramidTreeADT right_leaf;
};

struct PrivateDataPyramidTree{
    PyramidTreeADT pyramid_tree_adt;
    unsigned int num_elements;
    unsigned int height;
};

struct PyramidTree{
    void* const private;
    unsigned  int (*const get_num_elements)(PyramidTree *this);
/*
    int (*const insert)(BinaryTree *this, const void* data, void(*const callback_insert)(const void* data), int(*const callback_order)(const void* new, const void* inserted));
    int (*const insert_multiple)(BinaryTree *this, void(*const callback_insert)(const void* data), int(*const callback_order)(const void* new, const void* inserted),  int count, ...);
    struct Find (*const find)(BinaryTree *this, const void* data, int(*const callback)(const void* d1, const void* d2));
    int (*const empty)(BinaryTree *this);
    struct ChainingGet (*const get)(const BinaryTree* this);
    struct ChainingPrint (*const print)(const BinaryTree* this);
*/
};

PyramidTree newPyramidTree();
PyramidTree *newPtrPyramidTree();
void destroyBinaryTree(PyramidTree *this);

static int _insert_pyramid_tree(PyramidTree *this, const void* data, void(*const callback_insert)(const void* data) );

/*
static int _insert_multiple_binary_tree(BinaryTree *this, void(*const callback_insert)(const void* data), int(*const callback_order)(const void* new, const void* inserted),  int count, ...);
static struct ChainingGet _get_binary_tree(const BinaryTree *this);
static struct ChainingPrint _print_binary_tree(const BinaryTree *this);
static struct Find _find_binary_tree(BinaryTree *this, const void* data, int (*const callback)(const void* d1, const void* d2));
static int _empty_binary_tree(BinaryTree *this);
unsigned int _get_num_elements(BinaryTree *this);
*/


#ifdef __cplusplus
}
#endif

#endif //TREE_PYRAMID_H
