//#pragma once
#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector_t {
    size_t count;
    void** items;
} vector_t;

vector_t* vector_create();
void vector_free(vector_t*);

void vector_add(vector_t*, void*);

#endif // VECTOR_H