#include <stdio.h>
#include <stdlib.h>
#include "ConsoleWriter.h"

#define ConsoleColorRed system("color 4")
#define ConsoleColorGreen system("color A")
#define ConsoleClear system("cls")

CodeStatus WriteString(const String *str)
{
    if (str == NULL)
        return UNSUCCESSFUL_CODE;
    for (int i = 0; i < StringLength(str); i++)
        printf("%c", StringElem(str, i));
    return SUCCESSFUL_CODE;
}

CodeStatus WriteLineString(const String *str)
{
    if (str == NULL)
        return UNSUCCESSFUL_CODE;
    for (int i = 0; i < StringLength(str); i++)
        printf("%c", StringElem(str, i));
    printf("\n");
    return SUCCESSFUL_CODE;
}

CodeStatus WriteMessage(const char *message, Color color)
{
    ConsoleClear;
    fflush(stdin);
    if (color == Red)
        ConsoleColorRed;
    else if (color == Green)
        ConsoleColorGreen;
    printf("-----Message-----");
    printf("\n%s\n", message);
    system("pause");
    system("color 7");
    return SUCCESSFUL_CODE;
}

CodeStatus WriteHashTableNode(Node *node, int counter)
{
    if (node == NULL)
        return UNSUCCESSFUL_CODE;
    int countChildren = NodeChildrenCount(node);
    printf("%d. ", counter);
    for (int i = 0; i <= countChildren; i++)
    {
        if (NodeStatus(node) == Exist)
            WriteLineString(NodeGetValue(node));
        node = NodeChildren(node);
    }
    return SUCCESSFUL_CODE;
}

CodeStatus WriteHashTable(const HashTable *hashTable)
{
    if (hashTable == NULL)
        return UNSUCCESSFUL_CODE;
    int counter = 0;
    for (int i = 0; i < HashTableCapacity(hashTable); i++)
    {
        Node *node = HashTableNode(hashTable, i);
        if (node == NULL)
            continue;
        counter++;
        WriteHashTableNode(node, counter);
    }
    return SUCCESSFUL_CODE;
}

CodeStatus WriteEachNodeCollisionWithStats(HashTable *hashTable)
{
    int temp = 0;
    for (int i = 0; i < HashTableCapacity(hashTable); i++)
    {
        if (HashTableNode(hashTable, i) != NULL)
            printf("  %2d. %d\n", i + 1, NodeChildrenCount(HashTableNode(hashTable, i)) + 1);
        else
            printf("  %2d. %d\n", i + 1, 0);
        temp += NodeChildrenCount(HashTableNode(hashTable, i));
    }

    printf("\nAverage collisions: %.2f", (double)temp / (double)GetTableFilledCount(hashTable));
    printf("\nFill: %.2f\n", (double)GetTableFilledCount(hashTable) / (double)HashTableCapacity(hashTable));
    printf("Number of deleted items: %d\n", HashTableCountDeletedNodes(hashTable));
    printf("Number of exist items: %d\n", HashTableCount(hashTable));

    return SUCCESSFUL_CODE;
}