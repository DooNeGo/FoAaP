#include <stdlib.h>
#include "ApplicationContext.h"

typedef struct ApplicationContext
{
    HashTable *hashTable;
    Array *findItems;
    String *currentItem;
} ApplicationContext;

ApplicationContext *AppContextConstructor(HashTable *hashTable)
{
    ApplicationContext *appContext = (ApplicationContext *)malloc(sizeof(ApplicationContext));
    appContext->hashTable = hashTable;
    appContext->findItems = NULL;
    appContext->currentItem = NULL;
    return appContext;
}

HashTable *AppContextHashTable(const ApplicationContext *appContext)
{
    if (appContext == NULL)
        return NULL;
    return appContext->hashTable;
}

Array *AppContextFindItems(const ApplicationContext *appContext)
{
    if (appContext == NULL)
        return NULL;
    return appContext->findItems;
}

String *AppContextCurrentItem(const ApplicationContext *appContext)
{
    if (appContext == NULL)
        return NULL;
    return appContext->currentItem;
}

CodeStatus AppContextSetFindItems(ApplicationContext *appContext, Array *findItems)
{
    if (appContext == NULL)
        return UNSUCCESSFUL_CODE;
    appContext->findItems = findItems;
    return SUCCESSFUL_CODE;
}

CodeStatus AppContextSetCurrentItem(ApplicationContext *appContext, String *str)
{
    if (appContext == NULL || str == NULL)
        return UNSUCCESSFUL_CODE;
    appContext->currentItem = str;
    return SUCCESSFUL_CODE;
}

CodeStatus AppContextFree(ApplicationContext *appContext)
{
    if (appContext == NULL)
        return UNSUCCESSFUL_CODE;
    free(appContext);
    return SUCCESSFUL_CODE;
}

void InsertNodeValueToArray(Node *node, Array *arr)
{
    if (node == NULL || arr == NULL)
        return;
    if (NodeStatus(node) == EXIST)
        ArrayAdd(arr, NodeGetValue(node));
    InsertNodeValueToArray(NodeChildren(node), arr);
}

CodeStatus AppContextConvertHTableElemsToArray(ApplicationContext *appContext)
{
    if (appContext == NULL)
        return UNSUCCESSFUL_CODE;
    appContext->findItems = ArrayConstructor(2, StringSize());
    for (int i = 0; i < HashTableCapacity(AppContextHashTable(appContext)); i++)
        InsertNodeValueToArray(HashTableNode(AppContextHashTable(appContext), i), AppContextFindItems(appContext));
    return SUCCESSFUL_CODE;
}