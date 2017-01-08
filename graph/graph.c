//
// Created by regoeco on 5/01/17.
//
#include "graph.h"

Graph* new_graph(struct PrivateDataGraph *privateDataGraph){
    Graph *g, graph = {
            .private = privateDataGraph,
            .get_num_edges = _get_num_edges,
            .get_num_nodes = _get_num_nodes,
    };
    g = &graph;
    return g;
}

Graph newGraph( void* data, void* properties){
    struct PrivateDataGraph *privateDataGraph = malloc(sizeof(struct PrivateDataGraph));
    privateDataGraph->data = data;
    privateDataGraph->properties = properties;
    List *list = newListPtr(LINEAL, DOUBLE);
    privateDataGraph->list_nodesADT = list;

    //Graph graph = new_graph(privateDataGraph);
    Graph graph = {
            .private = privateDataGraph,
            .get_num_edges = _get_num_edges,
            .get_num_nodes = _get_num_nodes,
            .get_node = _get_node,
            .get_edge = _get_edge,
            .create_edge = _create_edge,
            .create_node = _create_node,
            .print = _print
    };
    return graph;
}

static struct PrivateDataGraph* get_private(Graph *this){
    return (struct PrivateDataGraph*)this->private;
}

static Node* newNode(unsigned int id, void* data, void* properties, List *edges){
    Node *new_node = malloc(sizeof(Node));
    new_node->id = id;
    new_node->data = malloc(sizeof(void*));
    memcpy(new_node->data, data, 1);
    new_node->properties = malloc(sizeof(void*));
    memcpy(new_node->properties, properties, 1);
    new_node->edges = edges;

    return new_node;
}

static Edge* newEdge(unsigned int id, void* properties, void* data, Node* node){
    Edge *new_edge = malloc(sizeof(Edge));
    new_edge->id = id;
    new_edge->properties = malloc(sizeof(void*));
    memcpy(new_edge->properties, properties, 1);
    new_edge->data = malloc(sizeof(void*));
    memcpy(new_edge->data, data, 1);
    new_edge->node = node;

    return new_edge;
}

static Edge* _get_edge(Graph *this, unsigned int dest_node, unsigned int src_node){
    Node *dest = this->get_node(this, dest_node);
    Edge** edges = (Edge**)dest->edges->get(dest->edges).all();
    unsigned int i;
    unsigned int size = dest->edges->get_size(dest->edges);
    for(i = 0; i< size; i++){
        if(edges[i]->id == src_node){
            return edges[i];
        }
    }
    return NULL;
}

static Node* _get_node(Graph *this, unsigned int id){
    struct PrivateDataGraph *private = get_private(this);
    Node ** nodes = (Node**)private->list_nodesADT->get(private->list_nodesADT).all();
    unsigned int size = this->get_num_nodes(this);
    unsigned int i;
    for(i = 0; i< size; i++){
        if(nodes[i]->id == id){
            return nodes[i];
        }
    }
    return NULL;
}

static int _create_node(Graph *this, unsigned int id, void* properties, void* data){
    struct PrivateDataGraph *private = get_private(this);
    Node *new_node = newNode(id, data, properties, newListPtr(LINEAL, DOUBLE));
    private->list_nodesADT->insert(private->list_nodesADT).top(new_node, NULL);
    private->num_nodes++;
    return 1;
}

static int _create_edge(Graph *this, unsigned int id, void* properties, void* data, unsigned int dest, unsigned int src){
    struct PrivateDataGraph *private = get_private(this);
    Node *node_dest = this->get_node(this, dest);
    Node *node_src = this->get_node(this, src);
    Edge *new_edge = newEdge(id, properties, data, node_src);
    node_dest->edges->insert(node_dest->edges).top(new_edge, NULL);
    private->num_edges++;
    return 1;
}

unsigned int _get_num_nodes(Graph *this){
    struct PrivateDataGraph *private = (struct PrivateDataGraph*)this->private;
    return private->num_nodes;
}

unsigned int _get_num_edges(Graph *this){
    struct PrivateDataGraph *private = (struct PrivateDataGraph*)this->private;
    return private->num_edges;
}
void callback_print(void *d);
static void _print(Graph *this){
    struct PrivateDataGraph *private = get_private(this);
    Node ** nodes = (Node**)private->list_nodesADT->get(private->list_nodesADT).all();
    unsigned int size = this->get_num_nodes(this);
    unsigned int i;
    for(i = 0; i< size; i++){
        printf("Node: %d:\n\tEdges:", nodes[i]->id);
        nodes[i]->edges->print(nodes[i]->edges, callback_print);
        printf("\n");

    }
}
void callback_print(void *d){
    Edge *edge = d;
    Node *node = edge->node;
    printf("  %d",node->id);
}