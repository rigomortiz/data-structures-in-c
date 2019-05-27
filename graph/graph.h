#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"
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
    void* data;
};

struct Node{
    unsigned int id;
    void* data;
    List* edges;
};

struct PrivateDataGraph{
    size_t size_data_node;
    size_t size_data_edge;
    unsigned int num_nodes;
    unsigned int num_edges;
    void* data;
    List* list_nodesADT;
};

struct Graph{
    void* private;
    void (*set_size_data_node)(size_t size);
    void (*set_size_data_edge)(size_t size);
    unsigned int (*const get_num_nodes)(Graph *this);
    unsigned int (*const get_num_edges)(Graph *this);
    int (*empty)(Graph *this);
    Node* (*const get_node)(Graph *this, unsigned int id);
    Edge* (*const get_edge)(Graph *this, unsigned int dest_node, unsigned int src_node);
    int (*const create_edge)(Graph *this, unsigned int id, void* data, unsigned int n1, unsigned int n2);
    int (*const create_node)(Graph *this, unsigned int id, void* data);
    void (*const print)(Graph *this, void(*callback)(const void* d, const void* d1));
};

Graph* new_graph(struct PrivateDataGraph *privateDataGraph);
Graph newGraph(void* data, size_t size_data_node, size_t size_data_edge);
void destroyGraph(Graph *graph);
static int _empty_graph(Graph *this);

static void _set_size_data_node(Graph *this, size_t size);
static void _set_size_data_edge(Graph *this, size_t size);
static int _create_node(Graph *this, unsigned int id, void* data);
static int  _create_edge(Graph *this, unsigned int id, void* data, unsigned int n1, unsigned n2);
static unsigned int _get_num_nodes(Graph *this);
static unsigned int _get_num_edges(Graph *this);
static Node* _get_node(Graph *this, unsigned int id);
static Edge* _get_edge(Graph *this, unsigned int n1_node, unsigned int n2_node);
static void _print(Graph* this, void(*callback)(const void* d));

#ifdef __cplusplus
}
#endif

#endif //GRAPH_H
