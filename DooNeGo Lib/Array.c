#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "DooNeGo.h"

Array *ConstructArray(int initialSize, int elemSize)
{
    Array *arr = (Array *)malloc(sizeof(Array));
    arr->count = 0;
    arr->capacity = initialSize;
    arr->elems = (void **)malloc(initialSize * 8);
    arr->elemSize = elemSize;
    return arr;
}

int InsertElemToArray(Array *arr, const void *elem)
{
    void *newArrElem = malloc(arr->elemSize);
    memcpy(newArrElem, elem, arr->elemSize);
    if (arr->count == arr->capacity)
    {
        int newSize = arr->capacity * 2;
        void **newArr = (void **)malloc(newSize * 8);
        for (int i = 0; i < arr->count; i++)
        {
            newArr[i] = arr->elems[i];
        }
        newArr[arr->count] = newArrElem;
        arr->capacity = newSize;
        arr->elems = newArr;
    }
    else
    {
        arr->elems[arr->count] = newArrElem;
    }
    (arr->count)++;
    return SUCCESSFUL_CODE;
}

void* GetArrayElem(Array *arr, int index)
{
    if (index >= arr->count || index < 0)
        return NULL;
    return arr->elems[index];
}