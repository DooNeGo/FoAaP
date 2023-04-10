#include "String.h"

#ifndef STATUS
#define STATUS

typedef enum Status
{
    Deleted = 0,
    Exist = 1
} Status;

#endif

#ifndef BOOL
#define BOOL

typedef enum Bool
{
    False = 0,
    True = 1,
} Bool;

#endif

#ifndef CODE_STATUS
#define CODE_STATUS

typedef enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
    ArgumentOutOfRangeException = 2,
} CodeStatus;

#endif

#ifndef NODE
#define NODE

typedef struct Node Node;
Node *NodeConstructor();
CodeStatus NodeDelete(Node *node, const String *value);
CodeStatus NodeSetValue(Node *node, String *value);
String *NodeGetValue(Node *node);
int NodeChildrenCount(const Node *node);
Node *NodeChildren(const Node *node);
Status NodeStatus(const Node *node);
Bool NodeCheckValue(const Node *node, const String *value);
int NodeSize();
CodeStatus NodeFree(Node *node);

#endif