//
// Created by regoeco on 18/01/17.
//
#include <malloc.h>
#include "cube.h"

/**
 *
 * @param size
 * @return
 */
Cube *newCube(int size){
    Cube *cube = malloc(sizeof(Cube));
    cube->size = size;
    cube->num_elements = size*size*size;
    cube->get_data = _get_data_cube;
    cube->get_num_elements = _get_num_elements_cube;
    cube->get_size = _get_size_cube;
    cube->set_size = _set_size_cube;

    cube->data = calloc((size_t)size, sizeof(int*));
    int i = 0, j = 0, k = 0;
    for(i = 0; i < size; i++){
        cube->data[i] = calloc((size_t)size, sizeof(int*));
        for (j = 0; j < size; j++) {
            cube->data[i][j] = calloc((size_t)size, sizeof(int*));
        }
    }

    for(i = 0; i< size; i++)
        for(j = 0; j < size; j++)
            for(k=0; k<size; k++)
                cube->data[i][j][k] = 0;

    return cube;
}

/**
 *
 * @param cube
 */
void destroyCube(Cube *cube){
    int size = cube->get_size(cube);
    int i = 0;
    int j = 0;
    int ***d;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            d = cube->get_data(cube);
            free(d[i][j]);
        }
        free(d[i]);
    }
    free(cube->data);
    free(cube);
}

/**
 *
 * @param cube
 * @return
 */
 int _get_size_cube(Cube *cube){
    return cube->size;
}

/**
 *
 * @param cube
 * @return
 */
 int _get_num_elements_cube(Cube *cube){
    return cube->num_elements;
}

/**
 *
 * @param cube
 * @return
 */
 int*** _get_data_cube(Cube* cube){
    return cube->data;
}

/**
 *
 * @param cube
 * @param size
 */
 void _set_size_cube(Cube *cube, int size){
    cube->size = size;
}