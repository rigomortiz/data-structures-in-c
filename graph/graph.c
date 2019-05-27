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


Graph newGraph( void* data, size_t size_data_node, size_t size_data_edge){
    struct PrivateDataGraph *privateDataGraph = malloc(sizeof(struct PrivateDataGraph));
    privateDataGraph->size_data_node = size_data_node;
    privateDataGraph->size_data_edge = size_data_edge;
    privateDataGraph->data = data;
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
        .print = _print,
        .empty = _empty_graph,
        .set_size_data_edge = _set_size_data_edge,
        .set_size_data_edge = _set_size_data_node

    };
    return graph;
}

static struct PrivateDataGraph* get_private(Graph *this){
    return (struct PrivateDataGraph*)this->private;
}


static Node* newNode(Graph *this, unsigned int id, void* data, List *edges){
    struct PrivateDataGraph *private = get_private(this);

    Node *new_node = malloc(sizeof(Node));
    new_node->id = id;
    new_node->data = malloc(sizeof(void *));
    memcpy(new_node->data, data, private->size_data_node);
    new_node->edges = edges;

    return new_node;
}

/**
 *
 * @param size
 */
static void _set_size_data_node(Graph *this, size_t size){
    struct PrivateDataGraph *private = get_private(this);
    private->size_data_node = size;
}

/**
 *
 * @param size
 */
static void _set_size_data_edge(Graph *this, size_t size){
    struct PrivateDataGraph *private = get_private(this);
    private->size_data_edge = size;
}

static Edge* newEdge(Graph *this, unsigned int id, void* data, Node* node){
    struct PrivateDataGraph *private = get_private(this);

    Edge *new_edge = malloc(sizeof(Edge));
    new_edge->id = id;
    new_edge->data = malloc(sizeof(void*));
    memcpy(new_edge->data, data, private->size_data_node);
    new_edge->node = node;

    return new_edge;
}

/**
 *
 * @param this
 * @param n1_node
 * @param n2_node
 * @return
 */
static Edge* _get_edge(Graph *this, unsigned int n1_node, unsigned int n2_node){
    Node *n1 = this->get_node(this, n1_node);
    Edge** edges = (Edge**)n1->edges->get(n1->edges).all();
    unsigned int i;
    unsigned int size = n1->edges->get_size(n1->edges);
    for(i = 0; i< size; i++){
        if(edges[i]->id == n2_node){
            return edges[i];
        }
    }
    return NULL;
}

/**
 *
 * @param this
 * @param id
 * @return
 */
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

static int _create_node(Graph *this, unsigned int id, void* data){
    struct PrivateDataGraph *private = get_private(this);
    Node *new_node = newNode(this, id, data, newListPtr(LINEAL, DOUBLE));
    private->list_nodesADT->insert(private->list_nodesADT).top(new_node, NULL);
    private->num_nodes++;
    return 1;
}

static int _create_edge(Graph *this, unsigned int id, void* data, unsigned int n1, unsigned int n2){
    struct PrivateDataGraph *private = get_private(this);
    Node *node_n1 = this->get_node(this, n1);
    Node *node_n2 = this->get_node(this, n2);
    Edge *new_edge1 = newEdge(this, id, data, node_n2);
    Edge *new_edge2 = newEdge(this, id, data, node_n1);
    node_n1->edges->insert(node_n1->edges).top(new_edge1, NULL);
    node_n2->edges->insert(node_n2->edges).top(new_edge2, NULL);
    private->num_edges++;
    return 1;
}

/**
 *
 * @param this
 * @return
 */
unsigned int _get_num_nodes(Graph *this){
    struct PrivateDataGraph *private = (struct PrivateDataGraph*)this->private;
    return private->num_nodes;
}

/**
 *
 * @param this
 * @return
 */
unsigned int _get_num_edges(Graph *this){
    struct PrivateDataGraph *private = (struct PrivateDataGraph*)this->private;
    return private->num_edges;
}

/**
 *
 * @param this
 */
static void _print(Graph *this, void(*callback)(const void* d)){
    struct PrivateDataGraph *private = get_private(this);
    Node ** nodes = (Node**)private->list_nodesADT->get(private->list_nodesADT).all();
    unsigned int size = this->get_num_nodes(this);
    unsigned int i;
    for(i = 0; i< size; i++){
        if (callback != NULL){
            callback(nodes[i]);
            nodes[i]->edges->print(nodes[i]->edges, callback);
        }
        //nodes[i]->edges->print(nodes[i]->edges, callback);
    }
}

/**
 *
 * @param this
 * @return
 */
int _empty_graph(Graph *this){
    struct PrivateDataGraph *private = get_private(this);
    Node ** nodes = (Node**)private->list_nodesADT->get(private->list_nodesADT).all();
    unsigned int size = this->get_num_nodes(this);
    unsigned int i;
    for(i = 0; i< size; i++){
        free(nodes[i]->data);
        Edge ** edges = nodes[i]->edges->get(nodes[i]->edges).all();
        unsigned int size_edges = nodes[i]->edges->get_size(nodes[i]->edges);
        unsigned int j;
        for(j = 0; j< size_edges; j++) {
            free(edges[i]->data);
        }
        destroyList(nodes[i]->edges);
        free(*edges);
    }

    free(*nodes);
    private->num_edges = 0;
    private->num_nodes = 0;
    return 0;
}

/**
 *
 * @param this
 */
void destroyGraph(Graph *this){
    this->empty(this);
    free(this->private);
}

