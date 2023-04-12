#include "String.h"
#include "HashTable.h"

#ifndef COLOR
#define COLOR

typedef enum Color
{
    Red,
    Green,
} Color;

#endif

#ifndef WRITE_STRING
#define WRITE_STRING

CodeStatus WriteString(const String *str);
CodeStatus WriteLineString(const String *str);
CodeStatus WriteMessage(const char *message, Color color);
CodeStatus WriteHashTableNode(Node *node, int counter);
CodeStatus WriteHashTable(const HashTable *hashTable);
CodeStatus WriteEachNodeCollisionWithStats(HashTable *hashTable);

#endif