#include "Node.h"

#ifndef HASH_TABLE
#define HASH_TABLE

typedef struct HashTable HashTable;
HashTable *ConstructHashTable(unsigned int initialSize);
int GetHashTableCount(const HashTable *hashTable);
const Node *GetHashTableNode(const HashTable *hashTable, unsigned int index);
Bool FindHashTableNodeValue(const HashTable *hashTable, const String *value);
CodeStatus DeleteHashTableNode(HashTable *hashTable, const String *value);
CodeStatus InsertValueToHashTable(HashTable *hashTable, const String *value);
int GetMaxCountCollisions(const HashTable *hashTable);
CodeStatus FreeHashTable(HashTable *hashTable);

#endif