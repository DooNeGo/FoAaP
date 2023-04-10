#include "String.h"
#include "ApplicationContext.h"

#ifndef MENU
#define MENU

typedef struct Menu Menu;
Menu *ConstructMenu(const char *name);
CodeStatus AddMenuChildren(Menu *parent, Menu *children);
CodeStatus ProcessMenu(const Menu *menu, ApplicationContext *appContext);
CodeStatus FreeMenu(Menu *menu);

#endif