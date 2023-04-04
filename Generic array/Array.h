#include "Array.c"

typedef struct Array Array;
Array *ArrayConstructor(int, int);
int ArrayAdd(Array *, const void*);
void* ArrayGet(Array *, int);