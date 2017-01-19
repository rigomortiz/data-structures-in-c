//
// Created by regoeco on 18/01/17.
//

#ifndef DATA_STRUCTURES_QUERY_MANAGER_H
#define DATA_STRUCTURES_QUERY_MANAGER_H

#include <malloc.h>
#include "../ADT/cube.h"

typedef struct Query Query;
struct Query{
    Cube* cube;
    int max_size;
    double max_value;
    double min_value;
    int (*update)(Query *this, int x, int y, int z, int w);
    long double  (*sum)(Query *this, int x1, int y1, int z1, int x2, int y2, int z2);
    int (*new_cube)(Query *this, int size);
};

/**
 *
 * @param size_data
 * @param max_size
 * @param max_value
 * @param min_value
 * @return
 */
Query *newQuery(int max_size, double max_value, double min_value);

/**
 *
 * @param this
 */
void destroyQuery(Query *this);

/**
 * 
 * @param this 
 * @param x 
 * @param y 
 * @param z 
 * @param w 
 */
static int _update_query(Query *this, int x, int y, int z, int w);

/**
 * 
 * @param this 
 * @param x1 
 * @param y1 
 * @param z1 
 * @param x2 
 * @param y2 
 * @param z2 
 * @return 
 */
static  long double  _sum_query(Query *this, int x1, int y1, int z1, int x2, int y2, int z2);

/**
 *
 * @param this
 * @param size
 */
int _new_cube_query(Query *this, int size);


#endif //DATA_STRUCTURES_QUERY_MANAGER_H
