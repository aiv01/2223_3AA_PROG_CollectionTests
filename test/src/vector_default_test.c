#define CLOVE_SUITE_NAME VectorDefaultTest
#include "clove-unit.h"
#include "vector.h"

vector_t *vector;

CLOVE_SUITE_SETUP() {
    vector = vector_create();
}

CLOVE_SUITE_TEARDOWN() {
    vector_free(vector);
}

CLOVE_TEST(VectorCreation) {
    CLOVE_ULLONG_EQ(0, vector->count);
    CLOVE_ULLONG_EQ(0, vector->size);
    CLOVE_DOUBLE_EQ(0.25, vector->settings.capacity);
    CLOVE_NULL(vector->items);
}

//vector_push

CLOVE_TEST(VectorPushOneElementToEmptyVector) {
    int item1 = 1;
    void *pushed_item = vector_push(vector, &item1);

    CLOVE_ULLONG_EQ(1, vector->count);
    CLOVE_ULLONG_EQ(4, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[0]);
    CLOVE_PTR_EQ(&item1, pushed_item);
}

CLOVE_TEST(VectorPushOneElementToOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    int item2 = 2;
    void *pushed_item = vector_push(vector, &item2);

    CLOVE_ULLONG_EQ(2, vector->count);
    CLOVE_ULLONG_EQ(4, vector->size);
    CLOVE_INT_EQ(2, *((int **)vector->items)[1]);
    CLOVE_PTR_EQ(&item2, pushed_item);
}

CLOVE_TEST(VectorPushOneElementToFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    int item5 = 4;
    void *pushed_item = vector_push(vector, &item5);

    CLOVE_ULLONG_EQ(5, vector->count);
    CLOVE_ULLONG_EQ(20, vector->size);
    CLOVE_INT_EQ(4, *((int **)vector->items)[4]);
    CLOVE_PTR_EQ(&item5, pushed_item);
}

//vector_insert

