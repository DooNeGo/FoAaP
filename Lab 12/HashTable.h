#include "Node.h"

#ifndef CODE_STATUS
#define CODE_STATUS

typedef enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
} CodeStatus;

#endif

#ifndef BOOL
#define BOOL

typedef enum Bool
{
    FALSE = 0,
    TRUE = 1,
} Bool;

#endif

#ifndef HASH_TABLE
#define HASH_TABLE

typedef struct HashTable HashTable;
HashTable *HashTableConstructor(unsigned int initialSize);
int HashTableCapacity(const HashTable *hashTable);
int HashTableCount(const HashTable *hashTable);
int HashTableCountDeletedNodes(const HashTable *hashTable);
Node *HashTableNode(const HashTable *hashTable, unsigned int index);
Bool HashTableFindValue(const HashTable *hashTable, const String *value);
CodeStatus HashTableDeleteValue(HashTable *hashTable, const String *value);
CodeStatus HashTableAdd(HashTable *hashTable, String *value);
CodeStatus HashTableAddCopy(HashTable *hashTable, const String *value);
CodeStatus HashTableFree(HashTable *hashTable);

int GetMaxCountCollisions(const HashTable *hashTable);
int GetTableFilledCount(HashTable *hashTable);

#endif