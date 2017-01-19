//
// Created by regoeco on 18/01/17.
//
#include <stdio.h>
#include "cube_summation.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

char **readLine(char* string);
int main(){
    printf("TEST\n");
    int T;//1 <= T <= 50 TEST
    int N;//1 <= N <= 100 SIZE CUBE
    int M; // 1 <= M <= 1000 QUERYS
    int W; // -10^9 <= W <= 10^9
    int i = 0 , j= 0;
    char *p[] = {
            "UPDATE 2 2 2 1",
            "QUERY 1 1 1 1 1 1",
            "QUERY 1 1 1 2 2 2",
            "QUERY 2 2 2 2 2 2"
    };
    CubeSummation *cubeSummation = newCubeSummation(100, pow(-10, 9), pow(10, 9));
    CubeSummation* this = cubeSummation;

    char **res;
    long double sum;
    T = 1;
    if(1 <= T && T <= 50) {
        for (i = 0; i < T; i++) {
            N = 2;//read
            M = 4;
            if (1 <= N && N <= 100) {
                cubeSummation->execute->new_cube(this->execute, N);
                if (1 <= M && M <= 1000) {
                    for (j = 0; j < M; j++) {
                        res = readLine(p[j]);
                        if (res != NULL) {
                            printf("%s\n", p[j]);
                            if (!strcmp("QUERY", res[0])) {
                               // printf("%s %s %s %s %s %s %s\n", res[0], res[1], res[2], res[3], res[4], res[5], res[6]);
                                sum = cubeSummation->execute->sum(this->execute, atoi(res[1]), atoi(res[2]),atoi(res[3]), atoi(res[4]), atoi(res[5]),atoi(res[6]));
                               printf("Sum: %Lf\n", sum);
                            } else if (!strcmp("UPDATE", res[0])) {
                                //printf("%s %s %s %s %s\n", res[0], res[1], res[2], res[3], res[4]);
                                cubeSummation->execute->update(this->execute, atoi(res[1]), atoi(res[2]), atoi(res[3]), atoi(res[4]));
                            }
                        } else printf("\nERROR GETTING LINE\n");
                    }
                } else printf("\nERROR IN SIZE OF QUERYS\n");
            } else printf("\nERROR IN SIZE OF CUBE\n");
        }
    }else printf("\nERROR IN SIZE OF TEST\n");


    return EXIT_SUCCESS;
}

char **readLine(char* string){
    int len = (int)strlen(string);
    int i = 0;
    int pos = 0;
    char c;
    char inst[7];
    for(i=0; i<len; i++){
        c = string[i];
        if(c == ' '){
            inst[pos] = '\0';
            break;
        }else{
            inst[pos++] = c;
        }
    }
    if(!strcmp("UPDATE", inst)){
        static char* values[5];//x, y, z, w;
        int v = 0;
        char *str_value = malloc(sizeof(char));
        values[v++] = "UPDATE";

        for(i += 1; i<=len; i++){
            c = string[i];
            if(c == ' ' || i == len){
                char* c_new =  malloc(sizeof(char*));
                memcpy(c_new, str_value, strlen(str_value));
                values[v++] = c_new;
                strcpy(str_value, "");
            }else{
                char* c_new =  malloc(sizeof(char));
                memcpy(c_new, &c, 1);
                strcat(str_value, c_new);
            }
        }
        //free(str_value);
        return values;

    }else if(!strcmp("QUERY", inst)){
        static char* values[7];//x1, y1, z1, x2, y2, z2;
        int v = 0;
        char *str_value = malloc(sizeof(char));
        values[v++] = "QUERY";

        for(i += 1; i<=len; i++){
            c = string[i];
            if(c == ' ' || i == len ){
                char* c_new =  malloc(sizeof(char*));
                memcpy(c_new, str_value, strlen(str_value));
                values[v++] = c_new;
                strcpy(str_value, "");
            }else{
                char* c_new =  malloc(sizeof(char));
                memcpy(c_new, &c, 1);
                strcat(str_value, c_new);
            }
        }
        //free(str_value);
        return values;

    }else{
        return NULL;
    }
    return NULL;
}