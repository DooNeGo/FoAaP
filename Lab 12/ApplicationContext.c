#include <stdlib.h>
#include "ApplicationContext.h"

typedef struct ApplicationContext
{
    HashTable *hashTable;
} ApplicationContext;

ApplicationContext *AppContextConstructor()
{
    ApplicationContext *appContext = (ApplicationContext *)malloc(sizeof(ApplicationContext));
    appContext->hashTable = NULL;
    return appContext;
}

CodeStatus AppContextSetHTable(ApplicationContext *appContext, HashTable *hashTable)
{
    if (hashTable == NULL)
        return UNSUCCESSFUL_CODE;
    appContext->hashTable = hashTable;
    return SUCCESSFUL_CODE;
}

HashTable *AppContextGetHTable(const ApplicationContext *appContext)
{
    return appContext->hashTable;
}