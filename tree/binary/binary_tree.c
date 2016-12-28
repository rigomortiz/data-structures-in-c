#include "binary_tree.h"
#include "../../stack/stack.h"

/**
 * 
 * @return BinaryTree
 */
BinaryTree newBinaryTree(){
    BinaryTree this_binary_tree;
    this_binary_tree.binary_tree_adt = NULL;
    this_binary_tree.number_elements = 0;
    this_binary_tree.depth = 0;
    this_binary_tree.delete = _delete_binary_tree;
    this_binary_tree.empty = _empty_binary_tree;
    this_binary_tree.insert = _insert_binary_tree;
    this_binary_tree.insert_multiple = _insert_multiple_binary_tree;
    this_binary_tree.print = _print_binary_tree;
    this_binary_tree.search = _search_binary_tree;
    this_binary_tree.get = _get_binary_tree;
    return this_binary_tree;
}

/**
 * 
 * @param this_binary_tree 
 */
void destroyBinaryTree(BinaryTree *this_binary_tree){
    this_binary_tree->empty(this_binary_tree);
}

/**
 * 
 * @param this_binary_tree 
 * @param data_to_insert 
 * @param callback_insert 
 * @param callback_order 
 * @return 
 */
int _insert_binary_tree(BinaryTree *this_binary_tree, const void* data_to_insert, const void(*callback_insert)(const void* d), const int(*callback_order)(const void* new, const void* inserted) ){

    int r;
    //first element
    if( this_binary_tree->binary_tree_adt == NULL)
    {
        pbinary_tree_adt new;
        new = (pbinary_tree_adt)malloc(sizeof(ELEMENT_BINARY_TREE));
        if(callback_insert != NULL)
            callback_insert(data_to_insert);
        new->father = NULL;
        new->data = (void*)data_to_insert;
        new->right_leaf  = NULL;
        new->left_leaf  = NULL;
        new->repeat = 0;
        new->level = 0;
        this_binary_tree->binary_tree_adt = new;
        this_binary_tree->number_elements++;
        return 1;
    }else{
        pbinary_tree_adt  tmp = this_binary_tree->binary_tree_adt;
        while(1){
            r = callback_order(data_to_insert, tmp->data);
            // less
            if( r == -1) {
                if( tmp->left_leaf != NULL){
                    tmp = (pbinary_tree_adt)tmp->left_leaf;
                }else{
                    pbinary_tree_adt new = (pbinary_tree_adt)malloc(sizeof(ELEMENT_BINARY_TREE));
                    if(callback_insert != NULL)
                        callback_insert(data_to_insert);
                    new->data = (void*)data_to_insert;
                    new->right_leaf  = NULL;
                    new->left_leaf  = NULL;
                    new->repeat = 0;
                    tmp->left_leaf = new;
                    new->father = tmp;
                    new->level = tmp->level + 1;
                    if(new->level > this_binary_tree->depth){
                        this_binary_tree->depth = new->level;
                    }
                    this_binary_tree->number_elements++;
                    return 1;
                }
            }
            // high
            else if( r == 1) {
                if( tmp->right_leaf != NULL){
                    tmp = tmp->right_leaf;
                }else{
                    pbinary_tree_adt new = (pbinary_tree_adt)malloc(sizeof(ELEMENT_BINARY_TREE));
                    if(callback_insert != NULL)
                        callback_insert(data_to_insert);
                    new->data = (void*)data_to_insert;
                    new->right_leaf  = NULL;
                    new->left_leaf  = NULL;
                    new->repeat = 0;
                    tmp->right_leaf = new;
                    new->father = tmp;
                    new->level = tmp->level + 1;
                    if(new->level > this_binary_tree->depth){
                        this_binary_tree->depth = new->level;
                    }
                    this_binary_tree->number_elements++;
                    return 1;
                }
            }
            // equal
            else if (r == 0) {
                tmp->repeat++;
                break;
            }
        }
        return 1;
    }

}

/**
 *
 * @param this_binary_tree
 * @param callback_insert
 * @param callback_order
 * @param count
 * @return
 */
