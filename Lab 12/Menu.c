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
    if (parent->children == NULL)
        parent->children = ArrayConstructor(1, sizeof(Menu));
    ArrayAddPtr(parent->children, children);
    return SUCCESSFUL_CODE;
}

const String *MenuChildrenName(const Menu *menu, unsigned int index)
{
    if (index >= ArrayGetCount(menu->children) || menu->children == NULL)
        return NULL;
    return ((Menu *)ArrayGetElem(menu->children, index))->name;
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
        return NULL;
    return ArrayGetCount(menu->children);
}

CodeStatus MenuFree(Menu *menu)
{
    StringFree(menu->name);
    for (int i = 0; i < MenuChildrenCount(menu); i++)
        MenuFree((Menu *)ArrayGetElem(menu->children, i));
    return ArrayFree(menu->children);
}

CodeStatus MenuAddProcess(ApplicationContext *appContext)
{
    ClearConsole;
    fflush(stdin);
    printf("-----Add-----\n");
    printf("Enter value (0 - Return): ");
    String *newValue = ReadString();
    if (newValue == NULL)
        return UNSUCCESSFUL_CODE;
    HashTableAdd(AppContextGetHTable(appContext), newValue);
    WriteMessage("Successful add", "Green");
    return SUCCESSFUL_CODE;
}

CodeStatus MenuDeleteProcess(ApplicationContext *appContext)
{
    ClearConsole;
    fflush(stdin);
    printf("-----Delete-----\n");
    printf("Enter value (0 - Return): ");
    String *valueString = ReadString();
    if (valueString == NULL)
        return UNSUCCESSFUL_CODE;
    HashTableDeleteValue(AppContextGetHTable(appContext), valueString);
    WriteMessage("Successful delete", "Green");
    return SUCCESSFUL_CODE;
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

void ShowChildren(const Menu *menu)
{
    for (int i = 0; i < MenuChildrenCount(menu); i++)
    {
        printf("%d - ", i + 1);
        WriteString(MenuChildrenName(menu, i));
        printf("\n");
    }
    printf("0 - Return\n");
}

CodeStatus MenuProcess(const Menu *menu, ApplicationContext *appContext)
{
    if (StringEqual(menu->name, "Add"))
        return MenuAddProcess(appContext);
    if (StringEqual(menu->name, "Delete"))
        return MenuDeleteProcess(appContext);
    if (StringEqual(menu->name, "Show"))
        return MenuShowProcess(appContext);
    while (1)
    {
        int value;
        ClearConsole;
        printf("-----");
        WriteString(menu->name);
        printf("-----\n");
        ShowChildren(menu);
        scanf("%d", &value);
        if (value == 0)
            return SUCCESSFUL_CODE;
        else if (value > 0 && value <= MenuChildrenCount(menu))
            MenuProcess(MenuChildren(menu, value - 1), appContext);
        else
            WriteMessage("Wrong value", "Red");
    }
}
