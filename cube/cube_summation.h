//
// Created by regoeco on 18/01/17.
//


#ifndef DATA_STRUCTURES_CUBE_SUMMATION_H
#define DATA_STRUCTURES_CUBE_SUMMATION_H
#include "data_structure/query/query.h"

typedef struct CubeSummation CubeSummation;
struct CubeSummation{
    Query *execute;
};

/**
 *
 * @param max_size
 * @param max_value
 * @param min_value
 * @return
 */
CubeSummation* newCubeSummation( int max_size, double max_value, double min_value);

/**
 *
 * @param this
 */
void destroyCubeSummation(CubeSummation *cubeSummation);


#endif //DATA_STRUCTURES_CUBE_SUMMATION_H
