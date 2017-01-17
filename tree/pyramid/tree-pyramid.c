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
    new->data = malloc(sizeof(void*));
    memcpy(new->data, data_to_insert, 1);
    new->right_son  = NULL;
    new->left_son  = NULL;
    new->left_father = left_father;
    new->right_father = right_father;
    new->level = (right_father == NULL?left_father->level:right_father->level) + 1;
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
    new->data = malloc(sizeof(void*));
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

        if(tmp->right_father == NULL){
            if( tmp->left_father != NULL){
                tmp = private->first_node;
                while(tmp->left_son != NULL)
                    tmp = tmp->left_son;
            }
            private->last_node = tmp->left_son = new_node(tmp, NULL, data_to_insert, callback_insert );

        }else if( tmp->right_father != NULL ){
            if(tmp->right_father->right_father == NULL)
                private->last_node = tmp->right_father->right_son = new_node(NULL, tmp->right_father, data_to_insert, callback_insert );
            else
                tmp->right_father->right_father->right_son->left_son = private->last_node = tmp->right_father->right_son = new_node(tmp->right_father->right_father->right_son, tmp->right_father, data_to_insert, callback_insert );
        }
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


/**
 *
 * @param this
 * @return
 */
struct ChainingPrint _print_pyramid_tree(const PyramidTree* this){
    static struct PrivateDataPyramidTree *privateDataPyramidTree;
    privateDataPyramidTree = this->private;
    struct DepthPrint depthPrint(void(*const callback)(const void* data)){
        static void (*fun)(const void* data);
        fun = callback;
        struct LeftPrint leftPrint(void){

            void des(void){
                PyramidTreeADT first = privateDataPyramidTree->first_node;
                while(first != NULL) {
                    PyramidTreeADT tmp = first;
                    if (fun != NULL)
                        fun(first->data);
                    while (tmp->left_son != NULL) {
                        tmp = tmp->left_son;
                        if (fun != NULL)
                            fun(tmp->data);
                    }
                    first = first->right_son;
                }
            }

            void asc(void){

            }

            struct LeftPrint leftPrint = {
                .asc = asc,
                .des = des
            };

            return leftPrint;
        }

        struct RightPrint rightPrint(void){

            void des(void){
                PyramidTreeADT first = privateDataPyramidTree->first_node;
                while(first != NULL) {
                    PyramidTreeADT tmp = first;
                    if (fun != NULL)
                        fun(first->data);
                    while (tmp->right_son != NULL) {
                        tmp = tmp->right_son;
                        if (fun != NULL)
                            fun(tmp->data);
                    }
                    first = first->left_son;
                }
            }

            void asc(void){

            }

            struct RightPrint rightPrint = {
                .asc = asc,
                .des = des
            };

            return rightPrint;
        }

        struct DepthPrint depthPrint = {
            .left = leftPrint,
            .right = rightPrint
        };

        return depthPrint;
    }

    struct WidthPrint widthPrint(void(*const callback)(const void* data)){

        struct LeftPrint leftPrint(void){

            void des(void){

            }

            void asc(void){

            }

            struct LeftPrint leftPrint = {
                    .asc = asc,
                    .des = des
            };

            return leftPrint;
        }

        struct RightPrint rightPrint(void){

            void des(void){

            }

            void asc(void){

            }

            struct RightPrint rightPrint = {
                    .asc = asc,
                    .des = des
            };

            return rightPrint;
        }

        struct WidthPrint widthPrint = {
            .left = leftPrint,
            .right = rightPrint
        };

        return widthPrint;
    }

    struct ChainingPrint chainingPrint = {
        .depth = depthPrint,
        .width = widthPrint
    };

    return chainingPrint;
}

/**
 *
 * @param this
 * @return
 */
struct ChainingGet _get_pyramid_tree(const PyramidTree* this){
    struct ChainingGet chainingGet;
    return chainingGet;
}