#include <stdio.h>
#include <stdlib.h>
#include "DooNeGo.h"
#include "Node.h"

int main(int argc, char **argv)
{
    Array *arr = ConstructArray(1, GetSizeOfString());

    InsertElemToArray(arr, ReadStringPtr());
    InsertElemToArray(arr, ReadStringPtr());
    InsertElemToArray(arr, ReadStringPtr());

    for (int i = 0; i < GetArrCount(arr); i++)
        WriteString((String *)GetArrElem(arr, i));

    printf("\nCount: %d\n", GetArrCount(arr));
    printf("Capacity: %d\n", GetArrCapacity(arr));

    system("pause");
    return SUCCESSFUL_CODE;
}