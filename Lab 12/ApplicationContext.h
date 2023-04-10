#include "HashTable.h"

#ifndef APP_CONTEXT
#define APP_CONTEXT

typedef struct ApplicationContext ApplicationContext;
ApplicationContext *AppContextConstructor();
HashTable *AppContextGetHTable(const ApplicationContext *appContext);
CodeStatus AppContextSetHTable(ApplicationContext *appContext, HashTable *hashTable);

#endif