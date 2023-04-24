#include "HashTable.h"
#include "DynamicArray.h"
#include "String.h"

#ifndef CODE_STATUS
#define CODE_STATUS

typedef enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
} CodeStatus;

#endif

#ifndef APP_CONTEXT
#define APP_CONTEXT

typedef struct ApplicationContext ApplicationContext;
ApplicationContext *AppContextConstructor(HashTable *hashTable);
HashTable *AppContextHashTable(const ApplicationContext *appContext);
Array *AppContextFindItems(const ApplicationContext *appContext);
String *AppContextCurrentItem(const ApplicationContext *appContext);
CodeStatus AppContextSetFindItems(ApplicationContext *appContext, Array *findItems);
CodeStatus AppContextSetCurrentItem(ApplicationContext *appContext, String *str);
CodeStatus AppContextFree(ApplicationContext *appContext);
CodeStatus AppContextConvertHTableElemsToArray(ApplicationContext *appContext);

#endif