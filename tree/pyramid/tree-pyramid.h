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
    void (*const asc)(void);
    void (*const des)(void);
};

struct LeftPrint{
    void (*const asc)(void);
    void (*const des)(void);
};

struct DepthPrint{
    struct LeftPrint (*const left)(void);
    struct RightPrint (*const right)(void);
};

struct WidthPrint{
    struct LeftPrint (*const left)(void);
    struct RightPrint (*const right)(void);
};

struct ChainingPrint{
    struct DepthPrint (*const depth)(void(*const callback)(const void* data));
    struct WidthPrint (*const width)(void(*const callback)(const void* data));
};

struct RightGet{
    void (*const asc)(void);
    void (*const des)(void);
};

struct LeftGet{
    void (*const asc)(void);
    void (*const des)(void);
};

struct DepthGet{
    struct LeftGet (*const left)(void);
    struct RightGet (*const right)(void);
};

struct WidthGet{
    struct LeftGet (*const left)(void);
    struct RightGet (*const right)(void);
};

struct ChainingGet{
    struct DepthGet (*const depth)(void(*const callback)(const void* data));
    struct WidthGet (*const width)(void(*const callback)(const void* data));
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
    int (*empty)(PyramidTree *this);
    struct ChainingGet (*get)(const PyramidTree* this);
    struct ChainingPrint (*print)(const PyramidTree* this);
};

/**
 *
 * @return
 */
PyramidTree newPyramidTree();

/**
 *
 * @return
 */
PyramidTree *newPtrPyramidTree();

/**
 *
 * @param this
 */
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
