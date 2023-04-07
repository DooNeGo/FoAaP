#include <stdio.h>
#include "ConsoleWriter.h"

CodeStatus WriteString(String *str)
{
    if (str == NULL)
        return UNSUCCESSFUL_CODE;
    for (int i = 0; i < GetCountString(str); i++)
    {
        printf("%c", GetElemString(str, i));
    }
    if (GetCountString(str) > 0)
        printf("\n");
    return SUCCESSFUL_CODE;
}