//
// Created by regoeco on 5/01/17.
//

#ifndef GRAPH_H
#define GRAPH_H


#include "../lists/list.h"
#include <memory.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Graph Graph;
typedef struct Edge Edge, ELEMENT_EDGE;
typedef struct Node Node, ELEMENT_NODE;

struct Edge{
    unsigned int id;
    Node *node;
    void* properties;
    void* data;
};

struct Node{
    unsigned int id;
    void* properties;
    void* data;
    List* edges;
};

struct PrivateDataGraph{
    unsigned int num_nodes;
    unsigned int num_edges;
    void* data;
    void* properties;
    List* list_nodesADT;
};

struct Graph{
    const void* private;
    unsigned int (*const get_num_nodes)(Graph *this);
    unsigned int (*const get_num_edges)(Graph *this);
    Node* (*const get_node)(Graph *this, unsigned int id);
    Edge* (*const get_edge)(Graph *this, unsigned int dest_node, unsigned int src_node);
    int (*const create_edge)(Graph *this, unsigned int id, void* properties, void* data, unsigned int dest, unsigned int src);
    int (*const create_node)(Graph *this, unsigned int id, void* properties, void* data);
    void (*const print)(Graph *this);
};



Graph* new_graph(struct PrivateDataGraph *privateDataGraph);
Graph newGraph(void* data, void* properties);

static int _create_node(Graph *this, unsigned int id, void* properties, void* data);
static int  _create_edge(Graph *this, unsigned int id, void* properties, void* data, unsigned int dest, unsigned src);
static unsigned int _get_num_nodes(Graph *this);
static unsigned int _get_num_edges(Graph *this);
static Node* _get_node(Graph *this, unsigned int id);
static Edge* _get_edge(Graph *this, unsigned int dest_node, unsigned int src_node);
static void _print(Graph* this);
/*

 InsertNode:
 INPUT: Graph *this, Node *node
 IF NOT NULL graph_adt:
    this.graph_adt.nodes.insert(node);



 */
 /*
  *
  List_Nodes nodes = {n1DP,n2 }
  */

/*
struct BinaryTree{
    void* const private;
    unsigned  int (*const get_num_elements)(BinaryTree *this);
    int (*const insert)(BinaryTree *this, const void* data, void(*const callback_insert)(const void* data), int(*const callback_order)(const void* new, const void* inserted));
    int (*const insert_multiple)(BinaryTree *this, void(*const callback_insert)(const void* data), int(*const callback_order)(const void* new, const void* inserted),  int count, ...);
    struct Find (*const find)(BinaryTree *this, const void* data, int(*const callback)(const void* d1, const void* d2));
    int (*const empty)(BinaryTree *this);
    struct ChainingGet (*const get)(const BinaryTree* this);
    struct ChainingPrint (*const print)(const BinaryTree* this);
};

*/

#ifdef __cplusplus
}
#endif

#endif //GRAPH_H
