#include <stdio.h>
#include "ConsoleWriter.h"
#include "DynamicArray.h"

CodeStatus WriteString(const String *str)
{
    if (str == NULL)
        return UNSUCCESSFUL_CODE;
    for (int i = 0; i < GetStringCount(str); i++)
    {
        printf("%c", GetStringElem(str, i));
    }
    if (GetStringCount(str) > 0)
        printf("\n");
    return SUCCESSFUL_CODE;
}

CodeStatus WriteHashTableNode(const Node *node)
{
    if (node == NULL)
        return UNSUCCESSFUL_CODE;
    int countChildren = GetChildrenCount(node);
    for (int i = 0; i <= countChildren; i++)
    {
        if (GetNodeStatus(node) == Exist)
            WriteString(GetNodeValue(node));
        node = GetNodeChildren(node);
    }
    return SUCCESSFUL_CODE;
}

CodeStatus WriteEachNodeCollision(HashTable *hashTable)
{
    int temp = 0;
    for (int i = 0; i < GetHashTableCount(hashTable); i++)
    {
        if (GetHashTableNode(hashTable, i) != NULL)
            printf("  %2d. %d\n", i + 1, GetChildrenCount(GetHashTableNode(hashTable, i)) + 1);
        else
            printf("  %2d. %d\n", i + 1, NULL);
        temp += GetChildrenCount(GetHashTableNode(hashTable, i));
    }
    printf("\nAverage collisions: %.2f", (double)temp / (double)GetTableFilledCount(hashTable));
    printf("\nFill: %.2f\n", (double)GetTableFilledCount(hashTable) / (double)GetHashTableCount(hashTable));
    return SUCCESSFUL_CODE;
}