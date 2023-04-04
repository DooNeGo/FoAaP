#include <stdlib.h>
typedef struct String
{
    char *elems;
    int count;
    int capacity;
} String;

String *ConstructString(int);
int AddElemToString(String *, const char elem);
int AddString(String *, const char *);
int ClearString(String *);
char *ConvertStringToCharArray(String *);
int writeString(String *arr);
String *readString();

typedef struct Array
{
    void **elems;
    int count;
    int capacity;
    int elemSize;
} Array;

Array *ConstructArray(int, int);
int InsertElemToArray(Array *, const void *);
void* GetArrayElem(Array *, int);


void swap(void *elemi, void *elemj, size_t size);
void *concatenation(const void *Source, const void *Source1, const int SourceCount, const int Source1Count, const size_t singleElementSize, int *outNewCount);


enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
};