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
    char newArrElem = elem;
    if (arr->count == arr->capacity)
    {
        int newSize = arr->capacity * 2;
        char *newArr = (char *)malloc(newSize);
        for (int i = 0; i < arr->count; i++)
        {
            newArr[i] = arr->elems[i];
        }
        free(arr->elems);
        newArr[arr->count] = newArrElem;
        arr->capacity = newSize;
        arr->elems = newArr;
    }
    else
    {
        arr->elems[arr->count] = newArrElem;
    }
    arr->count++;
    return SUCCESSFUL_CODE;
}

int AddString(String *arr, const char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        InsertElemToString(arr, string[i]);
    }
    return SUCCESSFUL_CODE;
}

int ClearString(String *arr)
{
    free(arr->elems);
    arr->elems = (char *)malloc(sizeof(char) * 2);
    arr->capacity = 2;
    arr->count = 0;
    return SUCCESSFUL_CODE;
}

char *ConvertStringToCharArray(String *arr)
{
    if (arr->count < 1)
        return NULL;
    char *arrChar = (char *)malloc(arr->count);
    memcpy(arrChar, arr->elems, arr->count);
    return arrChar;
}