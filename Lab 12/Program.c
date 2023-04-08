#include <stdio.h>
#include <stdlib.h>
#include "DooNeGo.h"
#include "HashTable.h"

int main(int argc, char **argv)
{
    HashTable *hashTable = ConstructHashTable(20);
    String *str = ReadStringPtr();

    printf("Input:\n");

    InsertValueToHashTable(hashTable, str);
    DeleteHashTableNode(hashTable, str);

    printf("\nOutput:\n");
    for (int i = 0; i < GetHashTableCount(hashTable); i++)
        WriteHashTableNode(GetHashTableNode(hashTable, i));
    printf("\nCollisions: %d\n", GetMaxCountCollisions(hashTable));

    FreeString(str);
    FreeHashTable(hashTable);

    system("pause");
    return SUCCESSFUL_CODE;
}