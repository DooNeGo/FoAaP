#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "DooNeGo.h"

String *ConstructString(int initialSize)
{
    String *arr = (String *)malloc(sizeof(String));
    arr->count = 0;
    arr->capacity = initialSize;
    arr->elems = (char *)malloc(initialSize);
    return arr;
}

int InsertElemToString(String *arr, const char elem)
{
    char *newArrElem = (char *)malloc(sizeof(char));
    memcpy(newArrElem, &elem, sizeof(char));
    if (arr->count == arr->capacity)
    {
        int newSize = arr->capacity * 2;
        char *newArr = (char *)malloc(newSize);
        for (int i = 0; i < arr->count; i++)
        {
            newArr[i] = arr->elems[i];
        }
        free(arr->elems);
        newArr[arr->count] = *newArrElem;
        arr->capacity = newSize;
        arr->elems = newArr;
    }
    else
    {
        arr->elems[arr->count] = *newArrElem;
    }
    (arr->count)++;
    free(newArrElem);
    return SUCCESSFUL_CODE;
}

int AddString(String *arr, const char *string)
{
    int size = strlen(string);
    for (int i = 0; i < size; i++)
    {
        InsertElemToString(arr, string[i]);
    }
    return SUCCESSFUL_CODE;
}

int ClearString(String *arr)
{
    free(arr->elems);
    arr->capacity = 1;
    arr->count = 0;
    return SUCCESSFUL_CODE;
}

char *ConvertStringToCharArray(String *arr)
{
    if (arr->count < 1)
        return NULL;
    char *newArr = (char *)malloc(arr->count);
    memcpy(newArr, arr->elems, arr->count);
    return newArr;
}