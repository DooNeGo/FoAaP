#include "DooNeGo.h"
#include <stdio.h>

int writeString(String *arr)
{
    for (int i = 0; i < arr->count; i++)
    {
        printf("%c", arr->elems[i]);
    }
    printf("\n");
    return SUCCESSFUL_CODE;
}