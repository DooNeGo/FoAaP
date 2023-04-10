#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "HashFunction.h"

typedef struct HashTable
{
    Node **nodes;
    unsigned int capacity;
    unsigned int countDeletedNodes;
} HashTable;

CodeStatus InitializeHashTableNodes(HashTable *hashTable)
{
    for (int i = 0; i < hashTable->capacity; i++)
        hashTable->nodes[i] = NULL;
    return SUCCESSFUL_CODE;
}

HashTable *HashTableConstructor(unsigned int initialSize)
{
    if (initialSize == 0)
        initialSize = 1;
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->nodes = (Node **)malloc(initialSize * 8);
    hashTable->capacity = initialSize;
    InitializeHashTableNodes(hashTable);
    hashTable->countDeletedNodes = 0;
    return hashTable;
}

int HashTableCount(const HashTable *hashTable)
{
    return hashTable->capacity;
}

Node *HashTableNode(const HashTable *hashTable, unsigned int index)
{
    if (hashTable == NULL || index >= HashTableCount(hashTable))
        return NULL;
    return hashTable->nodes[index];
}

Bool HashTableFindValue(const HashTable *hashTable, const String *value)
{
    int hash = GetHashCode(value) % HashTableCount(hashTable);
    return NodeCheckValue(HashTableNode(hashTable, hash), value);
}

CodeStatus HashTableDeleteValue(HashTable *hashTable, const String *value)
{
    int hash = GetHashCode(value) % HashTableCount(hashTable);
    if (NodeDelete(hashTable->nodes[hash], value) == SUCCESSFUL_CODE)
    {
        hashTable->countDeletedNodes++;
        return SUCCESSFUL_CODE;
    }
    return UNSUCCESSFUL_CODE;
}

CodeStatus InsertOldNodesToHashTable(HashTable *hashTable, Node *node)
{
    if (node == NULL)
        return UNSUCCESSFUL_CODE;
    int childrenCount = NodeChildrenCount(node);
    for (int j = 0; j <= childrenCount; j++)
    {
        if (NodeStatus(node) == Exist)
            HashTableAdd(hashTable, NodeGetValue(node));
        node = NodeChildren(node);
    }
    return SUCCESSFUL_CODE;
}

CodeStatus ResizeHashTable(HashTable *hashTable)
{
    if (hashTable == NULL)
        return UNSUCCESSFUL_CODE;
    int newHashTableSize = hashTable->capacity * 2;
    HashTable *newHashTable = HashTableConstructor(newHashTableSize);
    for (int i = 0; i < HashTableCount(hashTable); i++)
    {
        InsertOldNodesToHashTable(newHashTable, HashTableNode(hashTable, i));
        NodeFree(hashTable->nodes[i]);
    }
    free(hashTable->nodes);
    hashTable->nodes = newHashTable->nodes;
    hashTable->capacity = newHashTable->capacity;
    hashTable->countDeletedNodes = 0;
    free(newHashTable);
    return SUCCESSFUL_CODE;
}

CodeStatus HashTableAdd(HashTable *hashTable, String *value)
{
    if (hashTable == NULL || value == NULL)
        return UNSUCCESSFUL_CODE;
    int hash = GetHashCode(value) % HashTableCount(hashTable);
    if (HashTableNode(hashTable, hash) == NULL)
        hashTable->nodes[hash] = NodeConstructor();
    if (NodeChildrenCount(HashTableNode(hashTable, hash)) > 3)
    {
        ResizeHashTable(hashTable);
        hash = GetHashCode(value) % HashTableCount(hashTable);
    }
    return NodeSetValue(hashTable->nodes[hash], value);
}

int GetMaxCountCollisions(const HashTable *hashTable)
{
    int maxCountCollisions = 0;
    for (int i = 0; i < HashTableCount(hashTable); i++)
    {
        const Node *node = HashTableNode(hashTable, i);
        if (maxCountCollisions < NodeChildrenCount(node))
            maxCountCollisions = NodeChildrenCount(node);
    }
    return maxCountCollisions;
}

CodeStatus HashTableFree(HashTable *hashTable)
{
    for (int i = 0; i < HashTableCount(hashTable); i++)
        NodeFree(hashTable->nodes[i]);
    free(hashTable);
    return SUCCESSFUL_CODE;
}

int GetTableFilledCount(HashTable *hashTable)
{
    int counter = 0;
    for (int i = 0; i < HashTableCount(hashTable); i++)
    {
        const Node *node = HashTableNode(hashTable, i);
        if (node != NULL)
            counter++;
    }
    return counter;
}