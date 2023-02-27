#define CLOVE_SUITE_NAME VectorTest
#include "clove-unit.h"
#include "vector.h"

vector_t* vector;

CLOVE_SUITE_SETUP()
{
	vector = vector_create();
}

CLOVE_SUITE_TEARDOWN()
{
	vector_free(vector);
}

CLOVE_TEST(VectorCreation)
{
	CLOVE_NOT_NULL(vector);
	CLOVE_INT_EQ(0, vector->count);
	CLOVE_NULL(vector->items);
}

CLOVE_TEST(VectorAddOneItemToEmptyVector)
{
	int item = 1;
	vector_add(vector, &item);

	CLOVE_ULLONG_EQ(1, vector->count);
	CLOVE_INT_EQ(1, *((int**)vector->items)[0]);
}

CLOVE_TEST(VectorAddItemToOneItemVector)
{
	int item1 = 1;
	vector_add(vector, &item1);

	int item2 = 2;
	vector_add(vector, &item2);

	CLOVE_ULLONG_EQ(2, vector->count);
	CLOVE_INT_EQ(1, *((int**)vector->items)[0]);
	CLOVE_INT_EQ(2, *((int**)vector->items)[1]);
}

CLOVE_TEST(VectorRemoveItemFromOneItemVector)
{
	int item1 = 1;
	vector_add(vector, &item1);

	void* removed = vector_remove(vector, &item1);
	CLOVE_ULLONG_EQ(0, vector->count);
	CLOVE_PTR_EQ(&item1, removed);
	CLOVE_NULL(((int**)vector->items)[0]);
}

CLOVE_TEST(VectorRemoveSecondItemFromThreeItemVector)
{
	int item1 = 1;
	int item2 = 2;
	int item3 = 3;
	vector_add(vector, &item1);
	vector_add(vector, &item2);
	vector_add(vector, &item3);

	void* removed = vector_remove(vector, &item2);
	CLOVE_ULLONG_EQ(2, vector->count);
	CLOVE_PTR_EQ(&item2, removed);
	CLOVE_INT_EQ(1, *((int**)vector->items)[0]);
	CLOVE_INT_EQ(3, *((int**)vector->items)[1]);
}