#include "Array.c"

typedef struct Array Array;
Array *ArrayConstructor(int initialSize, int elemSize);
int ArrayAdd(Array *arr, const void *elem);
int ArrayGet(Array *arr, int index, void *outputElem);