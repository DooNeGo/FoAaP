#include <stdio.h>
#include "ConsoleReader.h"

typedef struct String
{
    char *elems;
    int length;
    int capacity;
} String;

String *ReadString()
{
    fflush(stdin);
    String *str = StringConstructor(2);
    while (1)
    {
        char temp = 0;
        scanf("%c", &temp);
        if (temp == '\n' || temp == ' ' || temp == '\t')
            break;
        StringAddCharElem(str, temp);
    }
    if (StringEquals(str, "0"))
    {
        StringFree(str);
        return NULL;
    }
    return str;
}