#include "DooNeGo.h"
#include <stdio.h>

CodeStatus WriteString(String *arr)
{
    if (arr == NULL)
        return UNSUCCESSFUL_CODE;
    for (int i = 0; i < GetCountString(arr); i++)
    {
        printf("%c", GetElemString(arr, i));
    }
    if (GetCountString(arr) > 0)
        printf("\n");
    return SUCCESSFUL_CODE;
}