int _insert_multiple_binary_tree(BinaryTree *this_binary_tree, const void (*callback_insert)(const void* d), const int(*callback_order)(const void* new, const void* inserted),  int count, ...){
    int i = 0;
    int r = 1;
    va_list lt;
    va_start(lt, count);

    for (i = 0;i<count;i++)
        r = r && this_binary_tree->insert( this_binary_tree, va_arg(lt, void*), callback_insert, callback_order);
    va_end(lt);

    return r;
}

/**
 *
 * @param _this_binary_tree
 * @param v
 * @return
 */
ChainingGet _get_binary_tree(const BinaryTree *this_binary_tree){
    static ChainingGet methods;//Method chaining
    //DATA STACK
    typedef struct{ pbinary_tree_adt ptb; }struct_ptb;
    static const BinaryTree* b;//copy BinaryTree
    b = this_binary_tree;

    PreorderGet preorder() {
        static PreorderGet preorder;

        //NID: NODO RAIZ, NODO IZQUIERDO, NODO DERECHO
        void** left(void){
            if(b->number_elements > 0) {
                int i = 0;
                void ** datas = calloc(sizeof(void*), b->number_elements);
                static Stack stack1;
                stack1 = newStack();
                stack1.push(&stack1, b->binary_tree_adt, NULL);
                while (stack1.size > 0) {
                    pbinary_tree_adt pbinary_tree_adt1 = (pbinary_tree_adt) stack1.peek(&stack1);
                    stack1.pop(&stack1, NULL);
                    datas[i++] = pbinary_tree_adt1->data;
                    if (pbinary_tree_adt1->right_leaf != NULL) {
                        stack1.push(&stack1, (void *) pbinary_tree_adt1->right_leaf, NULL);
                    }
                    if (pbinary_tree_adt1->left_leaf != NULL) {
                        stack1.push(&stack1, (void *) pbinary_tree_adt1->left_leaf, NULL);
                    }
                }
                destroyStack(&stack1);
                return datas;
            }else
                return NULL;
        }

        //DIN: NODO DERECHO, NODOD IZQUIERDO, NODOD RAIZ
        void** right(void) {
            if (b->number_elements > 0) {
                int i = 0;
                void ** datas = calloc(sizeof(void*), b->number_elements);
                pbinary_tree_adt currentNode = NULL;
                static Stack stack1;
                stack1 = newStack();
                stack1.push(&stack1, b->binary_tree_adt, NULL);
                pbinary_tree_adt prev = NULL;

                while (stack1.size > 0) {
                    currentNode = (pbinary_tree_adt) stack1.peek(&stack1);
                    /* case 1. We are nmoving down the tree. */
                    if (prev == NULL || prev->left_leaf == currentNode || prev->right_leaf == currentNode) {
                        if (currentNode->right_leaf)
                            stack1.push(&stack1, currentNode->right_leaf, NULL);
                        else if (currentNode->left_leaf)
                            stack1.push(&stack1, currentNode->left_leaf, NULL);
                        else {
                            /* If node is leaf node */
                            datas[i++] = currentNode->data;
                            stack1.pop(&stack1, NULL);
                        }
                    }
                    /* case 2. We are moving up the tree from left child */
                    if (currentNode->right_leaf == prev) {
                        if (currentNode->left_leaf)
                            stack1.push(&stack1, currentNode->left_leaf, NULL);
                        else {
                            datas[i++] = currentNode->data;
                            stack1.pop(&stack1, NULL);
                        }
                    }
                    /* case 3. We are moving up the tree from right child */
                    if (currentNode->left_leaf == prev) {
                        datas[i++] = currentNode->data;
                        stack1.pop(&stack1, NULL);
                    }
                    prev = currentNode;
                }

                destroyStack(&stack1);
                return datas;
            }else return NULL;
        }
        preorder.left = left;
        preorder.right = right;
        return preorder;
    }

    InorderGet inorder() {
        static InorderGet inorder;

        //IND: NODO IZQUIERDO, NODO RAIZ, NODO DERECHO
        void** asc(void){
            if(b->number_elements > 0){
                int i = 0;
                void** datas = calloc(sizeof(void*), b->number_elements);
                static Stack stack1;
                stack1 = newStack();
                pbinary_tree_adt pbinary_tree_adt1 = b->binary_tree_adt;
                while(stack1.size > 0 || pbinary_tree_adt1 ){
                    if(pbinary_tree_adt1){
                        stack1.push(&stack1, pbinary_tree_adt1, NULL);
                        pbinary_tree_adt1 = (pbinary_tree_adt)pbinary_tree_adt1->left_leaf;
                    }
                    else {
                        pbinary_tree_adt1 = (pbinary_tree_adt)stack1.peek(&stack1);
                        stack1.pop(&stack1, NULL);
                        datas[i++] = pbinary_tree_adt1->data;
                        pbinary_tree_adt1 =(pbinary_tree_adt) pbinary_tree_adt1->right_leaf;
                    }
                }
                destroyStack(&stack1);
                return datas;
            }return NULL;
        }

        //DNI: NODO DERECHO, NODO RAIZ, NODO IZQUIERDO
        void** des(void){
            if(b->number_elements > 0){
                int i = 0;
                void **datas = calloc(sizeof(void*), b->number_elements);
                static Stack stack1;
                stack1 = newStack();
                pbinary_tree_adt pbinary_tree_adt1 = b->binary_tree_adt;
                while(stack1.size > 0 || pbinary_tree_adt1 ){
                    if(pbinary_tree_adt1){
                        stack1.push(&stack1, pbinary_tree_adt1, NULL);
                        pbinary_tree_adt1 = (pbinary_tree_adt)pbinary_tree_adt1->right_leaf;
                    }
                    else {
                        pbinary_tree_adt1 = (pbinary_tree_adt)stack1.peek(&stack1);
                        stack1.pop(&stack1, NULL);
                        datas[i++] = pbinary_tree_adt1->data;
                        pbinary_tree_adt1 =(pbinary_tree_adt) pbinary_tree_adt1->left_leaf;
                    }
                }
                destroyStack(&stack1);
                return datas;
            }else
                return NULL;
        }

        inorder.asc = asc;
        inorder.des = des;
        return inorder;
    }

    PostorderGet postorder() {
        static PostorderGet postorder;

        //IDN: NODO IZQUIERDO, NODO DERECHO, NODO RAIZ
        void** left(void){
            if(b->number_elements > 0) {
                int i = 0;
                void** datas = calloc(sizeof(void*), b->number_elements);
                pbinary_tree_adt currentNode = NULL;
                static Stack stack1;
                stack1 = newStack();
                stack1.push(&stack1, b->binary_tree_adt, NULL);
                pbinary_tree_adt prev = NULL;

                while (stack1.size > 0) {
                    currentNode = (pbinary_tree_adt) stack1.peek(&stack1);
                    /* case 1. We are nmoving down the tree. */
                    if (prev == NULL || prev->left_leaf == currentNode || prev->right_leaf == currentNode) {
                        if (currentNode->left_leaf)
                            stack1.push(&stack1, currentNode->left_leaf, NULL);
                        else if (currentNode->right_leaf)
                            stack1.push(&stack1, currentNode->right_leaf, NULL);
                        else {
                            /* If node is leaf node */
                            datas[i++] = currentNode->data;
                            stack1.pop(&stack1, NULL);
                        }
                    }
                    /* case 2. We are moving up the tree from left child */
                    if (currentNode->left_leaf == prev) {
                        if (currentNode->right_leaf)
                            stack1.push(&stack1, currentNode->right_leaf, NULL);
                        else {
                            datas[i++] = currentNode->data;
                            stack1.pop(&stack1, NULL);
                        }
                    }
                    /* case 3. We are moving up the tree from right child */
                    if (currentNode->right_leaf == prev) {
                        datas[i++] = currentNode->data;
                        stack1.pop(&stack1, NULL);
                    }
                    prev = currentNode;
                }
                destroyStack(&stack1);
                return datas;
            }else
                return NULL;
        }

        //NDI: NODO RAIZ, NODO DERECHO, NODO IZQUIERDO
        void** right(void){
            if(b->number_elements > 0) {
                int i = 0;
                void** datas = calloc(sizeof(void*), b->number_elements);
                static Stack stack1;
                stack1 = newStack();
                stack1.push(&stack1, b->binary_tree_adt, NULL);
                while (stack1.size > 0) {
                    pbinary_tree_adt pbinary_tree_adt1 = (pbinary_tree_adt) stack1.peek(&stack1);
                    stack1.pop(&stack1, NULL);
                    datas[i++] = pbinary_tree_adt1->data;
                    if (pbinary_tree_adt1->left_leaf != NULL)
                        stack1.push(&stack1, (void *) pbinary_tree_adt1->left_leaf, NULL);
                    if (pbinary_tree_adt1->right_leaf != NULL)
                        stack1.push(&stack1, (void *) pbinary_tree_adt1->right_leaf, NULL);
                }
                destroyStack(&stack1);
                return datas;
            }else
                return NULL;
        }

        postorder.left = left;
        postorder.right = right;
        return postorder;
    }


    methods.inorder = inorder;
    methods.postorder = postorder;
    methods.preorder = preorder;

    return methods;
}

