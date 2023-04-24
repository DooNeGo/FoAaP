#ifndef CODE_STATUS
#define CODE_STATUS

typedef enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
} CodeStatus;

#endif

#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

typedef struct Array Array;
Array *ArrayConstructor(unsigned int initialSize, unsigned int elemSize);
CodeStatus ArrayAdd(Array *arr, const void *elem);
CodeStatus ArrayAddPtr(Array *arr, void *newElem);
void *ArrayGetElem(Array *arr, unsigned int index);
int ArrayCount(const Array *arr);
int ArrayCapacity(const Array *arr);
CodeStatus ArraySetPtrElem(Array *arr, void *newElem, unsigned int index);
CodeStatus ArrayRemoveElemAt(Array *arr, unsigned int index);
CodeStatus ArrayRemoveElem(Array *arr, const void *elem);
CodeStatus ArrayClear(Array *arr);
CodeStatus ArrayFree(Array *arr);

#endif