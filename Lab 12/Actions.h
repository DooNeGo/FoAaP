#ifndef ACTIONS
#define ACTIONS

void swap(void *elemi, void *elemj, unsigned int size);
void *concatenation(const void *Source, const void *Source1, const int SourceCount, const int Source1Count, const unsigned int singleElementSize, int *outNewCount);

#endif