/**
 *
 * @param this_binary_tree
 * @param d
 * @param callback
 * @return
 */
int _delete_binary_tree(BinaryTree *this_binary_tree, const void* d, const void (*callback)(const void*)){

}

/**
 *
 * @param this_binary_tree
 * @param d
 * @param callback
 * @return
 */
pbinary_tree_adt _search_binary_tree(const BinaryTree *this_binary_tree, const void* d, int (*callback)(const void* d1, const void* d2)){

    if(this_binary_tree->number_elements>0){
        pbinary_tree_adt pb = this_binary_tree->binary_tree_adt;
        int i = 0;
        while(pb != NULL){
            i = callback(d, pb->data);
            //mayor
            if( i == 1 ){
                pb = pb->right_leaf;
            }//menor
            else if( i == -1 ){
                pb = pb->left_leaf;
            }
            //igual
            else if( i == 0){
                return pb;
            }
        }
    }
    else
        return NULL;
}

/**
 *
 * @param this_binary_tree
 * @return
 */
int _empty_binary_tree(BinaryTree *this_binary_tree){
    Stack stack1 = newStack();

    stack1.push(&stack1, this_binary_tree->binary_tree_adt, NULL);
    pbinary_tree_adt currentNode = NULL ;
    pbinary_tree_adt prev = NULL;
    while(stack1.size > 0){
        currentNode = (pbinary_tree_adt)stack1.peek(&stack1);
        /* case 1. We are nmoving down the tree. */
        if(prev == NULL || prev->left_leaf == currentNode || prev->right_leaf == currentNode){
            if(currentNode->left_leaf)
                stack1.push(&stack1,currentNode->left_leaf, NULL);
            else if(currentNode->right_leaf)
                stack1.push(&stack1,currentNode->right_leaf, NULL);
            else {
                /* If node is leaf node */
                free(currentNode);
                stack1.pop(&stack1, NULL);
                this_binary_tree->number_elements--;
            }
        }
        /* case 2. We are moving up the tree from left child */
        if(currentNode->left_leaf == prev){
            if(currentNode->right_leaf)
                stack1.push(&stack1,currentNode->right_leaf, NULL);
            else {
                free(currentNode);
                stack1.pop(&stack1, NULL);
                this_binary_tree->number_elements--;
            }
        }
        /* case 3. We are moving up the tree from right child */
        if(currentNode->right_leaf == prev){
            free(currentNode);
            stack1.pop(&stack1, NULL);
            this_binary_tree->number_elements--;
        }
        prev = currentNode;
    }

    destroyStack(&stack1);
    return 1;
}

