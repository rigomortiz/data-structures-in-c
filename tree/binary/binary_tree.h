#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif
    typedef const char *string;
    typedef void *DATA;
    typedef struct Binary_Tree_ADT binary_tree_adt, node;
    typedef binary_tree_adt *pbinary_tree_adt, pnode, ELEMENT;
    typedef struct Binary_Tree binary_tree;
    typedef struct Chaining_Get chaining_get;


    struct Chaining_Get {
        DATA * (*inorder)(void (*callback)(DATA d, int r));
        DATA * (*postorder)(void (*callback)(DATA d, int r));
        DATA * (*preorder)(void (*callback)(DATA d, int r));
    };

    struct Binary_Tree_ADT{
        DATA data;
        double long repeat;
        struct Binary_Tree_ADT *left_leaf;
        struct Binary_Tree_ADT *right_leaf;
    };

    struct Binary_Tree{
        pbinary_tree_adt binary_tree_adt;
        long double number_elements;

        int (*insert)(binary_tree *this_binary_tree, DATA data_to_insert, void (*callback_insert)(DATA d), int (*callback_order)(DATA new, DATA inserted) );
        int (*insert_multiple)(binary_tree *this_binary_tree, void (*callback_insert)(DATA d), void(*callback_order)(DATA new, DATA inserted),  int count, ...);
        chaining_get (*get)(binary_tree *this);
        void (*print)(binary_tree *this_binary_tree, string type, void (*callback)(DATA));

        int (*delete)(binary_tree *this_binary_tree, DATA d, void (*callback)(DATA));
        int (*search)(binary_tree *this_binary_tree, DATA d, void (*callback)(DATA));
        int (*empty)(binary_tree *this_binary_tree);
    };

    void init_stack(binary_tree *this_binary_tree);
    void destroy_stack(binary_tree *this_binary_tree);

    int insert(binary_tree *this_binary_tree, DATA data_to_insert, void (*callback_insert)(DATA d), int (*callback_order)(DATA new, DATA inserted) );
    int insert_multiple(binary_tree *this_binary_tree, void (*callback_insert)(DATA d), void(*callback_order)(DATA new, DATA inserted),  int count, ...);
    chaining_get get(binary_tree *this);
    void print(binary_tree *this_binary_tree, string type, void (*callback)(DATA));
    int delete(binary_tree *this_binary_tree, DATA d, void (*callback)(DATA));
    int search(binary_tree *this_binary_tree, DATA d, void (*callback)(DATA));
    int empty(binary_tree *this_binary_tree);

    int _empty(pbinary_tree_adt hijo;
    DATA* _inorder(void (*callback)(DATA d, int r), pbinary_tree_adt hijo);
    DATA* _preorder(void (*callback)(DATA d, int r),  pbinary_tree_adt hijo);
    DATA* _postorder(void (*callback)(DATA d, int r),  pbinary_tree_adt hijo);
    DATA* inorder(void (*callback)(DATA d, int r));
    DATA* preorder(void (*callback)(DATA d, int r));
    DATA* postorder(void (*callback)(DATA d, int r));

#ifdef __cplusplus
}
#endif

#endif /* ARBOLBINARIO_H_ */
