#include "ApplicationContext.h"

#ifndef CODE_STATUS
#define CODE_STATUS

typedef enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
} CodeStatus;

#endif

#ifndef MENU
#define MENU

typedef struct Menu Menu;
Menu *MenuConstructor(const char *name);
CodeStatus MenuAddChildren(Menu *parent, Menu *children);
CodeStatus MenuProcess(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuFree(Menu *menu);

#endif