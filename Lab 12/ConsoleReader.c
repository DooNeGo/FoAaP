#include <stdio.h>
#include "ConsoleReader.h"

typedef struct String
{
    char *elems;
    int count;
    int capacity;
} String;

String *ReadString()
{
    fflush(stdin);
    String *str = StringConstructor(2);
    while (1)
    {
        char temp;
        scanf("%c", &temp);
        if (temp == '\n' || temp == ' ' || temp == '\t')
            break;
        StringAddCharElem(str, temp);
    }
    if (StringEqual(str, "0"))
    {
        StringFree(str);
        return NULL;
    }
    return str;
}