//
// Created by regoeco on 24/12/16.
//

#ifndef NEW_H
#define NEW_H

#include <glob.h>
#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif

struct Class{
    size_t size;
    void* (*construct)(void* self, va_list *app);
    void* (*destruct)(void* self);
    void* (*clone)(const void* self);
    int (*differ)(const void* self, const void* other);
};

void* new(const void* _class, ...);
void delete(void* type);
void *clone(const void* self);

int differ(const void* self, const void* other);
size_t sizeOf(void* self);

#ifdef  __cplusplus
}
#endif
#endif //NEW_H