CLOVE_TEST(VectorInsertOneElementAtValidIndexToEmptyVector) {
    int item1 = 1;
    void *inser_item = vector_insert(vector, &item1, 0);

    CLOVE_ULLONG_EQ(1, vector->count);
    CLOVE_ULLONG_EQ(4, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[0]);
    CLOVE_PTR_EQ(&item1, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtNegativeIndexToEmptyVector) {
    int item1 = 1;
    void *inser_item = vector_insert(vector, &item1, -1);

    CLOVE_ULLONG_EQ(1, vector->count);
    CLOVE_ULLONG_EQ(4, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[0]);
    CLOVE_PTR_EQ(&item1, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtIndexGTCountToEmptyVector) {
    int item1 = 1;
    void *inser_item = vector_insert(vector, &item1, 10);

    CLOVE_ULLONG_EQ(1, vector->count);
    CLOVE_ULLONG_EQ(4, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[0]);
    CLOVE_PTR_EQ(&item1, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtStartIndexToOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    int item2 = 2;
    void *inser_item = vector_insert(vector, &item2, 0);

    CLOVE_ULLONG_EQ(2, vector->count);
    CLOVE_ULLONG_EQ(4, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[1]);
    CLOVE_INT_EQ(2, *((int **)vector->items)[0]);
    CLOVE_PTR_EQ(&item2, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtEndIndexToOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    int item2 = 2;
    void *inser_item = vector_insert(vector, &item2, 1);

    CLOVE_ULLONG_EQ(2, vector->count);
    CLOVE_ULLONG_EQ(4, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector->items)[1]);
    CLOVE_PTR_EQ(&item2, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtNegativeIndexToOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    int item2 = 2;
    void *inser_item = vector_insert(vector, &item2, -1);

    CLOVE_ULLONG_EQ(2, vector->count);
    CLOVE_ULLONG_EQ(4, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector->items)[1]);
    CLOVE_PTR_EQ(&item2, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtIndexGTCountToOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    int item2 = 2;
    void *inser_item = vector_insert(vector, &item2, -1);

    CLOVE_ULLONG_EQ(2, vector->count);
    CLOVE_ULLONG_EQ(4, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector->items)[1]);
    CLOVE_PTR_EQ(&item2, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtStartIndexToFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    int item5 = 5;
    void *inser_item = vector_insert(vector, &item5, 0);

    CLOVE_ULLONG_EQ(5, vector->count);
    CLOVE_ULLONG_EQ(20, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[1]);
    CLOVE_INT_EQ(2, *((int **)vector->items)[2]);
    CLOVE_INT_EQ(3, *((int **)vector->items)[3]);
    CLOVE_INT_EQ(4, *((int **)vector->items)[4]);
    CLOVE_INT_EQ(5, *((int **)vector->items)[0]);
    CLOVE_PTR_EQ(&item5, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtMiddleIndexToFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    int item5 = 5;
    void *inser_item = vector_insert(vector, &item5, 2);

    CLOVE_ULLONG_EQ(5, vector->count);
    CLOVE_ULLONG_EQ(20, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector->items)[1]);
    CLOVE_INT_EQ(3, *((int **)vector->items)[3]);
    CLOVE_INT_EQ(4, *((int **)vector->items)[4]);
    CLOVE_INT_EQ(5, *((int **)vector->items)[2]);
    CLOVE_PTR_EQ(&item5, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtEndIndexToFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    int item5 = 5;
    void *inser_item = vector_insert(vector, &item5, 4);

    CLOVE_ULLONG_EQ(5, vector->count);
    CLOVE_ULLONG_EQ(20, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector->items)[1]);
    CLOVE_INT_EQ(3, *((int **)vector->items)[2]);
    CLOVE_INT_EQ(4, *((int **)vector->items)[3]);
    CLOVE_INT_EQ(5, *((int **)vector->items)[4]);
    CLOVE_PTR_EQ(&item5, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtNegativeIndexToFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    int item5 = 5;
    void *inser_item = vector_insert(vector, &item5, -1);

    CLOVE_ULLONG_EQ(5, vector->count);
    CLOVE_ULLONG_EQ(20, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector->items)[1]);
    CLOVE_INT_EQ(3, *((int **)vector->items)[2]);
    CLOVE_INT_EQ(4, *((int **)vector->items)[3]);
    CLOVE_INT_EQ(5, *((int **)vector->items)[4]);
    CLOVE_PTR_EQ(&item5, inser_item);
}

CLOVE_TEST(VectorInsertOneElementAtIndexGTCountToFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    int item5 = 5;
    void *inser_item = vector_insert(vector, &item5, 10);

    CLOVE_ULLONG_EQ(5, vector->count);
    CLOVE_ULLONG_EQ(20, vector->size);
    CLOVE_INT_EQ(1, *((int **)vector->items)[0]);
    CLOVE_INT_EQ(2, *((int **)vector->items)[1]);
    CLOVE_INT_EQ(3, *((int **)vector->items)[2]);
    CLOVE_INT_EQ(4, *((int **)vector->items)[3]);
    CLOVE_INT_EQ(5, *((int **)vector->items)[4]);
    CLOVE_PTR_EQ(&item5, inser_item);
}

//vector_get_at

CLOVE_TEST(VectorGetAtFromEmptyVector) {
    void *item = vector_get_at(vector, 0);

    CLOVE_NULL(item);
}

CLOVE_TEST(VectorGetAtValidIndexFromOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    void *item = vector_get_at(vector, 0);

    CLOVE_PTR_EQ(&item1, item);
}

CLOVE_TEST(VectorGetAtNegativeIndexFromOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    void *item = vector_get_at(vector, -1);

    CLOVE_NULL(item);
}

CLOVE_TEST(VectorGetAtIndexGTCountFromOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    void *inser_item = vector_get_at(vector, 10);

    CLOVE_NULL(inser_item);
}

CLOVE_TEST(VectorGetAtStartIndexFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *item = vector_get_at(vector, 0);

    CLOVE_PTR_EQ(&item1, item);
}

CLOVE_TEST(VectorGetAtEndIndexFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *item = vector_get_at(vector, 3);

    CLOVE_PTR_EQ(&item4, item);
}

CLOVE_TEST(VectorGetAtValidIndexFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *item = vector_get_at(vector, 2);

    CLOVE_PTR_EQ(&item3, item);
}

CLOVE_TEST(VectorGetAtNegativeIndexFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *item = vector_get_at(vector, -1);

    CLOVE_NULL(item);
}

CLOVE_TEST(VectorGetAtIndexGTCountFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *item = vector_get_at(vector, 10);

    CLOVE_NULL(item);
}

//vector_get_first

CLOVE_TEST(VectorGetFirstFromEmptyVector) {
    void *item = vector_get_first(vector);

    CLOVE_NULL(item);
}

CLOVE_TEST(VectorGetFirstFromOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    void *item = vector_get_first(vector);

    CLOVE_PTR_EQ(&item1, item);
}

CLOVE_TEST(VectorGetFirstFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *item = vector_get_first(vector);

    CLOVE_PTR_EQ(&item1, item);
}

//vector_get_last

CLOVE_TEST(VectorGetLastFromEmptyVector) {
    void *item = vector_get_last(vector);

    CLOVE_NULL(item);
}

CLOVE_TEST(VectorGetLastFromOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    void *item = vector_get_last(vector);

    CLOVE_PTR_EQ(&item1, item);
}

CLOVE_TEST(VectorGetLastFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *item = vector_get_last(vector);

    CLOVE_PTR_EQ(&item4, item);
}

//vector_get_index_of

CLOVE_TEST(VectorGetIndexOfFromEmptyVector) {
    int search_item = 1;
    int index = vector_get_index_of(vector, &search_item);

    CLOVE_UINT_EQ(-1, index);
}

CLOVE_TEST(VectorGetIndexOfExistingItemFromOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    int index = vector_get_index_of(vector, &item1);

    CLOVE_UINT_EQ(0, index);
}

CLOVE_TEST(VectorGetIndexOfNotExistingItemFromOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    int search_item = 2;
    int index = vector_get_index_of(vector, &search_item);

    CLOVE_UINT_EQ(-1, index);
}

CLOVE_TEST(VectorGetIndexOfExistingItemFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    int index = vector_get_index_of(vector, &item2);

    CLOVE_UINT_EQ(1, index);
}

CLOVE_TEST(VectorGetIndexOfNotExistingItemFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    int search_item = 5;
    int index = vector_get_index_of(vector, &search_item);

    CLOVE_UINT_EQ(-1, index);
}

// vector_remove

CLOVE_TEST(VectorRemoveFromEmptyVector) {
    int remove_item = 1;
    void *removed_item = vector_remove(vector, &remove_item);

    CLOVE_NULL(removed_item);
}

CLOVE_TEST(VectorRemoveExistingItemFromOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    void *removed_item = vector_remove(vector, &item1);

    CLOVE_PTR_EQ(&item1, removed_item);
    CLOVE_UINT_EQ(0, vector->count);
}

CLOVE_TEST(VectorRemoveNotExistingItemFromOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    int remove_item = 2;
    void *removed_item = vector_remove(vector, &remove_item);

    CLOVE_NULL(removed_item);
    CLOVE_UINT_EQ(1, vector->count);
}

CLOVE_TEST(VectorRemoveExistingItemFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *removed_item = vector_remove(vector, &item2);

    CLOVE_PTR_EQ(&item2, removed_item);
    CLOVE_UINT_EQ(3, vector->count);
}

CLOVE_TEST(VectorRemoveNotExistingItemFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    int remove_item = 5;
    void *removed_item = vector_remove(vector, &remove_item);

    CLOVE_NULL(removed_item);
    CLOVE_UINT_EQ(4, vector->count);
}

// vector_remove_at

CLOVE_TEST(VectorRemoveAtFromEmptyVector) {
    void *item = vector_remove_at(vector, 0);

    CLOVE_NULL(item);
    CLOVE_UINT_EQ(0, vector->count);
}

CLOVE_TEST(VectorRemoveAtValidIndexFromOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    void *item = vector_remove_at(vector, 0);

    CLOVE_PTR_EQ(&item1, item);
    CLOVE_UINT_EQ(0, vector->count);
}

CLOVE_TEST(VectorRemoveAtNegativeIndexFromOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    void *item = vector_remove_at(vector, -1);

    CLOVE_NULL(item);
    CLOVE_UINT_EQ(1, vector->count);
}

CLOVE_TEST(VectorRemoveAtIndexGTCountFromOneItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);

    void *inser_item = vector_remove_at(vector, 10);

    CLOVE_NULL(inser_item);
    CLOVE_UINT_EQ(1, vector->count);
}

CLOVE_TEST(VectorRemoveAtStartIndexFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *item = vector_remove_at(vector, 0);

    CLOVE_PTR_EQ(&item1, item);
    CLOVE_UINT_EQ(3, vector->count);
}

CLOVE_TEST(VectorRemoveAtEndIndexFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *item = vector_remove_at(vector, 3);

    CLOVE_PTR_EQ(&item4, item);
    CLOVE_UINT_EQ(3, vector->count);
}

CLOVE_TEST(VectorRemoveAtValidIndexFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *item = vector_remove_at(vector, 2);

    CLOVE_PTR_EQ(&item3, item);
    CLOVE_UINT_EQ(3, vector->count);
}

CLOVE_TEST(VectorRemoveAtNegativeIndexFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *item = vector_remove_at(vector, -1);

    CLOVE_NULL(item);
    CLOVE_UINT_EQ(4, vector->count);
}

CLOVE_TEST(VectorRemoveAtIndexGTCountFromFourItemVector) {
    int item1 = 1;
    vector_push(vector, &item1);
    int item2 = 2;
    vector_push(vector, &item2);
    int item3 = 3;
    vector_push(vector, &item3);
    int item4 = 4;
    vector_push(vector, &item4);

    void *item = vector_remove_at(vector, 10);

    CLOVE_NULL(item);
    CLOVE_UINT_EQ(4, vector->count);
}
