#include <stdlib.h>

typedef enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
    ArgumentOutOfRangeException = 2,
} CodeStatus;

typedef enum Bool
{
    False = 0,
    True = 1,
} Bool;

typedef struct String String;
String *ConstructString(int initialSize);
CodeStatus InsertCharArrToString(String *arr, const char *string);
CodeStatus InsertElemToString(String *arr, const char elem);
CodeStatus ClearString(String *arr);
char *ConvertStringToCharArray(String *arr);
CodeStatus SetCharArrToString(String *arr, const char *string);
int GetSizeOfString();
char GetElemString(String *str, int index);
int GetCountString(String *str);
CodeStatus SetStringWithFree(String *dest, String *source);
Bool IsEqualStrings(const String *str, const String *str1);

typedef struct Array Array;
Array *ConstructArray(int initialSize, int elemSize);
CodeStatus InsertElemToArray(Array *arr, const void *elem);
void *GetElemArr(Array *arr, int index);
int GetCountArr(Array *arr);
int GetCapacityArr(Array *arr);
CodeStatus SetElemArr(Array *arr, const void *newElem, int index);
CodeStatus RemoveArrayElemAt(Array *arr, int index);
CodeStatus RemoveArrayElem(Array *arr, const void *elem);
CodeStatus ClearArray(Array *arr);

CodeStatus WriteString(String *arr);
String *ReadString();

void swap(void *elemi, void *elemj, size_t size);
void *concatenation(const void *Source, const void *Source1, const int SourceCount, const int Source1Count, const size_t singleElementSize, int *outNewCount);
