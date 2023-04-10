#include "HashTable.h"

#ifndef APP_CONTEXT
#define APP_CONTEXT

typedef struct ApplicationContext ApplicationContext;
ApplicationContext *ConstructAppContext();
HashTable *GetHashTableAppContext(ApplicationContext *appContext);
CodeStatus SetPtrHashTableToAppContext(ApplicationContext *appContext, HashTable *hashTable);
const String *GetBackValue(const ApplicationContext *appContext);

#endif