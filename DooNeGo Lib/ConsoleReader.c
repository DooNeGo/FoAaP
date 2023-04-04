#include <stdio.h>
#include "DooNeGo.h"

String *readString()
{
    String *arr = ConstructString(2);
    while (1)
    {
        char temp;
        scanf("%c", &temp);
        if (temp == '\n')
            break;
        AddStringElem(arr, temp);
    }
    return arr;
}