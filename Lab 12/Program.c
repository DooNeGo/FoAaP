#include <stdio.h>
#include <stdlib.h>
#include "DooNeGo.h"
#include "HashTable.h"

int main(int argc, char **argv)
{
    HashTable *hashTable = ConstructHashTable(30);

    printf("Input:\n");
    for (int i = 0; i < 30; i++)
    {
        String *str = ReadStringPtr();
        InsertValueToHashTable(hashTable, str);
        FreeString(str);
    }

    printf("\nOutput:\n");
    for (int i = 0; i < GetHashTableCount(hashTable); i++)
        WriteHashTableNode(GetHashTableNode(hashTable, i));
    printf("\nMax collision: %d\n", GetMaxCountCollisions(hashTable));

    WriteEachNodeCollision(hashTable);

    FreeHashTable(hashTable);

    system("pause");
    return SUCCESSFUL_CODE;
}