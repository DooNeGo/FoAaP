#include <stdlib.h>
#include <string.h>
#include "String.h"

typedef struct String
{
    char *elems;
    int length;
    int capacity;
} String;

String *StringConstructor(unsigned int initialSize)
{
    if (initialSize == 0)
        initialSize = 2;
    String *str = (String *)malloc(sizeof(String));
    str->length = 0;
    str->capacity = initialSize;
    str->elems = (char *)malloc(initialSize);
    str->elems[0] = '\0';
    return str;
}

void Resize(String *str)
{
    int newSize = str->capacity * 2;
    char *newArr = (char *)malloc(newSize);
    memcpy(newArr, str->elems, str->length);
    free(str->elems);
    str->capacity = newSize;
    str->elems = newArr;
}

CodeStatus StringAddCharElem(String *str, const char elem)
{
    char newArrElem = elem;
    if (str->length + 1 == str->capacity)
        Resize(str);
    str->elems[str->length] = newArrElem;
    str->elems[str->length + 1] = '\0';
    str->length++;
    return SUCCESSFUL_CODE;
}

CodeStatus StringSetValue(String *str, const char *string)
{
    if (string == NULL || str == NULL)
        return UNSUCCESSFUL_CODE;
    int length = strlen(string);
    if (StringLength(str) > 0)
        StringClear(str, length);
    for (int i = 0; i < length; i++)
        StringAddCharElem(str, string[i]);
    return SUCCESSFUL_CODE;
}

char StringElem(const String *str, unsigned int index)
{
    if (index >= str->length || str == NULL)
        return NULL;
    return str->elems[index];
}

CodeStatus StringAdd(String *str, const char *string)
{
    int length = strlen(string);
    if (length == 0)
        return UNSUCCESSFUL_CODE;
    for (int i = 0; i < length; i++)
        StringAddCharElem(str, string[i]);
    return SUCCESSFUL_CODE;
}

CodeStatus StringClear(String *str, int initialSize)
{
    free(str->elems);
    str->elems = (char *)malloc(sizeof(char) * initialSize);
    str->capacity = initialSize;
    str->length = 0;
    return SUCCESSFUL_CODE;
}

char *StringGetValue(const String *str)
{
    if (str->length < 1)
        return NULL;
    char *arrChar = (char *)malloc(str->length + 1);
    memcpy(arrChar, str->elems, str->length + 1);
    return arrChar;
}

int StringSize()
{
    return sizeof(String);
}

int StringLength(const String *str)
{
    return str->length;
}

int StringCapacity(const String *str)
{
    return str->capacity;
}

Bool IsStringsEqual(const String *str, const String *str1)
{
    if (str == NULL || str1 == NULL || str->length != str1->length)
        return False;
    if (memcmp(StringGetValue(str), StringGetValue(str1), StringLength(str)) == 0)
        return True;
    return False;
}

Bool StringEquals(const String *str, const void *elem)
{
    if (str == NULL || elem == NULL)
        return False;
    if (memcmp(StringGetValue(str), elem, StringLength(str)) == 0)
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