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
CodeStatus MenuAddChildren(Menu *parent, Menu *children);
CodeStatus MenuProcess(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuFree(Menu *menu);

CodeStatus MenuDefaultProcess(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuAdd(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuShow(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuDelete(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuStats(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuCheck(const Menu *menu, ApplicationContext *appContext);

#endif