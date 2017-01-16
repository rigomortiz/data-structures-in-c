//
// Created by regoeco on 15/01/17.
//
#include "tree-pyramid.h"

/**
 *
 * @return PyramidTree
 */
PyramidTree newPyramidTree(){
    PyramidTree pyramidTree;
    struct PrivateDataPyramidTree *dataPyramidTree = malloc(sizeof(struct PrivateDataPyramidTree));

    //PRIVATE DATA
    dataPyramidTree->height = 0;
    dataPyramidTree->num_elements = 0;
    dataPyramidTree->first_node = NULL;
    dataPyramidTree->last_node = NULL;

    // PYRAMID TREE
    pyramidTree.private = dataPyramidTree;
    pyramidTree.empty = _empty_pyramid_tree;
    pyramidTree.get = _get_pyramid_tree;
    pyramidTree.get_num_elements = _get_num_elements_pyramid_tree;
    pyramidTree.insert = _insert_pyramid_tree;
    pyramidTree.insert_multiple = _insert_multiple_pyramid_tree;
    pyramidTree.print = _print_pyramid_tree;

    return pyramidTree;
}

/**
 *
 * @return *PyramidTree
 */
PyramidTree *newPtrPyramidTree(){
    PyramidTree *pyramidTree = malloc(sizeof(ELEMENT_PYRAMID_TREE));
    struct PrivateDataPyramidTree *dataPyramidTree = malloc(sizeof(struct PrivateDataPyramidTree));

    //PRIVATE DATA
    dataPyramidTree->height = 0;
    dataPyramidTree->num_elements = 0;
    dataPyramidTree->first_node = NULL;
    dataPyramidTree->last_node = NULL;

    // PYRAMID TREE
    pyramidTree->private = dataPyramidTree;
    pyramidTree->empty = _empty_pyramid_tree;
    pyramidTree->get = _get_pyramid_tree;
    pyramidTree->get_num_elements = _get_num_elements_pyramid_tree;
    pyramidTree->insert = _insert_pyramid_tree;
    pyramidTree->insert_multiple = _insert_multiple_pyramid_tree;
    pyramidTree->print = _print_pyramid_tree;

    return pyramidTree;
}

/**
 *
 * @param this
 */
void destroyPyramidTree(PyramidTree *this){
    struct PrivateDataPyramidTree *p = this->private;
    if( p->num_elements > 0){
        this->empty(this);
    }
    free(this->private);
}

/**
 *
 * @param right_father
 * @param data_to_insert
 * @param callback
 * @return
 */
static PyramidTreeADT new_node(PyramidTreeADT right_father, PyramidTreeADT left_father, const void* data_to_insert, void(*const callback)(const void* data)){
    PyramidTreeADT new = (PyramidTreeADT)malloc(sizeof(ELEMENT_PYRAMID_TREE));
    if(callback != NULL)
        callback(data_to_insert);
    memcpy(new->data, data_to_insert, 1);
    new->right_son  = NULL;
    new->left_son  = NULL;
    new->left_father = left_father;
    new->right_father = right_father;
    new->level = right_father->level + 1;
    return new;
}

/**
 *
 * @param father
 * @param data_to_insert
 * @param callback
 * @return
 */
static PyramidTreeADT new_node_head(const void* data_to_insert, void(*const callback)(const void* data)){
    PyramidTreeADT new = (PyramidTreeADT)malloc(sizeof(ELEMENT_PYRAMID_TREE));
    if(callback != NULL)
        callback(data_to_insert);
    memcpy(new->data, data_to_insert, 1);
    new->left_father = NULL;
    new->right_father = NULL;
    new->left_son  = NULL;
    new->right_son  = NULL;
    new->level = 1;
    return new;
}


/**
 *
 * @param this
 * @param data
 * @param callback_insert
 * @return
 */
int _insert_pyramid_tree(PyramidTree *this, const void* data_to_insert, void(*const callback_insert)(const void* data)){
    int r;
    //first element
    struct PrivateDataPyramidTree *private = (struct PrivateDataPyramidTree*)this->private;
    if( private->first_node == NULL) {
        private->last_node = private->first_node = new_node_head(data_to_insert, callback_insert);
    }else{
        PyramidTreeADT tmp = private->last_node;
        PyramidTreeADT right_father = NULL;
        PyramidTreeADT left_father = NULL;

        if( tmp->left_father == NULL && tmp->right_father == NULL ){
            right_father = tmp;
            //private->last_node =  tmp->left_son = new_node_only_father_right(tmp, data_to_insert, callback_insert);
        }
        else if( tmp->left_father == NULL && tmp->right_father != NULL ){
            left_father  = tmp->right_father;
            if(tmp->right_father->right_father == NULL){
                right_father = NULL;
            }else{
                right_father = tmp->right_father->right_father->right_son;
            }
            //private->last_node = tmp->right_father->right_son = new_node(right_father, left_father, data_to_insert, callback_insert );
        }
        else if( tmp->left_father != NULL && tmp->right_father != NULL ){
            left_father  = tmp->right_father;
            if(tmp->right_father->right_father == NULL){
                right_father = NULL;
            }else{
                right_father = tmp->right_father->right_father->right_son;
            }
            //private->last_node = tmp->right_father->right_son = new_node(right_father, left_father, data_to_insert, callback_insert );
        }
        else if( tmp->left_father != NULL && tmp->right_father == NULL ){
            tmp = private->first_node;
            while(tmp->left_son != NULL)
                tmp = tmp->left_son;
            right_father = tmp;
            //private->last_node =  tmp->left_son = new_node_only_father_right(tmp, data_to_insert, callback_insert);
        }
        private->last_node = tmp->right_father->right_son = new_node(right_father, left_father, data_to_insert, callback_insert );
    }
    private->num_elements++;
    return 1;
}

/**
 *
 * @param this
 * @return
 */
unsigned int _get_num_elements_pyramid_tree(PyramidTree *this){
    struct PrivateDataPyramidTree *private = (struct PrivateDataPyramidTree*)this->private;
    return private->num_elements;
}

/**
 *
 * @param this
 * @param callback_insert
 * @param count
 * @return
 */
int _insert_multiple_pyramid_tree(PyramidTree *this, void(*const callback_insert)(const void* data),  int count, ...){
    int i = 0;
    int r = 1;
    va_list lt;
    va_start(lt, count);

    for (i = 0;i<count;i++)
        r = r && this->insert( this, va_arg(lt, void*), callback_insert);
    va_end(lt);

    return r;
}

/**
 *
 * @param this
 * @return
 */
int _empty_pyramid_tree(PyramidTree *this){
    struct PrivateDataPyramidTree *private = (struct PrivateDataPyramidTree*)this->private;
    if(private->num_elements > 0){
        PyramidTreeADT level = private->first_node;
        PyramidTreeADT tmp;
        while(level->right_son != NULL){
            level = level->right_son;
        }
        if(level == private->last_node){
            level = private->last_node->left_father;
        }
        while(private->num_elements > 0){
            tmp = private->last_node;
            if(private->last_node->left_father == NULL){
                private->last_node = level;
            }else{
                private->last_node = private->last_node->left_father->left_son;
            }
            free(tmp->data);
            free(tmp);
            private->num_elements--;
        }
        return 1;
    } else{
        return 0;
    }
}

/**
 *
 * @param this
 * @return
 */
struct ChainingGet _get_pyramid_tree(const PyramidTree* this){

}

/**
 *
 * @param this
 * @return
 */
struct ChainingPrint _print_pyramid_tree(const PyramidTree* this){

}