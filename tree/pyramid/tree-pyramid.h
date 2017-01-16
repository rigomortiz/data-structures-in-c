//
// Created by regoeco on 15/01/17.
//

#ifndef TREE_PYRAMID_H
#define TREE_PYRAMID_H
#include <memory.h>
#include <malloc.h>


#ifdef __cplusplus
extern "C" {
#endif

typedef struct PyramidTree PyramidTree;
typedef struct PyramidTreeADT* PyramidTreeADT, ELEMENT_PYRAMID_TREE;

struct RightPrint{
    void (*const asc)();
    void (*const dee)();
};

struct DepthPrint{
    struct LeftPrint (*const left)();
    struct Rightrint (*const right)();
};

struct WidthPrint{
    struct LeftPrint (*const left)();
    struct Rightrint (*const right)();
};

struct ChainingPrint{
    struct DepthPrint (*const depth)(void(*callback)(const void* data));
    struct WidthPrint (*const width)(void(*callback)(const void* data));
};

struct PyramidTreeADT{
    void* data;
    unsigned int level;
    PyramidTreeADT left_father;
    PyramidTreeADT right_father;
    PyramidTreeADT left_son;
    PyramidTreeADT right_son;
};

struct PrivateDataPyramidTree{
    PyramidTreeADT first_node;
    PyramidTreeADT last_node;
    unsigned int num_elements;
    unsigned int height;
};

struct PyramidTree{
    void* private;
    unsigned int(*get_num_elements)(PyramidTree *this);
    int (*insert)(PyramidTree *this, const void* data, void(*const callback_insert)(const void* data));
    int (*insert_multiple)(PyramidTree *this, void(*const callback_insert)(const void* data),  int count, ...);
    int (*empty)(PyramidTree *this);
    struct ChainingGet (*get)(const PyramidTree* this);
    struct ChainingPrint (*print)(const PyramidTree* this);
};

PyramidTree newPyramidTree();
PyramidTree *newPtrPyramidTree();
void destroyPyramidTree(PyramidTree *this);

/**
 *
 * @param this
 * @param data
 * @param callback_insert
 * @return
 */
static int _insert_pyramid_tree(PyramidTree *this, const void* data, void(*const callback_insert)(const void* data) );

/**
 *
 * @param this
 * @return
 */
static unsigned int _get_num_elements_pyramid_tree(PyramidTree *this);

/**
 *
 * @param this
 * @param data
 * @param callback_insert
 * @return
 */
static int _insert_pyramid_tree(PyramidTree *this, const void* data, void(*const callback_insert)(const void* data));

/**
 *
 * @param this
 * @param callback_insert
 * @param count
 * @return
 */
static int _insert_multiple_pyramid_tree(PyramidTree *this, void(*const callback_insert)(const void* data),  int count, ...);

/**
 *
 * @param this
 * @return
 */
static int _empty_pyramid_tree(PyramidTree *this);

/**
 *
 * @param this
 * @return
 */
static struct ChainingGet _get_pyramid_tree(const PyramidTree* this);

/**
 *
 * @param this
 * @return
 */
static struct ChainingPrint _print_pyramid_tree(const PyramidTree* this);


#ifdef __cplusplus
}
#endif

#endif //TREE_PYRAMID_H
