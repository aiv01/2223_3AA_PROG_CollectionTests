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

void* vector_remove(vector_t* v, void* item){
    size_t position;
    int found = 0;
    for (size_t i = 0; i < v->count; i++)
    {
        void* current = v->items[i];
        if(current == item){
            position = i;
            found = 1;
            break;
        }
    }

    if (!found)
    {
        return NULL;
    }
    
    for (size_t i = position; i < v->count - 1; i++)
    {
        void* next = v->items[i+1];
        v->items[i] = next;
    }
    v->items[v->count - 1] = NULL;
    v->count--;
    
    return item;
}