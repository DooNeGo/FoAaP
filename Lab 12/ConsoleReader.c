#include <stdio.h>
#include "ConsoleReader.h"

String *ReadString()
{
    fflush(stdin);
    String *str = StringConstructor(2);
    while (1)
    {
        char temp = 0;
        scanf("%c", &temp);
        if (temp == '\n' || temp == '\t')
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