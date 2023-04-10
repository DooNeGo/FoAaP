#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "DynamicArray.h"

typedef struct Array
{
    void **elems;
    int count;
    int capacity;
    int elemSize;
} Array;

Array *ConstructArray(unsigned int initialSize, int elemSize)
{
    if (initialSize == 0)
        initialSize = 1;
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

CodeStatus InsertElemToArray(Array *arr, const void *elem)
{
    void *newArrElem = malloc(arr->elemSize);
    memcpy(newArrElem, elem, arr->elemSize);
    if (arr->count == arr->capacity)
        ResizeArr(arr);
    arr->elems[arr->count] = newArrElem;
    arr->count++;
    return SUCCESSFUL_CODE;
}

CodeStatus InsertPtrElemToArray(Array *arr, void *newElem)
{
    if (arr->count == arr->capacity)
        ResizeArr(arr);
    arr->elems[arr->count] = newElem;
    arr->count++;
    return SUCCESSFUL_CODE;
}

const void *GetArrElem(Array *arr, unsigned int index)
{
    if (index >= arr->count)
        return NULL;
    return arr->elems[index];
}

CodeStatus SetArrElem(Array *arr, const void *newElem, unsigned int index)
{
    if (index >= arr->count)
        return UNSUCCESSFUL_CODE;
    memcpy(arr->elems[index], newElem, arr->elemSize);
    return SUCCESSFUL_CODE;
}

int GetArrCount(const Array *arr)
{
    return arr->count;
}

int GetArrCapacity(const Array *arr)
{
    return arr->capacity;
}

CodeStatus RemoveArrayElemAt(Array *arr, unsigned int index)
{
    if (index >= arr->count)
        return ArgumentOutOfRangeException;
    for (int i = index; i < arr->count - 1; i++)
    {
        arr->elems[i] = arr->elems[i + 1];
    }
    arr->count--;
    return SUCCESSFUL_CODE;
}

CodeStatus RemoveArrayElem(Array *arr, const void *elem)
{
    for (int index = 0; index < arr->count; index++)
    {
        if (memcmp(arr->elems[index], elem, arr->elemSize) == 0)
        {
            return RemoveArrayElemAt(arr, index);
        }
    }
    return UNSUCCESSFUL_CODE;
}

CodeStatus ClearArray(Array *arr)
{
    for (int i = 0; i < arr->count; i++)
        free(arr->elems[i]);
    free(arr->elems);
    arr->elems = (void **)malloc(arr->elemSize * 2);
    arr->capacity = 2;
    arr->count = 0;
    return SUCCESSFUL_CODE;
}

CodeStatus FreeArray(Array *arr)
{
    for (int i = 0; i < arr->count; i++)
        free(arr->elems[i]);
    free(arr->elems);
    free(arr);
    return SUCCESSFUL_CODE;
}