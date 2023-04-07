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
Array *ConstructArray(int initialSize, int elemSize);
CodeStatus InsertElemToArray(Array *arr, const void *elem);
void *GetArrElem(Array *arr, int index);
int GetArrCount(Array *arr);
int GetArrCapacity(Array *arr);
CodeStatus SetArrElem(Array *arr, const void *newElem, int index);
CodeStatus RemoveArrayElemAt(Array *arr, int index);
CodeStatus RemoveArrayElem(Array *arr, const void *elem);
CodeStatus ClearArray(Array *arr);

#endif