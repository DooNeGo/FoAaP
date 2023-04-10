#include <stdlib.h>
#include "ApplicationContext.h"

typedef struct ApplicationContext
{
    HashTable *hashTable;
    String *backValue;
} ApplicationContext;

ApplicationContext *ConstructAppContext()
{
    ApplicationContext *appContext = (ApplicationContext *)malloc(sizeof(ApplicationContext));
    appContext->hashTable = NULL;
    appContext->backValue = ConstructString(2);
    SetCharArrToString(appContext->backValue, "0");
    return appContext;
}

const String *GetBackValue(const ApplicationContext *appContext)
{
    return appContext->backValue;
}

CodeStatus SetPtrHashTableToAppContext(ApplicationContext *appContext, HashTable *hashTable)
{
    if (hashTable == NULL)
        return UNSUCCESSFUL_CODE;
    appContext->hashTable = hashTable;
    return SUCCESSFUL_CODE;
}

HashTable *GetHashTableAppContext(ApplicationContext *appContext)
{
    return appContext->hashTable;
}