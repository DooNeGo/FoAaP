#include <stdio.h>
#include <stdlib.h>
#include "DooNeGo.h"

int main(int argc, char **argv)
{
    printf("Input:\n");
    String *arr = readString();
    String *arr1 = readString();

    Array *arrString = ConstructArray(1, sizeof(String));
    InsertElemToArray(arrString, arr);
    InsertElemToArray(arrString, arr1);

    printf("Output:\n");
    writeString((String *)GetArrayElem(arrString, 0));
    writeString((String *)GetArrayElem(arrString, 1));

    system("pause");
    return SUCCESSFUL_CODE;
}