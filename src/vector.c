#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "vector.h"

vector_t *vector_create_with_structure(vector_settings_t setting) {
    setting.capacity = setting.capacity ? fmin(fmax(setting.capacity, 0.1), 1) : 0.25;
    vector_t *result = (vector_t *)malloc(sizeof(vector_t));
    result->items = NULL;
    result->count = 0;
    result->size = 0;
    result->settings = setting;
    return result;
}

void vector_free(vector_t *vector) {
    free(vector->items);
    vector->items = NULL;
    vector->count = 0;
    free(vector);
}

static void **vector_resize(vector_t *vector) {
    int size = ceil((vector->count + 1) / vector->settings.capacity);
    void **new_items = realloc(vector->items, sizeof(void *) * size);
    if (new_items == NULL) {
        return NULL;
    }
    vector->items = new_items;
    vector->size = size;
    return vector->items;
}

void *vector_push(vector_t *vector, void *item) {
    if (vector->size <= vector->count) {
        if (vector_resize(vector) == NULL) {
            return NULL;
        }
    }
    vector->items[vector->count++] = item;
    return vector->items[vector->count - 1];
}

void *vector_insert(vector_t *vector, void *item, unsigned int index) {
    if (index >= vector->count) {
        return vector_push(vector, item);
    }
    if (vector->size <= vector->count) {
        if (vector_resize(vector) == NULL) {
            return NULL;
        }
    }
    for (size_t i = vector->count; i > index; --i) {
        vector->items[i] = vector->items[i - 1];
    }
    vector->items[index] = item;
    ++vector->count;
    return vector->items[index];
}

void *vector_get_at(vector_t *vector, unsigned int index) {
    if (index >= vector->count) {
        return NULL;
    }
    return vector->items[index];
}

void *vector_get_first(vector_t *vector) {
    if (vector->count == 0) {
        return NULL;
    }
    return vector->items[0];
}

void *vector_get_last(vector_t *vector) {
    if (vector->count == 0) {
        return NULL;
    }
    return vector->items[vector->count - 1];
}

int vector_get_index_of(vector_t *vector, void *item) {
    for (size_t i = 0; i < vector->count; ++i) {
        if (vector->items[i] == item) {
            return i;
        }
    }
    return -1;
}

void *vector_remove(vector_t *vector, void *item) {
    int found = 0;
    void *found_item = NULL;
    for (size_t i = 0; i < vector->count; i++) {
        void *current = vector->items[i];
        if (found == 1) {
            vector->items[i - 1] = current;
        } else {
            if (current == item) {
                found_item = vector->items[i];
                found = 1;
            }
        }
    }

    if (found == 1) {
        vector->items[--vector->count] = NULL;
    }

    return found_item;
}

void *vector_remove_at(vector_t *vector, unsigned int index) {
    if (index >= vector->count) {
        return NULL;
    }

    void *item = vector->items[index];

    for (size_t i = index; i < vector->count - 1; i++) {
        vector->items[i] = vector->items[i + 1];
    }
    vector->items[vector->count - 1] = NULL;
    vector->count--;

    return item;
}