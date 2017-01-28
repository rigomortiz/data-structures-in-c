////
//// Created by regoeco on 18/01/17.
////
//
//
//#include <malloc.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//
//
//#ifndef DATA_STRUCTURES_CUBE_H
//#define DATA_STRUCTURES_CUBE_H
//
//
//typedef struct Cube Cube;
//typedef struct Cube{
//    int size;
//    int num_elements;//size*size*size
//    int ***data;
//    int (*get_size)(Cube *cube);
//    int (*get_num_elements)(Cube *cube);
//    int*** (*get_data)(Cube* cube);
//    void (*set_size)(Cube *cube, int size);
//};
///**
// *
// * @param size
// * @return
// */
//Cube *newCube(int size);
//
///**
// *
// * @param cube
// */
//void destroyCube(Cube *cube);
//
///**
// *
// * @param cube
// * @return
// */
//static int _get_size_cube(Cube *cube);
//
///**
// *
// * @param cube
// * @return
// */
//static int _get_num_elements_cube(Cube *cube);
//
///**
// *
// * @param cube
// * @return
// */
//static int*** _get_data_cube(Cube* cube);
//
///**
// *
// * @param cube
// * @param size
// */
//static void _set_size_cube(Cube *cube, int size);
//
//#endif //DATA_STRUCTURES_CUBE_H
//
//#ifndef DATA_STRUCTURES_QUERY_MANAGER_H
//#define DATA_STRUCTURES_QUERY_MANAGER_H
//
//typedef struct Query Query;
//struct Query{
//    Cube* cube;
//    int max_size;
//    double max_value;
//    double min_value;
//    int (*update)(Query *this, int x, int y, int z, int w);
//    long double  (*sum)(Query *this, int x1, int y1, int z1, int x2, int y2, int z2);
//    int (*new_cube)(Query *this, int size);
//};
//
///**
// *
// * @param size_data
// * @param max_size
// * @param max_value
// * @param min_value
// * @return
// */
//Query *newQuery(int max_size, double max_value, double min_value);
//
///**
// *
// * @param this
// */
//void destroyQuery(Query *this);
//
///**
// *
// * @param this
// * @param x
// * @param y
// * @param z
// * @param w
// */
//static int _update_query(Query *this, int x, int y, int z, int w);
//
///**
// *
// * @param this
// * @param x1
// * @param y1
// * @param z1
// * @param x2
// * @param y2
// * @param z2
// * @return
// */
//static  long double  _sum_query(Query *this, int x1, int y1, int z1, int x2, int y2, int z2);
//
///**
// *
// * @param this
// * @param size
// */
//int _new_cube_query(Query *this, int size);
//
//
//#endif //DATA_STRUCTURES_QUERY_MANAGER_H
//
//
//
//
//#ifndef DATA_STRUCTURES_CUBE_SUMMATION_H
//#define DATA_STRUCTURES_CUBE_SUMMATION_H
//#include "data_structure/query/query.h"
//
//typedef struct CubeSummation CubeSummation;
//struct CubeSummation{
//    Query *execute;
//};
//
///**
// *
// * @param max_size
// * @param max_value
// * @param min_value
// * @return
// */
//CubeSummation* newCubeSummation( int max_size, double max_value, double min_value);
//
///**
// *
// * @param this
// */
//void destroyCubeSummation(CubeSummation *cubeSummation);
//
//
//#endif //DATA_STRUCTURES_CUBE_SUMMATION_H
//
//
///**
// *
// * @param size
// * @return
// */
//Cube *newCube(int size){
//    Cube *cube = malloc(sizeof(Cube));
//    cube->size = size;
//    cube->num_elements = size*size*size;
//    cube->get_data = _get_data_cube;
//    cube->get_num_elements = _get_num_elements_cube;
//    cube->get_size = _get_size_cube;
//    cube->set_size = _set_size_cube;
//
//    cube->data = calloc((size_t)size, sizeof(int*));
//    int i = 0, j = 0, k = 0;
//    for(i = 0; i < size; i++){
//        cube->data[i] = calloc((size_t)size, sizeof(int*));
//        for (j = 0; j < size; j++) {
//            cube->data[i][j] = calloc((size_t)size, sizeof(int*));
//        }
//    }
//
//    for(i = 0; i< size; i++)
//        for(j = 0; j < size; j++)
//            for(k=0; k<size; k++)
//                cube->data[i][j][k] = 0;
//
//    return cube;
//}
//
///**
// *
// * @param cube
// */
//void destroyCube(Cube *cube){
//    int size = cube->get_size(cube);
//    int i = 0;
//    int j = 0;
//    int ***d;
//    for(i = 0; i < size; i++){
//        for(j = 0; j < size; j++){
//            d = cube->get_data(cube);
//            free(d[i][j]);
//        }
//        free(d[i]);
//    }
//    free(cube->data);
//    free(cube);
//}
//
///**
// *
// * @param cube
// * @return
// */
//int _get_size_cube(Cube *cube){
//    return cube->size;
//}
//
///**
// *
// * @param cube
// * @return
// */
//int _get_num_elements_cube(Cube *cube){
//    return cube->num_elements;
//}
//
///**
// *
// * @param cube
// * @return
// */
//int*** _get_data_cube(Cube* cube){
//    return cube->data;
//}
//
///**
// *
// * @param cube
// * @param size
// */
//void _set_size_cube(Cube *cube, int size){
//    cube->size = size;
//}
//
//
//
///**
// *
// * @param size
// * @return
// */
//Query *newQuery(int max_size, double max_value, double min_value){
//    Query *query = malloc(sizeof(Query));
//    query->cube = NULL;
//    query->max_size = max_size;
//    query->max_value = max_value;
//    query->min_value = min_value;
//    query->sum = _sum_query;
//    query->update = _update_query;
//    query->new_cube = _new_cube_query;
//    return query;
//}
//
///**
// *
// * @param this
// * @param size
// * @return
// */
//int _new_cube_query(Query* this, int size){
//    if(size != 0){
//        if(size <= this->max_size){
//            if(this->cube != NULL)
//                destroyCube(this->cube);
//            this->cube = newCube(size);
//            return 1;
//        }else{
//            printf("\nERROR MAX SIZE IS:%d \n" + this->max_size);
//            return 0;
//        }
//    }else{
//        printf("\nERROR MIN SIZE IS: 1\n");
//        return 0;
//    }
//}
//
///**
// *
// * @param this
// */
//void destroyQuery(Query *this){
//    destroyCube(this->cube);
//    free(this->cube);
//    free(this);
//}
//
///**
// *
// * @param this
// * @param x
// * @param y
// * @param z
// * @param w
// * @return
// */
//int _update_query(Query *this, int x, int y, int z, int w){
//    printf("%d %d %d %d\n", x, y, z, w);
//    if(this->cube != NULL){
//        int num_elements = this->cube->get_num_elements(this->cube);
//        int limit = this->cube->get_size(this->cube);
//        double max_value = this->max_value;
//        double min_value = this->min_value;
//        if( num_elements >= 1){
//            if(x > limit || x < 1){
//                printf("\nERROR ATTRIBUTE X\n");
//                return 0;
//            }
//            if(y > limit || y < 1){
//                printf("\nERROR ATTRIBUTE Y\n");
//                return 0;
//            }
//            if( z > limit || z < 1){
//                printf("\nERROR ATTRIBUTE Z\n");
//                return 0;
//            }
//            if( w >= min_value || w <= max_value){
//                printf("\nERROR ATTRIBUTE W\n");
//                return 0;
//            }
//            int ***cube = this->cube->get_data(this->cube);
//            cube[x-1][y-1][z-1] = w;
//            return 1;
//        }else{
//            printf("\nERROR SIZE OF CUBE IS: 0\n");
//        }
//    }else{
//        printf("\nERROR CUBE IS NULL\n");
//    }
//    return 0;
//}
//
///**
// *
// * @param this
// * @param x1
// * @param y1
// * @param z1
// * @param x2
// * @param y2
// * @param z2
// * @return
// */
//long double  _sum_query(Query *this, int x1, int y1, int z1, int x2, int y2, int z2){
//    printf("%d %d %d %d %d %d\n", x1, y1, z1, x2, y2, z2);
//
//    if(this->cube != NULL){
//        int num_elements = this->cube->get_num_elements(this->cube);
//        int limit = this->cube->get_size(this->cube);
//        if( num_elements >= 1){
//            if( (1 <= x1 <= x2 <= limit) && (1 <= y1 <= y2 <= limit) && (1 <= z1 <= z2 <= limit) ){
//                int ***cube = this->cube->get_data(this->cube);
//                long double  sum = 0;
//                int x = 0;
//                int y = 0;
//                int z = 0;
//                for(x = x1; x <= x2; x++)
//                    for(y = y1; y <= y2; y++)
//                        for(z = z1; z <= z2; z++) {
//                            sum += cube[x-1][y-1][z-1];
//                        }
//                return sum;
//            }else{
//                printf("\nERROR IN ATTRIBUTES\n");
//            }
//        }else{
//            printf("\nERROR SIZE OF CUBE IS: 0\n");
//        }
//    }else{
//        printf("\nERROR CUBE IS NULL\n");
//    }
//    return 0;
//}
//
//
///**
// *
// * @param max_size
// * @param max_value
// * @param min_value
// * @return
// */
//CubeSummation* newCubeSummation( int max_size, double max_value, double min_value){
//    CubeSummation *cubeSummation = malloc(sizeof(CubeSummation));
//    cubeSummation->execute = newQuery(max_size, max_value, min_value);
//
//
//    return cubeSummation;
//}
//
///**
// *
// * @param this
// */
//void destroyCubeSummation(CubeSummation *this){
//    destroyQuery(this->execute);
//    free(this->execute);
//    free(this);
//}
//
//
//
//char **readLine(char* string);
//int main(){
//    printf("TEST\n");
//    int T;//1 <= T <= 50 TEST
//    int N;//1 <= N <= 100 SIZE CUBE
//    int M; // 1 <= M <= 1000 QUERYS
//    int W; // -10^9 <= W <= 10^9
//    int i = 0 , j= 0;
//    char *p[] = {
//            "UPDATE 2 2 2 1",
//            "QUERY 1 1 1 1 1 1",
//            "QUERY 1 1 1 2 2 2",
//            "QUERY 2 2 2 2 2 2"
//    };
//    CubeSummation *cubeSummation = newCubeSummation(100, pow(-10, 9), pow(10, 9));
//    CubeSummation* this = cubeSummation;
//
//    char **res;
//    long double sum;
//    T = 1;
//    if(1 <= T && T <= 50) {
//        for (i = 0; i < T; i++) {
//            N = 2;//read
//            M = 4;
//            if (1 <= N && N <= 100) {
//                cubeSummation->execute->new_cube(this->execute, N);
//                if (1 <= M && M <= 1000) {
//                    for (j = 0; j < M; j++) {
//                        res = readLine(p[j]);
//                        if (res != NULL) {
//                            printf("%s\n", p[j]);
//                            if (!strcmp("QUERY", res[0])) {
//                                // printf("%s %s %s %s %s %s %s\n", res[0], res[1], res[2], res[3], res[4], res[5], res[6]);
//                                sum = cubeSummation->execute->sum(this->execute, atoi(res[1]), atoi(res[2]),atoi(res[3]), atoi(res[4]), atoi(res[5]),atoi(res[6]));
//                                printf("Sum: %Lf\n", sum);
//                            } else if (!strcmp("UPDATE", res[0])) {
//                                //printf("%s %s %s %s %s\n", res[0], res[1], res[2], res[3], res[4]);
//                                cubeSummation->execute->update(this->execute, atoi(res[1]), atoi(res[2]), atoi(res[3]), atoi(res[4]));
//                            }
//                        } else printf("\nERROR GETTING LINE\n");
//                    }
//                } else printf("\nERROR IN SIZE OF QUERYS\n");
//            } else printf("\nERROR IN SIZE OF CUBE\n");
//        }
//    }else printf("\nERROR IN SIZE OF TEST\n");
//
//
//    return EXIT_SUCCESS;
//}
//
//char **readLine(char* string){
//    int len = (int)strlen(string);
//    int i = 0;
//    int pos = 0;
//    char c;
//    char inst[7];
//    for(i=0; i<len; i++){
//        c = string[i];
//        if(c == ' '){
//            inst[pos] = '\0';
//            break;
//        }else{
//            inst[pos++] = c;
//        }
//    }
//    if(!strcmp("UPDATE", inst)){
//        static char* values[5];//x, y, z, w;
//        int v = 0;
//        char *str_value = malloc(sizeof(char));
//        values[v++] = "UPDATE";
//
//        for(i += 1; i<=len; i++){
//            c = string[i];
//            if(c == ' ' || i == len){
//                char* c_new =  malloc(sizeof(char*));
//                memcpy(c_new, str_value, strlen(str_value));
//                values[v++] = c_new;
//                strcpy(str_value, "");
//            }else{
//                char* c_new =  malloc(sizeof(char));
//                memcpy(c_new, &c, 1);
//                strcat(str_value, c_new);
//            }
//        }
//        //free(str_value);
//        return values;
//
//    }else if(!strcmp("QUERY", inst)){
//        static char* values[7];//x1, y1, z1, x2, y2, z2;
//        int v = 0;
//        char *str_value = malloc(sizeof(char));
//        values[v++] = "QUERY";
//
//        for(i += 1; i<=len; i++){
//            c = string[i];
//            if(c == ' ' || i == len ){
//                char* c_new =  malloc(sizeof(char*));
//                memcpy(c_new, str_value, strlen(str_value));
//                values[v++] = c_new;
//                strcpy(str_value, "");
//            }else{
//                char* c_new =  malloc(sizeof(char));
//                memcpy(c_new, &c, 1);
//                strcat(str_value, c_new);
//            }
//        }
//        //free(str_value);
//        return values;
//
//    }else{
//        return NULL;
//    }
//    return NULL;
//}