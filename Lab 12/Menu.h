#include "ApplicationContext.h"

#ifndef MENU
#define MENU

typedef struct Menu Menu;
Menu *MenuConstructor(const char *name);
CodeStatus MenuAddChildren(Menu *parent, Menu *children);
CodeStatus MenuProcess(const Menu *menu, ApplicationContext *appContext);
CodeStatus MenuFree(Menu *menu);

#endif