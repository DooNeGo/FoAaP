#include <stdio.h>
#include <stdlib.h>
#include "DooNeGo.h"
#include "HashTable.h"

int main(int argc, char **argv)
{
    HashTable *hashTable = ConstructHashTable(50);

    printf("Input:\n");

    InsertValueToHashTableNode(hashTable, ReadStringPtr());
    InsertValueToHashTableNode(hashTable, ReadStringPtr());
    InsertValueToHashTableNode(hashTable, ReadStringPtr());

    printf("\nOutput:\n");
    for (int i = 0; i < 50; i++)
        WriteHashTableNode(GetHashTableNode(hashTable, i));

    system("pause");
    return SUCCESSFUL_CODE;
}