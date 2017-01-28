//
// Created by regoeco on 18/01/17.
//

#ifndef DATA_STRUCTURES_CUBE_H
#define DATA_STRUCTURES_CUBE_H
#include <malloc.h>

typedef struct Cube Cube;
typedef struct Cube{
    int size;
    int num_elements;//size*size*size
    int ***data;
    int (*get_size)(Cube *cube);
    int (*get_num_elements)(Cube *cube);
    int*** (*get_data)(Cube* cube);
    void (*set_size)(Cube *cube, int size);
};
/**
 *
 * @param size
 * @return
 */
Cube *newCube(int size);

/**
 *
 * @param cube
 */
void destroyCube(Cube *cube);

/**
 *
 * @param cube
 * @return
 */
static int _get_size_cube(Cube *cube);

/**
 *
 * @param cube
 * @return
 */
static int _get_num_elements_cube(Cube *cube);

/**
 *
 * @param cube
 * @return
 */
static int*** _get_data_cube(Cube* cube);

/**
 *
 * @param cube
 * @param size
 */
static void _set_size_cube(Cube *cube, int size);

#endif //DATA_STRUCTURES_CUBE_H
