#include "Array.h"
#include <stdio.h>
#include <math.h>

void ShowArray(Array *arr)
{
    for (int i = 0; i < arr->count; i++)
    {
        int outEl;
        ArrayGet(arr, i, &outEl);
        printf("%d\n", outEl);
    }
}

int main(int argc, char **argv)
{
    Array *arr = ArrayConstructor(1, sizeof(int));

    // status = ArrayAdd(arr, "hello");
    // ArrayAdd(arr, "stas");
    // ArrayAdd(arr, "matvey");
    // ArrayAdd(arr, "undefined");
    // ArrayAdd(arr, "tutbilay");
    int elem = 1;
    ArrayAdd(arr, &elem);
    ArrayAdd(arr, &elem);
    ArrayAdd(arr, &elem);
    ArrayAdd(arr, &elem);
    ArrayAdd(arr, &elem);

    ShowArray(arr);

    printf("\nSize: %d\n", arr->capacity);
    printf("Count: %d\n", arr->count);

    for (int i = 0; i < arr->count; i++)
        free(arr->elems[i]);
    system("pause");
    return 0;
}