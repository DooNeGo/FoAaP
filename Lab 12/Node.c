#include <stdlib.h>
#include "Node.h"

typedef struct Node
{
    String *value;
    Status status;
    Node *children;
    unsigned int countChildren;
} Node;

Node *NodeConstructor()
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = NULL;
    node->status = Deleted;
    node->children = NULL;
    node->countChildren = 0;
    return node;
}

Bool NodeCheckValue(const Node *node, const String *value)
{
    if (node == NULL)
        return False;
    if (IsEqualStrings(node->value, value) && node->status == Exist)
        return True;
    return NodeCheckValue(node->children, value);
}

CodeStatus NodeSetValue(Node *node, String *value)
{
    if (node == NULL || value == NULL || IsEqualStrings(node->value, value))
        return UNSUCCESSFUL_CODE;
    if (NodeStatus(node) == Deleted)
    {
        StringFree(node->value);
        node->value = value;
        node->status = Exist;
        return SUCCESSFUL_CODE;
    }
    if (node->children == NULL)
        node->children = NodeConstructor();
    node->countChildren++;
    return NodeSetValue(node->children, value);
}

String *NodeGetValue(Node *node)
{
    return node->value;
}

CodeStatus NodeFree(Node *node)
{
    if (node == NULL)
        return UNSUCCESSFUL_CODE;
    StringFree(node->value);
    NodeFree(node->children);
    free(node);
    return SUCCESSFUL_CODE;
}

CodeStatus NodeSetDeletedStatus(Node *node)
{
    if (node == NULL)
        return UNSUCCESSFUL_CODE;
    node->status = Deleted;
    return SUCCESSFUL_CODE;
}

CodeStatus NodeDelete(Node *node, const String *value)
{
    if (node == NULL)
        return UNSUCCESSFUL_CODE;
    if (IsEqualStrings(node->value, value))
        return NodeSetDeletedStatus(node);
    return NodeDelete(node->children, value);
}

int NodeSize()
{
    return sizeof(Node);
}

int NodeChildrenCount(const Node *node)
{
    if (node == NULL)
        return NULL;
    return node->countChildren;
}

Node *NodeChildren(const Node *node)
{
    return node->children;
}

Status NodeStatus(const Node *node)
{
    return node->status;
}