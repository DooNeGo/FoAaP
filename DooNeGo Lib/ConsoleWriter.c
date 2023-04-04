#include "DooNeGo.h"
#include <stdio.h>

enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
};

int writeString(String *arr)
{
    for (int i = 0; i < arr->count; i++)
    {
        printf("%c", arr->elems[i]);
    }
    return SUCCESSFUL_CODE;
}