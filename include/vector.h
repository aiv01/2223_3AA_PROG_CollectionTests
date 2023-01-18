//#pragma once
#ifndef __VECTOR_H
#define __VECTOR_H

typedef struct vector_t {
    size_t count;
    void **items;
} vector_t;

vector_t *vector_create();
void vector_free(vector_t *);

void vector_add(vector_t *, void *);

void *vector_remove(vector_t *, void *);

#endif // __VECTOR_H