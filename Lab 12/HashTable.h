#include "Node.h"

#ifndef HASH_TABLE
#define HASH_TABLE

typedef struct HashTable HashTable;
HashTable *ConstructHashTable(int initialSize);
Node *GetHashTableNode(HashTable *hashTable, unsigned int index);
Bool FindHashTableNodeValue(const HashTable *hashTable, String *value);
CodeStatus DeleteHashTableNode(HashTable *hashTable, String *value);
CodeStatus InsertValueToHashTableNode(HashTable *hashTable, String *value);

#endif