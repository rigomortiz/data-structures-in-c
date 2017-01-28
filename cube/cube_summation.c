//
// Created by regoeco on 18/01/17.
//

#include "cube_summation.h"

/**
 *
 * @param max_size
 * @param max_value
 * @param min_value
 * @return
 */
CubeSummation* newCubeSummation( int max_size, double max_value, double min_value){
    CubeSummation *cubeSummation = malloc(sizeof(CubeSummation));
    cubeSummation->execute = newQuery(max_size, max_value, min_value);


    return cubeSummation;
}

/**
 *
 * @param this
 */
void destroyCubeSummation(CubeSummation *this){
    destroyQuery(this->execute);
    free(this->execute);
    free(this);
}