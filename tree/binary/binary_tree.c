#include "binary_tree.h"

void init_stack(binary_tree *this_binary_tree){
    this_binary_tree->binary_tree_adt = NULL;
    this_binary_tree->number_elements = 0;
    this_binary_tree->delete = delete;
    this_binary_tree->empty = empty;
    this_binary_tree->insert = insert;
    this_binary_tree->insert_multiple = insert_multiple;
    this_binary_tree->print = print;
    this_binary_tree->search = search;
    this_binary_tree->get = get;
}
void destroy_stack(binary_tree *this_binary_tree){
    this_binary_tree->empty(this_binary_tree);
}

int insert(binary_tree *this_binary_tree, DATA data_to_insert, void(*callback_insert)(DATA d), int(*callback_order)(DATA new, DATA inserted) ){

    int r;
    if( this_binary_tree->binary_tree_adt == NULL)
    {
        // CODIGO AQUI --->
        pbinary_tree_adt new;
        new = (pbinary_tree_adt)malloc(sizeof(ELEMENT));
        if(callback_insert != NULL)
            callback_insert(data_to_insert);
        new->data = data_to_insert;
        new->right_leaf  = NULL;
        new->left_leaf  = NULL;
        new->repeat = 0;
        this_binary_tree->binary_tree_adt = new;//asignacion a lista el primer elemento
        // <---------------
        this_binary_tree->number_elements++;
        return 1;
    }else{
        pbinary_tree_adt  tmp = this_binary_tree->binary_tree_adt;
        while(1){
            r = callback_order(data_to_insert, tmp->data);
            // less
            if( r == -1) {
                if( tmp->left_leaf != NULL){
                    tmp = tmp->left_leaf;
                }else{
                    // CODIGO AQUI --->
                    pbinary_tree_adt new = (pbinary_tree_adt)malloc(sizeof(ELEMENT));
                    if(callback_insert != NULL)
                        callback_insert(data_to_insert);
                    new->data = data_to_insert;
                    new->right_leaf  = NULL;
                    new->left_leaf  = NULL;
                    new->repeat = 0;
                    tmp->left_leaf = new;//asignacion a lista el primer elemento
                    // <---------------
                    this_binary_tree->number_elements++;
                    return 1;
                }
            }
            // high
            else if( r == 1) {
                if( tmp->right_leaf != NULL){
                    tmp = tmp->right_leaf;
                }else{
                    // CODIGO AQUI --->
                    pbinary_tree_adt new = (pbinary_tree_adt)malloc(sizeof(ELEMENT));
                    if(callback_insert != NULL)
                        callback_insert(data_to_insert);
                    new->data = data_to_insert;
                    new->right_leaf  = NULL;
                    new->left_leaf  = NULL;
                    new->repeat = 0;
                    tmp->left_leaf = new;//asignacion a lista el primer elemento
                    // <---------------
                    this_binary_tree->number_elements++;
                    return 1;
                }
            }
            // equal
            else if (r == 0) {
                this_binary_tree->binary_tree_adt->repeat++;
                break;
            }

        }
        return 1;
    }

}

int insert_multiple(binary_tree *this_binary_tree, void (*callback_insert)(DATA d), void(*callback_order)(DATA new, DATA inserted),  int count, ...){
    int i = 0;
    int r = 1;
    va_list lt;
    va_start(lt, numero);

    for (i = 0;i<count;i++)
        r = r && this_binary_tree->insert( this_binary_tree, va_arg(lt, DATA), callback_insert, callback_order);
    va_end(lt);

    return r;
}

chaining_get get(binary_tree *this_binary_tree){
    chaining_get methods;
    DATA* _inorder(void (*callback)(DATA d, int r), pbinary_tree_adt hijo)
    {
        if(hijo != NULL){
            _inorder(callback, hijo->left_leaf);
            callback(hijo->data, 1);
            _inorder(callback, hijo->right_leaf);
        }
        void *s = NULL;
        return s;
    }

    DATA* _preorder(void (*callback)(DATA d, int r),  pbinary_tree_adt hijo)
    {
        if(hijo != NULL){
            callback(hijo->data, 1);
            _preorder(callback, hijo->left_leaf);
            _preorder(callback, hijo->right_leaf);
        }
        void *s = NULL;
        return s;
    }

    DATA* _postorder(void (*callback)(DATA d, int r),  pbinary_tree_adt hijo)
    {
        if(hijo != NULL){
            _postorder(callback, hijo->left_leaf);
            _postorder(callback, hijo->right_leaf);
            callback(hijo->data,1);
        }
        void *s = NULL;
        return s;
    }


    DATA* inorder(void (*callback)(DATA d, int r))
    {
        if(this_binary_tree->number_elements > 0)
            return _inorder(callback, this_binary_tree->binary_tree_adt);
        else return NULL;
    }
    DATA* preorder(void (*callback)(DATA d, int r))
    {
        if(this_binary_tree->number_elements > 0)
            return _preorder(callback, this_binary_tree->binary_tree_adt);
        else return NULL;
    }

    DATA* postorder(void (*callback)(DATA d, int r))
    {
        if(this_binary_tree->number_elements > 0)
            return _postorder(callback, this_binary_tree->binary_tree_adt);
        else return NULL;
    }

    methods.inorder = inorder;
    methods.postorder = postorder;
    methods.preorder = preorder;

    return methods;
}

int delete(binary_tree *this_binary_tree, DATA d, void (*callback)(DATA)){

}

int search(binary_tree *this_binary_tree, DATA d, void (*callback)(DATA));

int empty(binary_tree *this_binary_tree){
    int _empty(pbinary_tree_adt hijo ){
        if( hijo != NULL){
            _empty(hijo->left_leaf);
            _empty(hijo->right_leaf);
            free(hijo);
            *hijo = NULL;
        }
    }

    if( this_binary_tree->binary_tree_adt != NULL )
    {
        this_binary_tree->empty(this_binary_tree->binary_tree_adt);
        free(this_binary_tree->binary_tree_adt);
        this_binary_tree->binary_tree_adt = NULL;
        this_binary_tree->number_elements = 0;
        return 1;

    } else
        return 0;

}

void print(binary_tree *this_binary_tree, string type, void (*callback)(DATA));
