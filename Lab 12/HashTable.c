#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "HashFunction.h"
#include <stdarg.h>

typedef struct HashTable
{
    Node **nodes;
    unsigned int count;
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
    hashTable->count = 0;
    InitializeHashTableNodes(hashTable);
    hashTable->countDeletedNodes = 0;
    return hashTable;
}

int HashTableCapacity(const HashTable *hashTable)
{
    return hashTable->capacity;
}

int HashTableCount(const HashTable *hashTable)
{
    return hashTable->count;
}

int HashTableCountDeletedNodes(const HashTable *hashTable)
{
    return hashTable->countDeletedNodes;
}

Node *HashTableNode(const HashTable *hashTable, unsigned int index)
{
    if (hashTable == NULL || index >= HashTableCapacity(hashTable))
        return NULL;
    return hashTable->nodes[index];
}

Bool HashTableFindValue(const HashTable *hashTable, const String *value)
{
    int hash = GetHashCode1(value) % HashTableCapacity(hashTable);
    return NodeCheckValue(HashTableNode(hashTable, hash), value);
}

CodeStatus InsertOldNodesToHashTable(HashTable *hashTable, Node *node)
{
    if (node == NULL)
        return UNSUCCESSFUL_CODE;
    int childrenCount = NodeChildrenCount(node);
    for (int j = 0; j <= childrenCount; j++)
    {
        if (NodeStatus(node) == Exist)
            HashTableAddCopy(hashTable, NodeGetValue(node));
        node = NodeChildren(node);
    }
    return SUCCESSFUL_CODE;
}

int UpdateCountDeletedNodes(HashTable *hashTable)
{
    int counter = 0;
    for (int i = 0; i < HashTableCapacity(hashTable); i++)
    {
        Node *node = HashTableNode(hashTable, i);
        if (node == NULL)
            continue;
        int countChildren = NodeChildrenCount(node);
        for (int i = 0; i <= countChildren; i++)
        {
            if (NodeStatus(node) == Deleted)
                counter++;
            node = NodeChildren(node);
        }
    }
    return counter;
}

CodeStatus Rehash(HashTable *hashTable)
{
    if (hashTable == NULL)
        return UNSUCCESSFUL_CODE;
    hashTable->countDeletedNodes = UpdateCountDeletedNodes(hashTable);
    if ((double)HashTableCountDeletedNodes(hashTable) / (double)HashTableCapacity(hashTable) < 0.5)
        return UNSUCCESSFUL_CODE;
    HashTable *newHashTable = HashTableConstructor(HashTableCapacity(hashTable));
    for (int i = 0; i < HashTableCapacity(hashTable); i++)
    {
        InsertOldNodesToHashTable(newHashTable, HashTableNode(hashTable, i));
        NodeFree(hashTable->nodes[i]);
    }
    free(hashTable->nodes);
    hashTable->nodes = newHashTable->nodes;
    hashTable->countDeletedNodes = 0;
    free(newHashTable);
    return SUCCESSFUL_CODE;
}

CodeStatus HashTableDeleteValue(HashTable *hashTable, const String *value)
{
    if (value == NULL || hashTable == NULL)
        return UNSUCCESSFUL_CODE;
    int hash = GetHashCode1(value) % HashTableCapacity(hashTable);
    if (NodeDelete(hashTable->nodes[hash], value) == SUCCESSFUL_CODE)
    {
        hashTable->countDeletedNodes++;
        hashTable->count--;
        if ((double)HashTableCountDeletedNodes(hashTable) / (double)HashTableCapacity(hashTable) >= 0.5)
            Rehash(hashTable);
        return SUCCESSFUL_CODE;
    }
    return UNSUCCESSFUL_CODE;
}

CodeStatus Resize(HashTable *hashTable)
{
    if (hashTable == NULL)
        return UNSUCCESSFUL_CODE;
    int newHashTableSize = hashTable->capacity * 2;
    HashTable *newHashTable = HashTableConstructor(newHashTableSize);
    for (int i = 0; i < HashTableCapacity(hashTable); i++)
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

CodeStatus HashTableAddCopy(HashTable *hashTable, const String *value)
{
    if (hashTable == NULL || value == NULL)
        return UNSUCCESSFUL_CODE;
    int hash = GetHashCode1(value) % HashTableCapacity(hashTable);
    if (HashTableNode(hashTable, hash) == NULL)
        hashTable->nodes[hash] = NodeConstructor();
    if (NodeChildrenCount(HashTableNode(hashTable, hash)) > 3)
    {
        Resize(hashTable);
        hash = GetHashCode1(value) % HashTableCapacity(hashTable);
    }
    hashTable->count++;
    String *copyValue = StringConstructor(2);
    StringSetValue(copyValue, StringGetValue(value));
    return NodeSetValue(hashTable->nodes[hash], copyValue);
}

CodeStatus HashTableAdd(HashTable *hashTable, String *value)
{
    if (hashTable == NULL || value == NULL)
        return UNSUCCESSFUL_CODE;
    int hash = GetHashCode1(value) % HashTableCapacity(hashTable);
    if (HashTableNode(hashTable, hash) == NULL)
        hashTable->nodes[hash] = NodeConstructor();
    if (NodeChildrenCount(HashTableNode(hashTable, hash)) > 2)
    {
        Resize(hashTable);
        hash = GetHashCode1(value) % HashTableCapacity(hashTable);
    }
    if (NodeSetValue(hashTable->nodes[hash], value) == SUCCESSFUL_CODE)
    {
        hashTable->count++;
        return SUCCESSFUL_CODE;
    }
    return UNSUCCESSFUL_CODE;
}

int GetMaxCountCollisions(const HashTable *hashTable)
{
    int maxCountCollisions = 0;
    for (int i = 0; i < HashTableCapacity(hashTable); i++)
    {
        const Node *node = HashTableNode(hashTable, i);
        if (maxCountCollisions < NodeChildrenCount(node))
            maxCountCollisions = NodeChildrenCount(node);
    }
    return maxCountCollisions;
}

CodeStatus HashTableFree(HashTable *hashTable)
{
    for (int i = 0; i < HashTableCapacity(hashTable); i++)
        NodeFree(hashTable->nodes[i]);
    free(hashTable);
    return SUCCESSFUL_CODE;
}

int GetTableFilledCount(HashTable *hashTable)
{
    int counter = 0;
    for (int i = 0; i < HashTableCapacity(hashTable); i++)
    {
        const Node *node = HashTableNode(hashTable, i);
        if (node != NULL)
            counter++;
    }
    return counter;
}