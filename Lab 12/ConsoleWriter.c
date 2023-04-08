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
    for (int i = 0; i < GetHashTableCount(hashTable); i++);
    return SUCCESSFUL_CODE;
}