#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"
#include "HashTable.h"

typedef struct HashTable
{
    Array *nodes;
    unsigned int countDeletedNodes;
} HashTable;

CodeStatus InitializeHashTableNodes(HashTable *hashTable)
{
    for (int i = 0; i < GetArrCapacity(hashTable->nodes); i++)
    {
        Node *node = ConstructNode();
        InsertElemToArray(hashTable->nodes, node);
    }
    return SUCCESSFUL_CODE;
}

HashTable *ConstructHashTable(int initialSize)
{
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->nodes = ConstructArray(initialSize, GetSizeOfNode());
    InitializeHashTableNodes(hashTable);
    hashTable->countDeletedNodes = 0;
    return hashTable;
}

int GetHashCode(String *string, const int tableCount)
{
    int resultHash = 0;
    for (int i = 0; i < GetCountString(string); i++)
    {
        resultHash = (tableCount * resultHash + GetStringElem(string, i)) % tableCount;
    }
    resultHash = (resultHash << 2 + 1) % tableCount;
    return resultHash;
}

Node *GetHashTableNode(HashTable *hashTable, unsigned int index)
{
    if (hashTable == NULL || index > GetArrCount(hashTable->nodes) || GetArrElem(hashTable->nodes, index) == NULL)
        return NULL;
    return (Node *)GetArrElem(hashTable->nodes, index);
}

Bool FindHashTableNodeValue(const HashTable *hashTable, String *value)
{
    int hash = GetHashCode(value, GetArrCount(hashTable->nodes));
    return CheckNodeValue((Node *)GetArrElem(hashTable->nodes, hash), value);
}

CodeStatus DeleteHashTableNode(HashTable *hashTable, String *value)
{
    int hash = GetHashCode(value, GetArrCount(hashTable->nodes));
    if (FindAndDeleteNode((Node *)GetArrElem(hashTable->nodes, hash), value) == SUCCESSFUL_CODE)
    {
        hashTable->countDeletedNodes++;
        return SUCCESSFUL_CODE;
    }
    return UNSUCCESSFUL_CODE;
}

CodeStatus ResizeHashTable(HashTable *hashTable)
{
    if (hashTable == NULL)
        return UNSUCCESSFUL_CODE;
    int newHashTableSize = GetArrCount(hashTable->nodes) * 2;
    HashTable *newHashTable = ConstructHashTable(newHashTableSize);
    for (int i = 0; i < GetArrCount(hashTable->nodes); i++)
    {
        InsertValueToHashTableNode(newHashTable, GetNodeValue((Node *)GetArrElem(hashTable->nodes, i)));
        Node *children = GetNodeChildren((Node *)GetArrElem(hashTable->nodes, i));
        if (GetNodeStatus(children) == Exist)
            InsertValueToHashTableNode(newHashTable, GetNodeValue(children));
        for (int j = 0; j < GetChildrenCount((Node *)GetArrElem(hashTable->nodes, i)); j++)
        {
            Node *nextChildren = GetNodeChildren(children);
            if (GetNodeStatus(nextChildren) == Exist)
                InsertValueToHashTableNode(newHashTable, GetNodeValue(nextChildren));
            free(children);
            children = nextChildren;
        }
    }
    FreeArray(hashTable->nodes);
    hashTable->nodes = newHashTable->nodes;
    hashTable->countDeletedNodes = 0;
    free(newHashTable);
    return SUCCESSFUL_CODE;
}

CodeStatus InsertValueToHashTableNode(HashTable *hashTable, String *value)
{
    if (hashTable == NULL || value == NULL)
        return UNSUCCESSFUL_CODE;
    int hash = GetHashCode(value, GetArrCount(hashTable->nodes));
    if (GetChildrenCount((Node *)GetArrElem(hashTable->nodes, hash)) > 9)
        ResizeHashTable(hashTable);
    return SetValueToNode((Node *)GetArrElem(hashTable->nodes, hash), value);
}