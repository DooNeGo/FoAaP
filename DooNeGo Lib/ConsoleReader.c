#include <stdio.h>
#include "ConsoleReader.h"

typedef struct String
{
    char *elems;
    int count;
    int capacity;
} String;

String ReadString()
{
    fflush(stdin);
    String arr = *ConstructString(2);
    while (1)
    {
        char temp;
        scanf("%c", &temp);
        if (temp == '\n')
            break;
        InsertElemToString(&arr, temp);
    }
    return arr;
}

String *ReadStringPtr()
{
    fflush(stdin);
    String *arr = ConstructString(2);
    while (1)
    {
        char temp;
        scanf("%c", &temp);
        if (temp == '\n')
            break;
        InsertElemToString(arr, temp);
    }
    return arr;
}