//
// Created by regoeco on 24/12/16.
//
#include <malloc.h>
#include <assert.h>
#include "new.h"

/**
 *
 * @param _class
 * @return
 */
void* new(const void* _class, ...){
    const struct Class *class = _class;
    void* p = calloc(1, class->size);
    assert(p);
    *(const struct Class **)p = class;

    if(class->construct){
        va_list ap;
        va_start(ap, _class);
        p = class->construct(p, &ap);
        va_end(ap);
    }
    return p;
}

void delete(void* self){
    const struct Class **cp = self;
    if(self && *cp && (*cp)->destruct){
        self = (*cp)->destruct(self);
    }
    free(self);
}

int differ(const void* self, const void* other){
    const struct Class* const *cp  = self;
    assert(self && *cp && (*cp)->differ);
    return (*cp)->differ(self, other);
}

size_t sizeOf(void* self){
    const struct Class * const * p = self;
    assert(self && *p);
    return (*p)->size;
}

void *clone(const void* _self){
    const struct Class *self = _self;
    return new(self);
}