#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "DynamicArray.h"
#include "ConsoleWriter.h"
#include "ConsoleReader.h"

#define ClearConsole system("cls");

typedef struct Menu
{
    String *name;
    Array *children;
} Menu;

Menu *MenuConstructor(const char *name)
{
    Menu *menu = (Menu *)malloc(sizeof(Menu));
    menu->name = StringConstructor(2);
    StringSetValue(menu->name, name);
    menu->children = NULL;
    return menu;
}

CodeStatus MenuAddChildren(Menu *parent, Menu *children)
{
    if (parent == NULL || children == NULL)
        return UNSUCCESSFUL_CODE;
    if (parent->children == NULL)
        parent->children = ArrayConstructor(1, sizeof(Menu));
    ArrayAddPtr(parent->children, children);
    return SUCCESSFUL_CODE;
}

const String *MenuName(const Menu *menu)
{
    return menu->name;
}

const Menu *MenuChildren(const Menu *menu, unsigned int index)
{
    if (index > ArrayGetCount(menu->children) || menu->children == NULL)
        return NULL;
    return (Menu *)ArrayGetElem(menu->children, index);
}

int MenuChildrenCount(const Menu *menu)
{
    if (menu->children == NULL)
        return 0;
    return ArrayGetCount(menu->children);
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

CodeStatus MenuAddProcess(ApplicationContext *appContext)
{
    if (appContext == NULL)
        return UNSUCCESSFUL_CODE;
    while (1)
    {
        ClearConsole;
        printf("-----Add-----\n");
        printf("Enter value (0 - Return): ");
        String *newValue = ReadString();
        if (newValue == NULL)
            return SUCCESSFUL_CODE;
        if (HashTableAdd(AppContextGetHTable(appContext), newValue) == SUCCESSFUL_CODE)
            WriteMessage("Successful add", Green);
        else
            WriteMessage("Unsuccessful add", Red);
    }
}

CodeStatus MenuShowProcess(ApplicationContext *appContext)
{
    if (appContext == NULL)
        return UNSUCCESSFUL_CODE;
    ClearConsole;
    printf("-----Show-----\n");
    if (HashTableCount(AppContextGetHTable(appContext)) > 0)
        WriteHashTable(AppContextGetHTable(appContext));
    else
        printf("Empty...\n");
    system("pause");
    return SUCCESSFUL_CODE;
}

CodeStatus MenuDeleteProcess(ApplicationContext *appContext)
{
    if (appContext == NULL)
        return UNSUCCESSFUL_CODE;
    while (1)
    {
        ClearConsole;
        printf("-----Delete-----\n");
        printf("Enter value (0 - Return): ");
        String *valueString = ReadString();
        if (valueString == NULL)
            return SUCCESSFUL_CODE;
        if (HashTableDeleteValue(AppContextGetHTable(appContext), valueString) == SUCCESSFUL_CODE)
            WriteMessage("Successful delete", Green);
        else
            WriteMessage("Unsuccessful delete", Red);
        StringFree(valueString);
    }
}

CodeStatus MenuStatsProcess(ApplicationContext *appContext)
{
    if (appContext == NULL)
        return UNSUCCESSFUL_CODE;
    ClearConsole;
    printf("-----Stats-----");
    printf("\nMax collision: %d\n", GetMaxCountCollisions(AppContextGetHTable(appContext)));
    WriteEachNodeCollisionWithStats(AppContextGetHTable(appContext));
    system("pause");
    return SUCCESSFUL_CODE;
}

CodeStatus MenuCheckProcess(ApplicationContext *appContext)
{
    if (appContext == NULL)
        return UNSUCCESSFUL_CODE;
    while (1)
    {
        ClearConsole;
        printf("-----Check-----\n");
        printf("Enter value (0 - Return): ");
        String *valueString = ReadString();
        if (valueString == NULL)
            return SUCCESSFUL_CODE;
        if (HashTableFindValue(AppContextGetHTable(appContext), valueString))
            WriteMessage("Such an element exists", Green);
        else
            WriteMessage("No such element exists", Red);
    }
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

CodeStatus MenuProcess(const Menu *menu, ApplicationContext *appContext)
{
    if (StringEquals(MenuName(menu), "Add"))
        return MenuAddProcess(appContext);
    if (StringEquals(MenuName(menu), "Delete"))
        return MenuDeleteProcess(appContext);
    if (StringEquals(MenuName(menu), "Show"))
        return MenuShowProcess(appContext);
    if (StringEquals(MenuName(menu), "Stats"))
        return MenuStatsProcess(appContext);
    if (StringEquals(MenuName(menu), "Check"))
        return MenuCheckProcess(appContext);

    while (1)
    {
        int value;
        ClearConsole;
        fflush(stdin);
        printf("-----");
        WriteString(MenuName(menu));
        printf("-----\n");
        ShowChildren(menu);
        scanf_s("%d", &value);
        if (value == 0)
            return SUCCESSFUL_CODE;
        else if (value > 0 && value <= MenuChildrenCount(menu))
            MenuProcess(MenuChildren(menu, value - 1), appContext);
        else
            WriteMessage("Wrong value", Red);
    }
}
