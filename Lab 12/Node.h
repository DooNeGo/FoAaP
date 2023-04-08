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
Node *ConstructNode();
CodeStatus FindAndDeleteNode(Node *node, const String *value);
CodeStatus SetValueToNode(Node *node, const String *value);
const String *GetNodeValue(const Node *node);
int GetChildrenCount(const Node *node);
const Node *GetNodeChildren(const Node *node);
Status GetNodeStatus(const Node *node);
Bool CheckNodeValue(const Node *node, const String *value);
int GetSizeOfNode();
void FreeNode(Node *node);

#endif