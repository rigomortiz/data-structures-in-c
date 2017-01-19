//
// Created by regoeco on 18/01/17.
//
#include "query.h"

/**
 * 
 * @param size 
 * @return 
 */
Query *newQuery(int max_size, double max_value, double min_value){
    Query *query = malloc(sizeof(Query));
    query->cube = NULL;
    query->max_size = max_size;
    query->max_value = max_value;
    query->min_value = min_value;
    query->sum = _sum_query;
    query->update = _update_query;
    query->new_cube = _new_cube_query;
    return query;
}

/**
 *
 * @param this
 * @param size
 * @return
 */
int _new_cube_query(Query* this, int size){
    if(size != 0){
        if(size <= this->max_size){
            if(this->cube != NULL)
                destroyCube(this->cube);
            this->cube = newCube(size);
            return 1;
        }else{
            printf("\nERROR MAX SIZE IS:%d \n" + this->max_size);
            return 0;
        }
    }else{
        printf("\nERROR MIN SIZE IS: 1\n");
        return 0;
    }
}

/**
 * 
 * @param this 
 */
void destroyQuery(Query *this){
    destroyCube(this->cube);
    free(this->cube);
    free(this);
}

/**
 * 
 * @param this 
 * @param x 
 * @param y 
 * @param z 
 * @param w
 * @return
 */
int _update_query(Query *this, int x, int y, int z, int w){
    printf("%d %d %d %d\n", x, y, z, w);
    if(this->cube != NULL){
        int num_elements = this->cube->get_num_elements(this->cube);
        int limit = this->cube->get_size(this->cube);
        double max_value = this->max_value;
        double min_value = this->min_value;
        if( num_elements >= 1){
            if(x > limit || x < 1){
                printf("\nERROR ATTRIBUTE X\n");
                return 0;
            }
            if(y > limit || y < 1){
                printf("\nERROR ATTRIBUTE Y\n");
                return 0;
            }
            if( z > limit || z < 1){
                printf("\nERROR ATTRIBUTE Z\n");
                return 0;
            }
            if( w >= min_value || w <= max_value){
                printf("\nERROR ATTRIBUTE W\n");
                return 0;
            }
            int ***cube = this->cube->get_data(this->cube);
            cube[x-1][y-1][z-1] = w;
            return 1;
        }else{
            printf("\nERROR SIZE OF CUBE IS: 0\n");
        }
    }else{
        printf("\nERROR CUBE IS NULL\n");
    }
    return 0;
}

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
long double  _sum_query(Query *this, int x1, int y1, int z1, int x2, int y2, int z2){
    printf("%d %d %d %d %d %d\n", x1, y1, z1, x2, y2, z2);

    if(this->cube != NULL){
        int num_elements = this->cube->get_num_elements(this->cube);
        int limit = this->cube->get_size(this->cube);
        double max_value = this->max_value;
        double min_value = this->min_value;
        if( num_elements >= 1){

            if( (1 <= x1 <= x2 <= limit) && (1 <= y1 <= y2 <= limit) && (1 <= z1 <= z2 <= limit) ){
                int ***cube = this->cube->get_data(this->cube);

                int I, J, K;
                I = J = K = 0;
                printf("\n\n\n");

                //for(I=0; I<limit; I++)
                    //for(J=0; J<limit; J++)
                       // for(K=0; K<limit; K++)
                          //  printf("[%d][%d][%d] = %d\n", I+1, J+1, K+1, cube[I][J][K]);





                long double  sum = 0;
                int x = 0;
                int y = 0;
                int z = 0;
                for(x = x1; x <= x2; x++)
                    for(y = y1; y <= y2; y++)
                        for(z = z1; z <= z2; z++) {
                            printf("[%d][%d][%d] = %d\n", x, y, z, cube[x - 1][y - 1][z - 1]);
                            sum += cube[x-1][y-1][z-1];

                        }
/*
                    sum += cube[i-1][y1-1][z1-1];
                    sum += cube[i-1][y2-1][z2-1];

                for(i = y1; i < y2; i++){
                    sum += cube[x1-1][i-1][z1-1];
                    sum += cube[x2-1][i-1][z2-1];
                }
                for(i = z1; i < z2; i++){
                    sum += cube[x1-1][y1-1][i-1];
                    sum += cube[x2-1][y2-1][i-1];
                }
*/
                return sum;
            }else{
                printf("\nERROR IN ATTRIBUTES\n");
            }
        }else{
            printf("\nERROR SIZE OF CUBE IS: 0\n");
        }
    }else{
        printf("\nERROR CUBE IS NULL\n");
    }
    return 0;
}