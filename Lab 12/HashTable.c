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
    {
        hashTable->nodes[i] = NULL;
    }
    return SUCCESSFUL_CODE;
}

HashTable *ConstructHashTable(unsigned int initialSize)
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

int GetHashTableCount(const HashTable *hashTable)
{
    return hashTable->capacity;
}

const Node *GetHashTableNode(const HashTable *hashTable, unsigned int index)
{
    if (hashTable == NULL || index >= GetHashTableCount(hashTable))
        return NULL;
    return hashTable->nodes[index];
}

Bool FindHashTableNodeValue(const HashTable *hashTable, const String *value)
{
    int hash = GetHashCode(value) % GetHashTableCount(hashTable);
    return CheckNodeValue(GetHashTableNode(hashTable, hash), value);
}

CodeStatus DeleteHashTableNode(HashTable *hashTable, const String *value)
{
    int hash = GetHashCode(value) % GetHashTableCount(hashTable);
    if (FindAndDeleteNode(hashTable->nodes[hash], value) == SUCCESSFUL_CODE)
    {
        hashTable->countDeletedNodes++;
        return SUCCESSFUL_CODE;
    }
    return UNSUCCESSFUL_CODE;
}

CodeStatus InsertOldNodesToHashTable(HashTable *hashTable, const Node *node)
{
    if (node == NULL)
        return UNSUCCESSFUL_CODE;
    int childrenCount = GetChildrenCount(node);
    for (int j = 0; j <= childrenCount; j++)
    {
        if (GetNodeStatus(node) == Exist)
            InsertValueToHashTable(hashTable, GetNodeValue(node));
        node = GetNodeChildren(node);
    }
    return SUCCESSFUL_CODE;
}

CodeStatus ResizeHashTable(HashTable *hashTable)
{
    if (hashTable == NULL)
        return UNSUCCESSFUL_CODE;
    int newHashTableSize = hashTable->capacity * 2;
    HashTable *newHashTable = ConstructHashTable(newHashTableSize);
    for (int i = 0; i < GetHashTableCount(hashTable); i++)
    {
        InsertOldNodesToHashTable(newHashTable, GetHashTableNode(hashTable, i));
        FreeNode(hashTable->nodes[i]);
    }
    free(hashTable->nodes);
    hashTable->nodes = newHashTable->nodes;
    hashTable->capacity = newHashTable->capacity;
    hashTable->countDeletedNodes = 0;
    free(newHashTable);
    return SUCCESSFUL_CODE;
}

CodeStatus InsertValueToHashTable(HashTable *hashTable, const String *value)
{
    if (hashTable == NULL || value == NULL)
        return UNSUCCESSFUL_CODE;
    int hash = GetHashCode(value) % GetHashTableCount(hashTable);
    if (GetHashTableNode(hashTable, hash) == NULL)
        hashTable->nodes[hash] = ConstructNode();
    if (GetChildrenCount(GetHashTableNode(hashTable, hash)) > 3)
    {
        ResizeHashTable(hashTable);
        hash = GetHashCode(value) % GetHashTableCount(hashTable);
    }
    return SetValueToNode(hashTable->nodes[hash], value);
}

int GetMaxCountCollisions(const HashTable *hashTable)
{
    int maxCountCollisions = 0;
    for (int i = 0; i < GetHashTableCount(hashTable); i++)
    {
        const Node *node = GetHashTableNode(hashTable, i);
        if (maxCountCollisions < GetChildrenCount(node))
            maxCountCollisions = GetChildrenCount(node);
    }
    return maxCountCollisions;
}

CodeStatus FreeHashTable(HashTable *hashTable)
{
    for (int i = 0; i < GetHashTableCount(hashTable); i++)
        FreeNode(hashTable->nodes[i]);
    free(hashTable);
    return SUCCESSFUL_CODE;
}

int GetTableFilledCount(HashTable *hashTable)
{
    int counter = 0;
    for (int i = 0; i < GetHashTableCount(hashTable); i++)
    {
        const Node *node = GetHashTableNode(hashTable, i);
        if (node != NULL)
            counter++;
    }
    return counter;
}