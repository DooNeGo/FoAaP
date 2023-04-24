#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "DynamicArray.h"

typedef struct Array
{
    void **elems;
    unsigned int count;
    unsigned int capacity;
    unsigned int elemSize;
} Array;

Array *ArrayConstructor(unsigned int initialSize, unsigned int elemSize)
{
    if (initialSize == 0)
        initialSize = 2;
    Array *arr = (Array *)malloc(sizeof(Array));
    arr->count = 0;
    arr->capacity = initialSize;
    arr->elems = (void **)malloc(initialSize * 8);
    arr->elemSize = elemSize;
    return arr;
}

void ResizeArr(Array *arr)
{
    int newSize = arr->capacity * 2;
    void **newArr = (void **)malloc(newSize * 8);
    memcpy(newArr, arr->elems, arr->capacity * 8);
    free(arr->elems);
    arr->capacity = newSize;
    arr->elems = newArr;
}

CodeStatus ArrayAdd(Array *arr, const void *elem)
{
    void *newArrElem = malloc(arr->elemSize);
    memcpy(newArrElem, elem, arr->elemSize);
    if (arr->count == arr->capacity)
        ResizeArr(arr);
    arr->elems[arr->count] = newArrElem;
    arr->count++;
    return SUCCESSFUL_CODE;
}

CodeStatus ArrayAddPtr(Array *arr, void *newElem)
{
    if (arr->count == arr->capacity)
        ResizeArr(arr);
    arr->elems[arr->count] = newElem;
    arr->count++;
    return SUCCESSFUL_CODE;
}

void *ArrayGetElem(Array *arr, unsigned int index)
{
    if (index >= arr->count)
        return NULL;
    return arr->elems[index];
}

CodeStatus ArraySetPtrElem(Array *arr, void *newElem, unsigned int index)
{
    if (index >= arr->count)
        return UNSUCCESSFUL_CODE;
    arr->elems[index] = newElem;
    return SUCCESSFUL_CODE;
}

CodeStatus ArraySetElem(Array *arr, const void *elem, unsigned int index)
{
    void *newElem = malloc(arr->elemSize);
    memcpy(newElem, elem, arr->elemSize);
    if (index >= arr->count)
        return UNSUCCESSFUL_CODE;
    arr->elems[index] = newElem;
    return SUCCESSFUL_CODE;
}

int ArrayCount(const Array *arr)
{
    return arr->count;
}

int ArrayCapacity(const Array *arr)
{
    return arr->capacity;
}

CodeStatus ArrayRemoveElemAt(Array *arr, unsigned int index)
{
    if (index >= arr->count || arr == NULL)
        return UNSUCCESSFUL_CODE;
    for (int i = index; i < arr->count - 1; i++)
    {
        arr->elems[i] = arr->elems[i + 1];
    }
    arr->count--;
    return SUCCESSFUL_CODE;
}

CodeStatus ArrayRemoveElem(Array *arr, const void *elem)
{
    for (int index = 0; index < arr->count; index++)
    {
        if (memcmp(arr->elems[index], elem, arr->elemSize) == 0)
        {
            return ArrayRemoveElemAt(arr, index);
        }
    }
    return UNSUCCESSFUL_CODE;
}

CodeStatus ArrayClear(Array *arr)
{
    if (arr == NULL)
        return UNSUCCESSFUL_CODE;
    for (int i = 0; i < arr->count; i++)
        free(arr->elems[i]);
    free(arr->elems);
    arr->elems = (void **)malloc(8 * 2);
    arr->capacity = 2;
    arr->count = 0;
    return SUCCESSFUL_CODE;
}

CodeStatus ArrayFree(Array *arr)
{
    if (arr == NULL)
        return UNSUCCESSFUL_CODE;
    for (int i = 0; i < arr->count; i++)
        free(arr->elems[i]);
    free(arr->elems);
    free(arr);
    return SUCCESSFUL_CODE;
}