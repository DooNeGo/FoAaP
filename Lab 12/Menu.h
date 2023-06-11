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
Menu *MenuConstructor2(const char *name, CodeStatus (*action)(const Menu *menu, ApplicationContext *appContext));
CodeStatus MenuAddChild(Menu *parent, Menu *children);
CodeStatus MenuProcess(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuFree(Menu *menu);

CodeStatus MenuDefaultAction(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuAddAction(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuShowAction(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuDeleteAction(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuStatsAction(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuCheckAction(const Menu *menu, ApplicationContext *appContext);

#endif