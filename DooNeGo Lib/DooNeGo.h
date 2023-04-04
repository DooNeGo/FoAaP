typedef struct String
{
    char *elems;
    int count;
    int capacity;
} String;

String *ConstructString(int);
int AddStringElem(String *, const char elem);
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
int InsertArrayElem(Array *, const void *);
void* GetArrayElem(Array *, int);