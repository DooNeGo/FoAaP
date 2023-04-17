#include "HashTable.h"
#include "DynamicArray.h"

#ifndef CODE_STATUS
#define CODE_STATUS

typedef enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
    ArgumentOutOfRangeException = 2,
} CodeStatus;

#endif

#ifndef COLOR
#define COLOR

typedef enum Color
{
    RED,
    GREEN,
} Color;

#endif

#ifndef WRITE_STRING
#define WRITE_STRING

CodeStatus WriteString(const String *str);
CodeStatus WriteLineString(const String *str);
CodeStatus WriteMessage(const char *message, Color color);
CodeStatus WriteArray(Array *arr);
CodeStatus WriteHashTable(const HashTable *hashTable);
CodeStatus WriteEachNodeCollisionWithStats(HashTable *hashTable);

#endif