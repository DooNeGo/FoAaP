#include <stdlib.h>
#include "Node.h"

typedef struct Node
{
    String *value;
    Status status;
    Node *children;
} Node;

Node *NodeConstructor()
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = NULL;
    node->status = DELETED;
    node->children = NULL;
    return node;
}

Bool NodeCheckValue(const Node *node, const String *value)
{
    if (node == NULL)
        return FALSE;
    if (IsStringsEqual(NodeGetValue(node), value) && NodeStatus(node) == EXIST)
        return TRUE;
    return NodeCheckValue(node->children, value);
}

CodeStatus NodeSetValue(Node *node, String *value)
{
    if (node == NULL || value == NULL || IsStringsEqual(node->value, value) && NodeStatus(node) == EXIST)
        return UNSUCCESSFUL_CODE;
    if (NodeStatus(node) == DELETED)
    {
        StringFree(node->value);
        node->value = value;
        node->status = EXIST;
        return SUCCESSFUL_CODE;
    }
    if (node->children == NULL)
        node->children = NodeConstructor();
    return NodeSetValue(node->children, value);
}

String *NodeGetValue(const Node *node)
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
    node->status = DELETED;
    return SUCCESSFUL_CODE;
}

CodeStatus NodeDelete(Node *node, const String *value)
{
    if (node == NULL)
        return UNSUCCESSFUL_CODE;
    if (IsStringsEqual(node->value, value))
        return NodeSetDeletedStatus(node);
    return NodeDelete(node->children, value);
}

int NodeSize()
{
    return sizeof(Node);
}

int CountChildren(const Node *children)
{
    if (children == NULL)
        return 0;
    int counter = 1;
    counter += CountChildren(NodeChildren(children));
    return counter;
}

int NodeChildrenCount(const Node *node)
{
    if (node == NULL)
        return 0;
    return CountChildren(NodeChildren(node));
}

Node *NodeChildren(const Node *node)
{
    return node->children;
}

Status NodeStatus(const Node *node)
{
    return node->status;
}