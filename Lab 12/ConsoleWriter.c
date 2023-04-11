#include <stdio.h>
#include <stdlib.h>
#include "ConsoleWriter.h"
#include "DynamicArray.h"

#define ConsoleColorRed system("color 4")
#define ConsoleColorGreen system("color A")
#define ConsoleColorWhite system("color 7")
#define ConsoleClear system("cls")

CodeStatus WriteString(const String *str)
{
    if (str == NULL)
        return UNSUCCESSFUL_CODE;

    for (int i = 0; i < StringCount(str); i++)
        printf("%c", StringElem(str, i));

    return SUCCESSFUL_CODE;
}

CodeStatus WriteLineString(const String *str)
{
    if (str == NULL)
        return UNSUCCESSFUL_CODE;

    for (int i = 0; i < StringCount(str); i++)
        printf("%c", StringElem(str, i));

    if (StringCount(str) > 0)
        printf("\n");

    return SUCCESSFUL_CODE;
}

CodeStatus WriteMessage(const char *message, const char *color)
{
    ConsoleClear;
    fflush(stdin);
    printf("-----Message-----");
    if (color == "Red")
        ConsoleColorRed;
    else if (color == "Green")
        ConsoleColorGreen;
    printf("\n%s\n", message);
    system("pause");
    ConsoleColorWhite;
    return SUCCESSFUL_CODE;
}

CodeStatus WriteHashTableNode(Node *node)
{
    if (node == NULL)
        return UNSUCCESSFUL_CODE;
    int countChildren = NodeChildrenCount(node);
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
    for (int i = 0; i < HashTableCapacity(hashTable); i++)
        WriteHashTableNode(HashTableNode(hashTable, i));
    return SUCCESSFUL_CODE;
}

CodeStatus WriteEachNodeCollision(HashTable *hashTable)
{
    int temp = 0;
    for (int i = 0; i < HashTableCapacity(hashTable); i++)
    {
        if (HashTableNode(hashTable, i) != NULL)
            printf("  %2d. %d\n", i + 1, NodeChildrenCount(HashTableNode(hashTable, i)) + 1);
        else
            printf("  %2d. %d\n", i + 1, NULL);
        temp += NodeChildrenCount(HashTableNode(hashTable, i));
    }
    printf("\nAverage collisions: %.2f", (double)temp / (double)GetTableFilledCount(hashTable));
    printf("\nFill: %.2f\n", (double)GetTableFilledCount(hashTable) / (double)HashTableCapacity(hashTable));
    return SUCCESSFUL_CODE;
}