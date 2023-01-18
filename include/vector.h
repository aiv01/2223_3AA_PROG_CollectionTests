//#pragma once
#ifndef __VECTOR_H
#define __VECTOR_H

#define vector_create(...) vector_create_with_structure((vector_settings_t){__VA_ARGS__});

typedef struct vector_settings {
    double capacity;
} vector_settings_t;

typedef struct vector {
    vector_settings_t settings;
    size_t count;
    size_t size;
    void **items;
} vector_t;


vector_t *vector_create_with_structure(vector_settings_t);

void vector_free(vector_t *);

void *vector_push(vector_t *, void *);

void *vector_insert(vector_t *, void *, unsigned int);

void *vector_get_at(vector_t *, unsigned int);

void *vector_get_first(vector_t *);

void *vector_get_last(vector_t *);

int vector_get_index_of(vector_t *, void *);

void *vector_remove(vector_t *, void *);

void *vector_remove_at(vector_t *, unsigned int);

#endif // __VECTOR_H