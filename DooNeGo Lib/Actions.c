#include "DooNeGo.h"
#include <string.h>
#include <stdlib.h>

void swap(void *elemi, void *elemj, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, elemi, size);
    memcpy(elemi, elemj, size);
    memcpy(elemj, temp, size);
    free(temp);
}

void *concatenation(const void *Source, const void *Source1, const int SourceCount, const int Source1Count, const size_t singleElementSize, int *outNewCount)
{
    int newArrayCount = SourceCount + Source1Count;
    void *newArray = malloc(newArrayCount * singleElementSize);
    memcpy(newArray, Source, singleElementSize * SourceCount);
    memcpy(newArray + singleElementSize * SourceCount, Source1, singleElementSize * Source1Count);
    *outNewCount = newArrayCount;
    return newArray;
}