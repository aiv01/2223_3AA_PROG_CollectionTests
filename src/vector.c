#include "vector.h"
#include <stdlib.h>

vector_t* vector_create() {
    vector_t* result = (vector_t*)malloc(sizeof(vector_t));
    result->items = NULL;
    result->count = 0;
    return result;
}

void vector_free(vector_t* v) {
    free(v->items);
    v->items = NULL;
    v->count = 0;
    free(v);
}

void vector_add(vector_t* v, void* item) {
    v->items = realloc(v->items, sizeof(void*) * (v->count + 1));
    v->items[v->count++] = item;
}