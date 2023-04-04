#include <stdlib.h>
typedef struct String
{
    char *elems;
    int count;
    int capacity;
} String;

String *ConstructString(int initialSize);
int InsertElemToString(String *arr, const char elem);
int AddString(String *arr, const char *string);
int ClearString(String *arr);
char *ConvertStringToCharArray(String *arr);
int writeString(String *arr);
String *readString();

typedef struct Array
{
    void **elems;
    int count;
    int capacity;
    int elemSize;
} Array;

Array *ConstructArray(int initialSize, int elemSize);
int InsertElemToArray(Array *arr, const void *elem);
void* GetArrayElem(Array *arr, int index);


void swap(void *elemi, void *elemj, size_t size);
void *concatenation(const void *Source, const void *Source1, const int SourceCount, const int Source1Count, const size_t singleElementSize, int *outNewCount);


enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
};