//
// Created by regoeco on 5/01/17.
//
#include "graph.h"
#include "../lists/list.h"

static Graph* new_graph(struct PrivateDataGraph *privateDataGraph){
    Graph *g, graph = {
            .private = privateDataGraph,
            .get_num_edges = _get_num_edges,
            .get_num_nodes = _get_num_nodes,
            .insert_edge = _insert_edge,
            .insert_node = _insert_node,
            .insert_multiples = _insert_multiples,
    };
    g = &graph;
    return g;
}


Graph newGraph( void* data, void* properties){
    struct PrivateDataGraph *privateDataGraph = malloc(sizeof(struct PrivateDataGraph));
    privateDataGraph->data = data;
    privateDataGraph->properties = properties;
    privateDataGraph->graphADT = NULL;

    //Graph graph = new_graph(privateDataGraph);
    Graph graph = {
            .private = privateDataGraph,
            .get_num_edges = _get_num_edges,
            .get_num_nodes = _get_num_nodes,
            .insert_edge = _insert_edge,
            .insert_node = _insert_node,
            .insert_multiples = _insert_multiples
    };
    return graph;
}
/*
 * Node{
     int id,
     void* properties_node,
     void* properties_edge,
     void* data_edge,
     void* data_node,
     List nodes(&Node)
 * }
 */

static int _create_node(Graph *this, Node node){
    Node *new_node = malloc(sizeof(Node));
    new_node->id = node.id;
    new_node->data = node.data;
    new_node->properties = node.properties;
    new_node->edges = newListPtr(LINEAL, DOUBLE);
    struct PrivateDataGraph *private = (struct PrivateDataGraph*)this->private;
    private->graphADT->list_nodesADT->insert(private->graphADT->list_nodesADT).top(new_node, NULL);
}

static int _create_edge(Graph *this, Edge edge){

}




unsigned int _get_num_nodes(Graph *this){

}

unsigned int _get_num_edges(Graph *this){

}

int _insert_multiples(Graph *this, Node *node, Edge *edge){

}

int _insert_node(Graph *this, Node *node){

}

int _insert_edge(Graph *this, Edge *edge){


}




/**
 *  a -- b -- d
 *  |
 *  c -- e
 *  |    |
 *  f -- g
 *
 *  List_Nodes = {
 *      a0(DP),
 *      b1(DP),
 *      c2(DP),
 *      d3(DP),
 *      e4(DP),
 *      f5(DP),
 *      g6(DP)
 *  }
 *  List Aristas= {
 *      (a<->b)(DP),
 *      (b<->d)(DP),
 *      (a<->c)(DP),
 *      (c<->e)(DP),
 *      (c<->f)(DP),
 *      (f<->g)(DP),
 *      (g<->e)(DP)
 *  }
 *
 *  Grapt( List = { Nodes( List = { Edges() ,... } ) ) ,...} )
 *
*/