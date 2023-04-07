#include <stdlib.h>
#include <string.h>
#include "String.h"

typedef struct String
{
    char *elems;
    int count;
    int capacity;
} String;

String *ConstructString(int initialSize)
{
    String *arr = (String *)malloc(sizeof(String));
    arr->count = 0;
    arr->capacity = initialSize;
    arr->elems = (char *)malloc(initialSize);
    return arr;
}

void ResizeString(String *arr)
{
    int newSize = arr->capacity * 2;
    char *newArr = (char *)malloc(newSize);
    memcpy(newArr, arr->elems, arr->count);
    free(arr->elems);
    arr->capacity = newSize;
    arr->elems = newArr;
}

CodeStatus InsertElemToString(String *arr, const char elem)
{
    char newArrElem = elem;
    if (arr->count == arr->capacity)
        ResizeString(arr);
    arr->elems[arr->count] = newArrElem;
    arr->count++;
    return SUCCESSFUL_CODE;
}

CodeStatus SetCharArrToString(String *arr, const char *string)
{
    if (arr->count > 0)
        ClearString(arr);
    int size = strlen(string);
    for (int i = 0; i < size; i++)
    {
        InsertElemToString(arr, string[i]);
    }
    return SUCCESSFUL_CODE;
}

CodeStatus SetStringWithFree(String *dest, String *source)
{
    if (dest->count > 0)
        ClearString(dest);
    memcpy(dest, source, sizeof(String));
    free(source);
    return SUCCESSFUL_CODE;
}

CodeStatus InsertCharArrToString(String *arr, const char *string)
{
    int size = strlen(string);
    for (int i = 0; i < size; i++)
    {
        InsertElemToString(arr, string[i]);
    }
    return SUCCESSFUL_CODE;
}

CodeStatus ClearString(String *arr)
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

int GetSizeOfString()
{
    return sizeof(String);
}

int GetCountString(String *str)
{
    return str->count;
}

char GetElemString(String *str, int index)
{
    if (index >= str->count || index < 0)
        return NULL;
    return str->elems[index];
}

Bool IsEqualStrings(const String *str, const String *str1)
{
    if (str->count != str1->count)
        return False;
    if (memcmp(str->elems, str1->elems, str->count) == 0)
        return True;
    return False;
}