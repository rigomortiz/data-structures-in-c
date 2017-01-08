#include <stdlib.h>
#include <memory.h>
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
void* create(void* data);
int main(int argc, char** argv)
{
    int data = 10;
    int pro = 0;
    Graph grap = newGraph(&data, &pro);
    grap.create_node(&grap, 1, &pro, &data);
    grap.create_node(&grap, 2, &pro, &data);
    grap.create_node(&grap, 1, &pro, &data);
    grap.create_edge(&grap, 1, &pro, &data, 1, 2);
    grap.create_edge(&grap, 2, &pro, &data, 2, 3);
    grap.create_edge(&grap, 3, &pro, &data, 3, 1);
    grap.create_edge(&grap, 4, &pro, &data, 2, 1);
    grap.create_edge(&grap, 5, &pro, &data, 1, 3);

    grap.print(&grap);

    return (EXIT_SUCCESS);
}
