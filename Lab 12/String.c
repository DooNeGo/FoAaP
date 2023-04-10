#include <stdlib.h>
#include <string.h>
#include "String.h"

typedef struct String
{
    char *elems;
    int count;
    int capacity;
} String;

String *StringConstructor(unsigned int initialSize)
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

CodeStatus StringAddCharElem(String *arr, const char elem)
{
    char newArrElem = elem;
    if (arr->count == arr->capacity)
        ResizeString(arr);
    arr->elems[arr->count] = newArrElem;
    arr->count++;
    return SUCCESSFUL_CODE;
}

CodeStatus StringSetValue(String *str, const char *string)
{
    if (StringCount(str) > 0)
        StringClear(str, 2);
    int size = strlen(string);
    for (int i = 0; i < size; i++)
    {
        StringAddCharElem(str, string[i]);
    }
    return SUCCESSFUL_CODE;
}

char StringElem(const String *str, unsigned int index)
{
    if (index >= str->count)
        return NULL;
    return str->elems[index];
}

CodeStatus StringAdd(String *arr, const char *string)
{
    int size = strlen(string);
    for (int i = 0; i < size; i++)
    {
        StringAddCharElem(arr, string[i]);
    }
    return SUCCESSFUL_CODE;
}

CodeStatus StringClear(String *str, int initialSize)
{
    free(str->elems);
    str->elems = (char *)malloc(sizeof(char) * initialSize);
    str->capacity = initialSize;
    str->count = 0;
    return SUCCESSFUL_CODE;
}

char *StringGetValue(const String *arr)
{
    if (arr->count < 1)
        return NULL;
    char *arrChar = (char *)malloc(arr->count);
    memcpy(arrChar, arr->elems, arr->count);
    return arrChar;
}

int StringSize()
{
    return sizeof(String);
}

int StringCount(const String *str)
{
    return str->count;
}

Bool IsEqualStrings(const String *str, const String *str1)
{
    if (str == NULL || str1 == NULL || str->count != str1->count)
        return False;
    if (memcmp(StringGetValue(str), StringGetValue(str1), StringCount(str)) == 0)
        return True;
    return False;
}

Bool StringEqual(const String *str, const void *elem)
{
    if (str == NULL || elem == NULL)
        return False;
    if (memcmp(StringGetValue(str), elem, StringCount(str)) == 0)
        return True;
    return False;
}

CodeStatus StringFree(String *str)
{
    if (str == NULL)
        return UNSUCCESSFUL_CODE;
    free(str->elems);
    free(str);
    return SUCCESSFUL_CODE;
}