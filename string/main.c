//
// Created by regoeco on 23/12/16.
//
//

#include "../new/new.h"
typedef struct String{
    const void* class;
    char *text;
};
struct String s;
int main ()
{
    void * a = new((void*)s, "a");/*
    void * b = new(String, "b");
    printf("sizeOf(a) == %u\n", sizeOf(a));
    if (differ(a, b))
        puts("ok");
    delete(a), delete(b);*/

    //printf("texto:%s\n", a->text);
//    delete(a);
    return 0;
}