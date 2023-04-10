#include "String.h"
#include "HashTable.h"

#ifndef WRITE_STRING
#define WRITE_STRING

CodeStatus WriteString(const String *str);
CodeStatus WriteLineString(const String *str);
CodeStatus WriteMessage(const char *message, const char *color);
CodeStatus WriteHashTableNode(Node *node);
CodeStatus WriteEachNodeCollision(HashTable *hashTable);

#endif