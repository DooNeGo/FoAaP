#include "Node.h"

#ifndef HASH_TABLE
#define HASH_TABLE

typedef struct HashTable HashTable;
HashTable *HashTableConstructor(unsigned int initialSize);
int HashTableCount(const HashTable *hashTable);
Node *HashTableNode(const HashTable *hashTable, unsigned int index);
Bool HashTableFindValue(const HashTable *hashTable, const String *value);
CodeStatus HashTableDeleteValue(HashTable *hashTable, const String *value);
CodeStatus HashTableAdd(HashTable *hashTable, String *value);
CodeStatus HashTableFree(HashTable *hashTable);

int GetMaxCountCollisions(const HashTable *hashTable);
int GetTableFilledCount(HashTable *hashTable);

#endif