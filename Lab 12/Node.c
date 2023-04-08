#include <stdlib.h>
#include "Node.h"
#include "DynamicArray.h"

typedef struct Node
{
    String *value;
    Status status;
    Node *children;
    unsigned int countChildren;
} Node;

Node *ConstructNode()
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = NULL;
    node->status = Deleted;
    node->children = NULL;
    node->countChildren = 0;
    return node;
}

Bool CheckNodeValue(const Node *node, const String *value)
{
    if (node == NULL)
        return False;
    if (IsEqualStrings(node->value, value))
        return True;
    return CheckNodeValue(node->children, value);
}

CodeStatus SetValueToNode(Node *node, String *value)
{
    if (node == NULL || value == NULL || IsEqualStrings(node->value, value))
        return UNSUCCESSFUL_CODE;
    if (node->status == Deleted)
    {
        node->value = ConstructString(2);
        SetPtrString(node->value, value);
        node->status = Exist;
        return SUCCESSFUL_CODE;
    }
    if (node->children == NULL)
        node->children = ConstructNode();
    node->countChildren++;
    return SetValueToNode(node->children, value);
}

CodeStatus DeleteNode(Node *node)
{
    if (node == NULL)
        return UNSUCCESSFUL_CODE;
    node->status = Deleted;
    return SUCCESSFUL_CODE;
}

CodeStatus FindAndDeleteNode(Node *node, const String *value)
{
    if (node == NULL)
        return UNSUCCESSFUL_CODE;
    if (IsEqualStrings(node->value, value))
        return DeleteNode(node);
    return FindAndDeleteNode(node->children, value);
}

String *GetNodeValue(Node *node)
{
    return node->value;
}

int GetSizeOfNode()
{
    return sizeof(Node);
}

int GetChildrenCount(const Node *node)
{
    return node->countChildren;
}

Node *GetNodeChildren(Node *node)
{
    return node->children;
}

Status GetNodeStatus(const Node *node)
{
    return node->status;
}