//
// Created by regoeco on 5/01/17.
//

#ifndef GRAPH_H
#define GRAPH_H


#include "../lists/list.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Graph Graph;
typedef struct GraphADT* GraphADT, ELEMENT_GRAPH;
typedef struct Edge Edge, ELEMENT_EDGE;
typedef struct Node Node, ELEMENT_NODE;
typedef struct NodeADT* NodeADT ;

struct NodeADT{
    List* edgesADT;
};

struct GraphADT{
    List* list_nodesADT;
};

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
    void* properties;
    unsigned int num_elements;
    void* data;
    GraphADT graphADT;
};

struct Graph{
    const void* private;
    unsigned int (*const get_num_nodes)(Graph *this);
    unsigned int (*const get_num_edges)(Graph *this);
    int (*const create_node)(Graph *this, Node node);
    int (*const create_edge)(Graph *this, Node node);

    int (*const insert_multiples)(Graph *this, Node *node, Edge *edge);
    int (*const insert_node)(Graph *this, Node *node);
    int (*const insert_edge)(Graph *this, Edge *edge);
};



static Graph* new_graph(struct PrivateDataGraph *privateDataGraph);
Graph newGraph(void* data, void* properties);

static int _create_node(Graph *this, Node node);
static int _create_edge(Graph *this, Edge edge);



static unsigned int _get_num_nodes(Graph *this);
static unsigned int _get_num_edges(Graph *this);
static int _insert_multiples(Graph *this, Node *node, Edge *edge);
static int _insert_node(Graph *this, Node *node);
static int _insert_edge(Graph *this, Edge *edge);

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
