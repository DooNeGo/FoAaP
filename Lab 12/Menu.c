#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "DynamicArray.h"
#include "ConsoleWriter.h"
#include "ConsoleReader.h"

#define ClearConsole system("cls")

typedef struct Menu
{
    String *name;
    CodeStatus (*action)(const Menu *, ApplicationContext *);
    Array *children;
} Menu;

Menu *MenuConstructor(const char *name)
{
    Menu *menu = (Menu *)malloc(sizeof(Menu));
    menu->name = StringConstructor(2);
    StringSetValue(menu->name, name);
    menu->children = NULL;
    menu->action = MenuDefaultProcess;
    return menu;
}

Menu *MenuConstructor2(const char *name, CodeStatus (*action)(const Menu *menu, ApplicationContext *appContext))
{
    Menu *menu = (Menu *)malloc(sizeof(Menu));
    menu->name = StringConstructor(2);
    StringSetValue(menu->name, name);
    menu->children = NULL;
    menu->action = action;
    return menu;
}

CodeStatus MenuAddChildren(Menu *parent, Menu *children)
{
    if (parent == NULL || children == NULL)
        return UNSUCCESSFUL_CODE;
    if (parent->children == NULL)
        parent->children = ArrayConstructor(1, sizeof(Menu));
    ArrayAdd(parent->children, children);
    return SUCCESSFUL_CODE;
}

const String *MenuName(const Menu *menu)
{
    return menu->name;
}

const Menu *MenuChildren(const Menu *menu, unsigned int index)
{
    if (index > ArrayCount(menu->children) || menu->children == NULL)
        return NULL;
    return (Menu *)ArrayGetElem(menu->children, index);
}

int MenuChildrenCount(const Menu *menu)
{
    if (menu->children == NULL)
        return 0;
    return ArrayCount(menu->children);
}

CodeStatus MenuFree(Menu *menu)
{
    if (menu == NULL)
        return UNSUCCESSFUL_CODE;
    StringFree(menu->name);
    for (int i = 0; i < MenuChildrenCount(menu); i++)
        MenuFree((Menu *)ArrayGetElem(menu->children, i));
    return ArrayFree(menu->children);
}

CodeStatus MenuAdd(const Menu *menu, ApplicationContext *appContext)
{
    printf("Enter value (0 - Return): ");
    String *newValue = ReadString();
    if (newValue == NULL)
        return SUCCESSFUL_CODE;
    if (HashTableAdd(AppContextHashTable(appContext), newValue) == SUCCESSFUL_CODE)
        WriteMessage("Successful add", GREEN);
    else
        WriteMessage("Unsuccessful add", RED);
    return UNSUCCESSFUL_CODE;
}

CodeStatus MenuShow(const Menu *menu, ApplicationContext *appContext)
{
    if (HashTableCount(AppContextHashTable(appContext)) > 0)
        WriteHashTable(AppContextHashTable(appContext));
    else
        printf("Empty...\n");
    system("pause");
    return SUCCESSFUL_CODE;
}

CodeStatus MenuDelete(const Menu *menu, ApplicationContext *appContext)
{
    printf("Enter value (0 - Return): ");
    String *valueString = ReadString();
    if (valueString == NULL)
        return SUCCESSFUL_CODE;
    if (HashTableDeleteValue(AppContextHashTable(appContext), valueString) == SUCCESSFUL_CODE)
        WriteMessage("Successful delete", GREEN);
    else
        WriteMessage("Unsuccessful delete", RED);
    StringFree(valueString);
    return UNSUCCESSFUL_CODE;
}

CodeStatus MenuStats(const Menu *menu, ApplicationContext *appContext)
{
    printf("Max collision: %d\n", GetMaxCountCollisions(AppContextHashTable(appContext)));
    WriteEachNodeCollisionWithStats(AppContextHashTable(appContext));
    system("pause");
    return SUCCESSFUL_CODE;
}

CodeStatus MenuCheck(const Menu *menu, ApplicationContext *appContext)
{
    printf("Enter value (0 - Return): ");
    String *valueString = ReadString();
    if (valueString == NULL)
        return SUCCESSFUL_CODE;
    if (HashTableFindValue(AppContextHashTable(appContext), valueString))
        WriteMessage("Such an element exists", GREEN);
    else
        WriteMessage("No such element exists", RED);
    return UNSUCCESSFUL_CODE;
}

void ShowChildren(const Menu *menu)
{
    for (int i = 0; i < MenuChildrenCount(menu); i++)
    {
        printf("%d - ", i + 1);
        WriteString(MenuName(MenuChildren(menu, i)));
        printf("\n");
    }
    printf("0 - Return\n");
}

CodeStatus MenuDefaultProcess(const Menu *menu, ApplicationContext *appContext)
{
    int value = 100;
    ShowChildren(menu);
    fflush(stdin);
    scanf("%d", &value);
    if (value == 0)
        return SUCCESSFUL_CODE;
    else if (value > 0 && value <= MenuChildrenCount(menu))
        MenuProcess(MenuChildren(menu, value - 1), appContext);
    else
        WriteMessage("Wrong value", RED);
    return UNSUCCESSFUL_CODE;
}

CodeStatus MenuProcess(const Menu *menu, ApplicationContext *appContext)
{
    if (menu == NULL || appContext == NULL)
        return UNSUCCESSFUL_CODE;
    while (1)
    {
        ClearConsole;
        printf("-----");
        WriteString(MenuName(menu));
        printf("-----\n");
        if (menu->action(menu, appContext) == SUCCESSFUL_CODE)
            return SUCCESSFUL_CODE;
    }
}
