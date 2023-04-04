#include <stdio.h>
#include "DooNeGo.h"

String *readString()
{
    fflush(stdin);
    String *arr = ConstructString(2);
    while (1)
    {
        char temp;
        scanf("%c", &temp);
        if (temp == '\n')
            break;
        AddElemToString(arr, temp);
    }
    return arr;
}