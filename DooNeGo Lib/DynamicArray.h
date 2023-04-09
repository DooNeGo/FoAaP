#ifndef CODE_STATUS
#define CODE_STATUS

typedef enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
    ArgumentOutOfRangeException = 2,
} CodeStatus;

#endif

#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

typedef struct Array Array;
Array *ConstructArray(unsigned int initialSize, int elemSize);
CodeStatus InsertElemToArray(Array *arr, void *elem);
void *GetArrElem(Array *arr, unsigned int index);
int GetArrCount(const Array *arr);
int GetArrCapacity(const Array *arr);
CodeStatus SetArrElem(Array *arr, const void *newElem, unsigned int index);
CodeStatus RemoveArrayElemAt(Array *arr, unsigned int index);
CodeStatus RemoveArrayElem(Array *arr, const void *elem);
CodeStatus ClearArray(Array *arr);
CodeStatus FreeArray(Array *arr);

#endif