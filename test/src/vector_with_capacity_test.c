#define CLOVE_SUITE_NAME VectorWithCapacity
#include "clove-unit.h"
#include "vector.h"

vector_t *vector_with_capacity;

CLOVE_SUITE_SETUP() {
    vector_with_capacity = vector_create(0.5);
}

CLOVE_SUITE_TEARDOWN() {
    vector_free(vector_with_capacity);
}

CLOVE_TEST(VectorCreation) {
    CLOVE_ULLONG_EQ(0, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(0, vector_with_capacity->size);
    CLOVE_DOUBLE_EQ(0.5, vector_with_capacity->settings.capacity);
    CLOVE_NULL(vector_with_capacity->items);
}

//vector_push

CLOVE_TEST(VectorPushOneElementToEmptyVector) {
    int item1 = 1;
    void *pushed_item = vector_push(vector_with_capacity, &item1);

    CLOVE_ULLONG_EQ(1, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(2, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[0]);
    CLOVE_PTR_EQ(&item1, pushed_item);
}

CLOVE_TEST(VectorPushOneElementToOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    int item2 = 2;
    void *pushed_item = vector_push(vector_with_capacity, &item2);

    CLOVE_ULLONG_EQ(2, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(2, vector_with_capacity->size);
    CLOVE_INT_EQ(2, *((int **)vector_with_capacity->items)[1]);
    CLOVE_PTR_EQ(&item2, pushed_item);
}

CLOVE_TEST(VectorPushOneElementToThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    int item4 = 4;
    void *pushed_item = vector_push(vector_with_capacity, &item4);

    CLOVE_ULLONG_EQ(4, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(6, vector_with_capacity->size);
    CLOVE_INT_EQ(4, *((int **)vector_with_capacity->items)[3]);
    CLOVE_PTR_EQ(&item4, pushed_item);
}

//vector_insert

CLOVE_TEST(VectorInsertOneElementAtValidIndexToEmptyVector) {
    int item1 = 1;
    void *inser_item = vector_insert(vector_with_capacity, &item1, 0);

    CLOVE_ULLONG_EQ(1, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(2, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[0]);
    CLOVE_PTR_EQ(&item1, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtNegativeIndexToEmptyVector) {
    int item1 = 1;
    void *inser_item = vector_insert(vector_with_capacity, &item1, -1);

    CLOVE_ULLONG_EQ(1, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(2, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[0]);
    CLOVE_PTR_EQ(&item1, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtIndexGTCountToEmptyVector) {
    int item1 = 1;
    void *inser_item = vector_insert(vector_with_capacity, &item1, 10);

    CLOVE_ULLONG_EQ(1, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(2, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[0]);
    CLOVE_PTR_EQ(&item1, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtStartIndexToOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    int item2 = 2;
    void *inser_item = vector_insert(vector_with_capacity, &item2, 0);

    CLOVE_ULLONG_EQ(2, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(2, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[1]);
    CLOVE_INT_EQ(2, *((int **)vector_with_capacity->items)[0]);
    CLOVE_PTR_EQ(&item2, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtEndIndexToOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    int item2 = 2;
    void *inser_item = vector_insert(vector_with_capacity, &item2, 1);

    CLOVE_ULLONG_EQ(2, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(2, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector_with_capacity->items)[1]);
    CLOVE_PTR_EQ(&item2, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtNegativeIndexToOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    int item2 = 2;
    void *inser_item = vector_insert(vector_with_capacity, &item2, -1);

    CLOVE_ULLONG_EQ(2, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(2, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector_with_capacity->items)[1]);
    CLOVE_PTR_EQ(&item2, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtIndexGTCountToOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    int item2 = 2;
    void *inser_item = vector_insert(vector_with_capacity, &item2, -1);

    CLOVE_ULLONG_EQ(2, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(2, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector_with_capacity->items)[1]);
    CLOVE_PTR_EQ(&item2, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtStartIndexToThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    int item4 = 4;
    void *inser_item = vector_insert(vector_with_capacity, &item4, 0);

    CLOVE_ULLONG_EQ(4, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(6, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[1]);
    CLOVE_INT_EQ(2, *((int **)vector_with_capacity->items)[2]);
    CLOVE_INT_EQ(3, *((int **)vector_with_capacity->items)[3]);
    CLOVE_INT_EQ(4, *((int **)vector_with_capacity->items)[0]);
    CLOVE_PTR_EQ(&item4, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtMiddleIndexToThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    int item4 = 4;
    void *inser_item = vector_insert(vector_with_capacity, &item4, 2);

    CLOVE_ULLONG_EQ(4, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(6, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector_with_capacity->items)[1]);
    CLOVE_INT_EQ(3, *((int **)vector_with_capacity->items)[3]);
    CLOVE_INT_EQ(4, *((int **)vector_with_capacity->items)[2]);
    CLOVE_PTR_EQ(&item4, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtEndIndexToThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    int item4 = 4;
    void *inser_item = vector_insert(vector_with_capacity, &item4, 4);

    CLOVE_ULLONG_EQ(4, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(6, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector_with_capacity->items)[1]);
    CLOVE_INT_EQ(3, *((int **)vector_with_capacity->items)[2]);
    CLOVE_INT_EQ(4, *((int **)vector_with_capacity->items)[3]);
    CLOVE_PTR_EQ(&item4, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtNegativeIndexToThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    int item4 = 4;
    void *inser_item = vector_insert(vector_with_capacity, &item4, -1);

    CLOVE_ULLONG_EQ(4, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(6, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector_with_capacity->items)[1]);
    CLOVE_INT_EQ(3, *((int **)vector_with_capacity->items)[2]);
    CLOVE_INT_EQ(4, *((int **)vector_with_capacity->items)[3]);
    CLOVE_PTR_EQ(&item4, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtIndexGTCountToThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    int item4 = 4;
    void *inser_item = vector_insert(vector_with_capacity, &item4, 10);

    CLOVE_ULLONG_EQ(4, vector_with_capacity->count);
    CLOVE_ULLONG_EQ(6, vector_with_capacity->size);
    CLOVE_INT_EQ(1, *((int **)vector_with_capacity->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector_with_capacity->items)[1]);
    CLOVE_INT_EQ(3, *((int **)vector_with_capacity->items)[2]);
    CLOVE_INT_EQ(4, *((int **)vector_with_capacity->items)[3]);
    CLOVE_PTR_EQ(&item4, inser_item);
}

//vector_get_at

CLOVE_TEST(VectorGetAtFromEmptyVector) {
    void *item = vector_get_at(vector_with_capacity, 0);

    CLOVE_NULL(item);
}

CLOVE_TEST(VectorGetAtValidIndexFromOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    void *item = vector_get_at(vector_with_capacity, 0);

    CLOVE_PTR_EQ(&item1, item);
}

CLOVE_TEST(VectorGetAtNegativeIndexFromOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    void *item = vector_get_at(vector_with_capacity, -1);

    CLOVE_NULL(item);
}

CLOVE_TEST(VectorGetAtIndexGTCountFromOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    void *inser_item = vector_get_at(vector_with_capacity, 10);

    CLOVE_NULL(inser_item);
}

CLOVE_TEST(VectorGetAtStartIndexFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *item = vector_get_at(vector_with_capacity, 0);

    CLOVE_PTR_EQ(&item1, item);
}

CLOVE_TEST(VectorGetAtEndIndexFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *item = vector_get_at(vector_with_capacity, 2);

    CLOVE_PTR_EQ(&item3, item);
}

CLOVE_TEST(VectorGetAtValidIndexFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *item = vector_get_at(vector_with_capacity, 1);

    CLOVE_PTR_EQ(&item2, item);
}

CLOVE_TEST(VectorGetAtNegativeIndexFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *item = vector_get_at(vector_with_capacity, -1);

    CLOVE_NULL(item);
}

CLOVE_TEST(VectorGetAtIndexGTCountFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *item = vector_get_at(vector_with_capacity, 10);

    CLOVE_NULL(item);
}

//vector_get_first

CLOVE_TEST(VectorGetFirstFromEmptyVector) {
    void *item = vector_get_first(vector_with_capacity);

    CLOVE_NULL(item);
}

CLOVE_TEST(VectorGetFirstFromOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    void *item = vector_get_first(vector_with_capacity);

    CLOVE_PTR_EQ(&item1, item);
}

CLOVE_TEST(VectorGetFirstFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *item = vector_get_first(vector_with_capacity);

    CLOVE_PTR_EQ(&item1, item);
}

//vector_get_last

CLOVE_TEST(VectorGetLastFromEmptyVector) {
    void *item = vector_get_last(vector_with_capacity);

    CLOVE_NULL(item);
}

CLOVE_TEST(VectorGetLastFromOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    void *item = vector_get_last(vector_with_capacity);

    CLOVE_PTR_EQ(&item1, item);
}

CLOVE_TEST(VectorGetLastFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *item = vector_get_last(vector_with_capacity);

    CLOVE_PTR_EQ(&item3, item);
}

//vector_get_index_of

CLOVE_TEST(VectorGetIndexOfFromEmptyVector) {
    int search_item = 1;
    int index = vector_get_index_of(vector_with_capacity, &search_item);

    CLOVE_UINT_EQ(-1, index);
}

CLOVE_TEST(VectorGetIndexOfExistingItemFromOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    int index = vector_get_index_of(vector_with_capacity, &item1);

    CLOVE_UINT_EQ(0, index);
}

CLOVE_TEST(VectorGetIndexOfNotExistingItemFromOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    int search_item = 2;
    int index = vector_get_index_of(vector_with_capacity, &search_item);

    CLOVE_UINT_EQ(-1, index);
}

CLOVE_TEST(VectorGetIndexOfExistingItemFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    int index = vector_get_index_of(vector_with_capacity, &item2);

    CLOVE_UINT_EQ(1, index);
}

CLOVE_TEST(VectorGetIndexOfNotExistingItemFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    int search_item = 4;
    int index = vector_get_index_of(vector_with_capacity, &search_item);

    CLOVE_UINT_EQ(-1, index);
}

// vector_remove

CLOVE_TEST(VectorRemoveFromEmptyVector) {
    int remove_item = 1;
    void *removed_item = vector_remove(vector_with_capacity, &remove_item);

    CLOVE_NULL(removed_item);
}

CLOVE_TEST(VectorRemoveExistingItemFromOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    void *removed_item = vector_remove(vector_with_capacity, &item1);

    CLOVE_PTR_EQ(&item1, removed_item);
    CLOVE_UINT_EQ(0, vector_with_capacity->count);
}

CLOVE_TEST(VectorRemoveNotExistingItemFromOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    int remove_item = 2;
    void *removed_item = vector_remove(vector_with_capacity, &remove_item);

    CLOVE_NULL(removed_item);
    CLOVE_UINT_EQ(1, vector_with_capacity->count);
}

CLOVE_TEST(VectorRemoveExistingItemFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *removed_item = vector_remove(vector_with_capacity, &item2);

    CLOVE_PTR_EQ(&item2, removed_item);
    CLOVE_UINT_EQ(2, vector_with_capacity->count);
}

CLOVE_TEST(VectorRemoveNotExistingItemFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    int remove_item = 4;
    void *removed_item = vector_remove(vector_with_capacity, &remove_item);

    CLOVE_NULL(removed_item);
    CLOVE_UINT_EQ(3, vector_with_capacity->count);
}

// vector_remove_at

CLOVE_TEST(VectorRemoveAtFromEmptyVector) {
    void *item = vector_remove_at(vector_with_capacity, 0);

    CLOVE_NULL(item);
    CLOVE_UINT_EQ(0, vector_with_capacity->count);
}

CLOVE_TEST(VectorRemoveAtValidIndexFromOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    void *item = vector_remove_at(vector_with_capacity, 0);

    CLOVE_PTR_EQ(&item1, item);
    CLOVE_UINT_EQ(0, vector_with_capacity->count);
}

CLOVE_TEST(VectorRemoveAtNegativeIndexFromOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    void *item = vector_remove_at(vector_with_capacity, -1);

    CLOVE_NULL(item);
    CLOVE_UINT_EQ(1, vector_with_capacity->count);
}

CLOVE_TEST(VectorRemoveAtIndexGTCountFromOneItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);

    void *inser_item = vector_remove_at(vector_with_capacity, 10);

    CLOVE_NULL(inser_item);
    CLOVE_UINT_EQ(1, vector_with_capacity->count);
}

CLOVE_TEST(VectorRemoveAtStartIndexFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *item = vector_remove_at(vector_with_capacity, 0);

    CLOVE_PTR_EQ(&item1, item);
    CLOVE_UINT_EQ(2, vector_with_capacity->count);
}

CLOVE_TEST(VectorRemoveAtEndIndexFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *item = vector_remove_at(vector_with_capacity, 2);

    CLOVE_PTR_EQ(&item3, item);
    CLOVE_UINT_EQ(2, vector_with_capacity->count);
}

CLOVE_TEST(VectorRemoveAtValidIndexFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *item = vector_remove_at(vector_with_capacity, 1);

    CLOVE_PTR_EQ(&item2, item);
    CLOVE_UINT_EQ(2, vector_with_capacity->count);
}

CLOVE_TEST(VectorRemoveAtNegativeIndexFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *item = vector_remove_at(vector_with_capacity, -1);

    CLOVE_NULL(item);
    CLOVE_UINT_EQ(3, vector_with_capacity->count);
}

CLOVE_TEST(VectorRemoveAtIndexGTCountFromThreeItemVector) {
    int item1 = 1;
    vector_push(vector_with_capacity, &item1);
    int item2 = 2;
    vector_push(vector_with_capacity, &item2);
    int item3 = 3;
    vector_push(vector_with_capacity, &item3);

    void *item = vector_remove_at(vector_with_capacity, 10);

    CLOVE_NULL(item);
    CLOVE_UINT_EQ(3, vector_with_capacity->count);
}