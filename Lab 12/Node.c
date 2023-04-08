#include <stdlib.h>
#include "Node.h"

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

CodeStatus SetValueToNode(Node *node, const String *value)
{
    if (node == NULL || value == NULL || IsEqualStrings(node->value, value))
        return UNSUCCESSFUL_CODE;
    if (GetNodeStatus(node) == Deleted)
    {
        if (node->value == NULL)
            node->value = ConstructString(2);
        else
            ClearString(node->value);
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

const String *GetNodeValue(const Node *node)
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

const Node *GetNodeChildren(const Node *node)
{
    return node->children;
}

Status GetNodeStatus(const Node *node)
{
    return node->status;
}

void FreeNode(Node *node)
{
    if (node == NULL)
        return;
    FreeString(node->value);
    FreeNode(node->children);
    free(node);
    return;
}