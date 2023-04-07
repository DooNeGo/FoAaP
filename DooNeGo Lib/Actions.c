#include <string.h>
#include <stdlib.h>
#include "Actions.h"

void swap(void *elemi, void *elemj, unsigned int size)
{
    void *temp = malloc(size);
    memcpy(temp, elemi, size);
    memcpy(elemi, elemj, size);
    memcpy(elemj, temp, size);
    free(temp);
}

void *concatenation(const void *Source, const void *Source1, const int SourceCount, const int Source1Count, const unsigned int singleElementSize, int *outNewCount)
{
    int newArrayCount = SourceCount + Source1Count;
    void *newArray = malloc(newArrayCount * singleElementSize);
    memcpy(newArray, Source, singleElementSize * SourceCount);
    memcpy(newArray + singleElementSize * SourceCount, Source1, singleElementSize * Source1Count);
    *outNewCount = newArrayCount;
    return newArray;
}