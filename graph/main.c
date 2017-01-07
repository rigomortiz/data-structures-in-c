#include <stdlib.h>
#include "graph.h"
#include "../lists/list.h"

//
// Created by regoeco on 5/01/17.
//
/*
 * N1 <--> N2
 * |       |
 * N3 <----|
 *   Na, Nb
 * E1[ 1, 2 ]
   E2[ 1, 3 ]
 * E3[ 3, 2 ]
 * LG = { N1(N2, N3), N2(N1, N3), N3(N1, N2) }
 */
int main(int argc, char** argv)
{
    Node nodes[3];
    nodes[0].id = 1, nodes[0].data = NULL, nodes[0].properties = NULL;
    nodes[1].id = 2, nodes[1].data = NULL, nodes[1].properties = NULL;
    nodes[2].id = 3, nodes[2].data = NULL, nodes[2].properties = NULL;

    List listNodes = newList(LINEAL, DOUBLE);
    List listEdges = newList(LINEAL, DOUBLE);
    listNodes.insert(&listNodes).top(&nodes[0], NULL);
    listNodes.insert(&listNodes).top(&nodes[1], NULL);
    listNodes.insert(&listNodes).top(&nodes[2], NULL);


    Graph grap = newGraph(listNodes, listEdges, NULL, NULL);


    return (EXIT_SUCCESS);
}

