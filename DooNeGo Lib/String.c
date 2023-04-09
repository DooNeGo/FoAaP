#include <stdlib.h>
#include <string.h>
#include "String.h"

typedef struct String
{
    char *elems;
    int count;
    int capacity;
} String;

String *ConstructString(unsigned int initialSize)
{
    if (initialSize == 0)
        initialSize = 2;
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

CodeStatus SetCharArrToString(String *str, const char *string)
{
    if (GetStringCount(str) > 0)
        ClearString(str, 2);
    int size = strlen(string);
    for (int i = 0; i < size; i++)
    {
        InsertElemToString(str, string[i]);
    }
    return SUCCESSFUL_CODE;
}

char GetStringElem(const String *str, unsigned int index)
{
    if (index >= str->count)
        return NULL;
    return str->elems[index];
}

CodeStatus SetPtrString(String *dest, const String *source)
{
    if (dest->count > 0)
        ClearString(dest, 2);
    for (int i = 0; i < GetStringCount(source); i++)
        InsertElemToString(dest, GetStringElem(source, i));
    return SUCCESSFUL_CODE;
}

CodeStatus SetString(String *dest, const String source)
{
    if (dest->count > 0)
        ClearString(dest, 2);
    for (int i = 0; i < GetStringCount(&source); i++)
        InsertElemToString(dest, GetStringElem(&source, i));
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

CodeStatus ClearString(String *str, int initialSize)
{
    free(str->elems);
    str->elems = (char *)malloc(sizeof(char) * initialSize);
    str->capacity = initialSize;
    str->count = 0;
    return SUCCESSFUL_CODE;
}

char *ConvertStringToCharArray(const String *arr)
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

int GetStringCount(const String *str)
{
    return str->count;
}

Bool IsEqualStrings(const String *str, const String *str1)
{
    if (str == NULL || str1 == NULL || str->count != str1->count)
        return False;
    if (memcmp(str->elems, str1->elems, str->count) == 0)
        return True;
    return False;
}

CodeStatus FreeString(String *str)
{
    if (str == NULL)
        return SUCCESSFUL_CODE;
    free(str->elems);
    free(str);
    return SUCCESSFUL_CODE;
}