/**
 *
 * @param this_binary_tree
 * @param callback
 */
ChainingPrint _print_binary_tree(const BinaryTree *this_binary_tree){
    static ChainingPrint methods;//Method chaining
    //DATA STACK
    typedef struct{ pbinary_tree_adt ptb; }struct_ptb;
    static const BinaryTree* b;//copy BinaryTree
    b = this_binary_tree;

    PreorderPrint preorder(const void(*callback)(const void* d)) {
        static PreorderPrint preorder;
        static const void(*f)(const void* d);
        f = callback;

        //NID: NODO RAIZ, NODO IZQUIERDO, NODO DERECHO
        void left(void){
            if(b->number_elements > 0) {
                static Stack stack1;
                stack1 = newStack();
                stack1.push(&stack1, b->binary_tree_adt, NULL);
                while (stack1.size > 0) {
                    pbinary_tree_adt pbinary_tree_adt1 = (pbinary_tree_adt) stack1.peek(&stack1);
                    stack1.pop(&stack1, NULL);

                    if (f != NULL)
                        f(pbinary_tree_adt1->data);

                    if (pbinary_tree_adt1->right_leaf != NULL) {
                        stack1.push(&stack1, (void *) pbinary_tree_adt1->right_leaf, NULL);
                    }
                    if (pbinary_tree_adt1->left_leaf != NULL) {
                        stack1.push(&stack1, (void *) pbinary_tree_adt1->left_leaf, NULL);
                    }
                }
                destroyStack(&stack1);
            }
        }

        //DIN: NODO DERECHO, NODOD IZQUIERDO, NODOD RAIZ
        void right(void) {
            if (b->number_elements > 0) {
                pbinary_tree_adt currentNode = NULL;
                static Stack stack1;
                stack1 = newStack();
                stack1.push(&stack1, b->binary_tree_adt, NULL);
                pbinary_tree_adt prev = NULL;

                while (stack1.size > 0) {
                    currentNode = (pbinary_tree_adt) stack1.peek(&stack1);
                    /* case 1. We are nmoving down the tree. */
                    if (prev == NULL || prev->left_leaf == currentNode || prev->right_leaf == currentNode) {
                        if (currentNode->right_leaf)
                            stack1.push(&stack1, currentNode->right_leaf, NULL);
                        else if (currentNode->left_leaf)
                            stack1.push(&stack1, currentNode->left_leaf, NULL);
                        else {
                            /* If node is leaf node */
                            if (f != NULL)
                                f(currentNode->data);
                            stack1.pop(&stack1, NULL);
                        }
                    }
                    /* case 2. We are moving up the tree from left child */
                    if (currentNode->right_leaf == prev) {
                        if (currentNode->left_leaf)
                            stack1.push(&stack1, currentNode->left_leaf, NULL);
                        else {
                            if (f != NULL)
                                f(currentNode->data);
                            stack1.pop(&stack1, NULL);
                        }
                    }
                    /* case 3. We are moving up the tree from right child */
                    if (currentNode->left_leaf == prev) {
                        if (f != NULL)
                            f(currentNode->data);
                        stack1.pop(&stack1, NULL);
                    }
                    prev = currentNode;
                }

                destroyStack(&stack1);
            }
        }
        preorder.left = left;
        preorder.right = right;
        return preorder;
    }

    InorderPrint inorder( const void(*callback)(const void* d)) {
        static InorderPrint inorder;
        static const void(*f)(const void* d);
        f = callback;

        //IND: NODO IZQUIERDO, NODO RAIZ, NODO DERECHO
        void asc(void){
            if(b->number_elements > 0){
                static Stack stack1;
                stack1 = newStack();
                pbinary_tree_adt pbinary_tree_adt1 = b->binary_tree_adt;
                while(stack1.size > 0 || pbinary_tree_adt1 ){
                    if(pbinary_tree_adt1){
                        stack1.push(&stack1, pbinary_tree_adt1, NULL);
                        pbinary_tree_adt1 = (pbinary_tree_adt)pbinary_tree_adt1->left_leaf;
                    }
                    else {
                        pbinary_tree_adt1 = (pbinary_tree_adt)stack1.peek(&stack1);
                        stack1.pop(&stack1, NULL);
                        if(f != NULL)
                            f(pbinary_tree_adt1->data);
                        pbinary_tree_adt1 =(pbinary_tree_adt) pbinary_tree_adt1->right_leaf;
                    }
                }
                destroyStack(&stack1);
            }
        }

        //DNI: NODO DERECHO, NODO RAIZ, NODO IZQUIERDO
        void des(void){
            if(b->number_elements > 0){
                static Stack stack1;
                stack1 = newStack();
                pbinary_tree_adt pbinary_tree_adt1 = b->binary_tree_adt;
                while(stack1.size > 0 || pbinary_tree_adt1 ){
                    if(pbinary_tree_adt1){
                        stack1.push(&stack1, pbinary_tree_adt1, NULL);
                        pbinary_tree_adt1 = (pbinary_tree_adt)pbinary_tree_adt1->right_leaf;
                    }
                    else {
                        pbinary_tree_adt1 = (pbinary_tree_adt)stack1.peek(&stack1);
                        stack1.pop(&stack1, NULL);
                        if(f != NULL)
                            f(pbinary_tree_adt1->data);
                        pbinary_tree_adt1 =(pbinary_tree_adt) pbinary_tree_adt1->left_leaf;
                    }
                }
                destroyStack(&stack1);
            }
        }

        inorder.asc = asc;
        inorder.des = des;
        return inorder;
    }

    PostorderPrint postorder(const void(*callback)(const void* d)) {
        static PostorderPrint postorder;
        static const void(*f)(const void* d);
        f = callback;

        //IDN: NODO IZQUIERDO, NODO DERECHO, NODO RAIZ
        void left(void){
            if(b->number_elements > 0) {
                pbinary_tree_adt currentNode = NULL;
                static Stack stack1;
                stack1 = newStack();
                stack1.push(&stack1, b->binary_tree_adt, NULL);
                pbinary_tree_adt prev = NULL;

                while (stack1.size > 0) {
                    currentNode = (pbinary_tree_adt) stack1.peek(&stack1);
                    /* case 1. We are nmoving down the tree. */
                    if (prev == NULL || prev->left_leaf == currentNode || prev->right_leaf == currentNode) {
                        if (currentNode->left_leaf)
                            stack1.push(&stack1, currentNode->left_leaf, NULL);
                        else if (currentNode->right_leaf)
                            stack1.push(&stack1, currentNode->right_leaf, NULL);
                        else {
                            /* If node is leaf node */
                            if (f != NULL)
                                f(currentNode->data);
                            stack1.pop(&stack1, NULL);
                        }
                    }
                    /* case 2. We are moving up the tree from left child */
                    if (currentNode->left_leaf == prev) {
                        if (currentNode->right_leaf)
                            stack1.push(&stack1, currentNode->right_leaf, NULL);
                        else {
                            if (f != NULL)
                                f(currentNode->data);
                            stack1.pop(&stack1, NULL);
                        }
                    }
                    /* case 3. We are moving up the tree from right child */
                    if (currentNode->right_leaf == prev) {
                        if (f != NULL)
                            f(currentNode->data);
                        stack1.pop(&stack1, NULL);
                    }
                    prev = currentNode;
                }

                destroyStack(&stack1);
            }
        }

        //NDI: NODO RAIZ, NODO DERECHO, NODO IZQUIERDO
        void right(void){
            if(b->number_elements > 0) {
                static Stack stack1;
                stack1 = newStack();
                stack1.push(&stack1, b->binary_tree_adt, NULL);
                while (stack1.size > 0) {
                    pbinary_tree_adt pbinary_tree_adt1 = (pbinary_tree_adt) stack1.peek(&stack1);
                    stack1.pop(&stack1, NULL);

                    if (f != NULL)
                        f(pbinary_tree_adt1->data);

                    if (pbinary_tree_adt1->left_leaf != NULL) {
                        stack1.push(&stack1, (void *) pbinary_tree_adt1->left_leaf, NULL);
                    }
                    if (pbinary_tree_adt1->right_leaf != NULL) {
                        stack1.push(&stack1, (void *) pbinary_tree_adt1->right_leaf, NULL);
                    }
                }
                destroyStack(&stack1);
            }
        }

        postorder.left = left;
        postorder.right = right;
        return postorder;
    }

    methods.inorder = inorder;
    methods.postorder = postorder;
    methods.preorder = preorder;

    return methods;
}

/**
		134
	   /   \
	  87  145
	 /  \
	1   89
	 \    \
	 23   90
	/  \
   12  45
	  /
	 27

global int i = 0;
 p = NODO
 if(p)


*/