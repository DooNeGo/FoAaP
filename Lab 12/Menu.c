#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "DynamicArray.h"
#include "ConsoleWriter.h"
#include "ConsoleReader.h"

#define Clear_Console system("cls");

typedef struct Menu
{
    String *name;
    Array *children;
} Menu;

Menu *ConstructMenu(const char *name)
{
    Menu *menu = (Menu *)malloc(sizeof(Menu));
    menu->name = ConstructString(2);
    SetCharArrToString(menu->name, name);
    menu->children = NULL;
    return menu;
}

CodeStatus AddMenuChildren(Menu *parent, Menu *children)
{
    if (parent->children == NULL)
        parent->children = ConstructArray(1, sizeof(Menu));
    InsertPtrElemToArray(parent->children, children);
    return SUCCESSFUL_CODE;
}

const String *GetChildrenMenuName(const Menu *menu, unsigned int index)
{
    if (index >= GetArrCount(menu->children) || menu->children == NULL)
        return NULL;
    return ((Menu *)GetArrElem(menu->children, index))->name;
}

const Menu *GetMenuChildren(const Menu *menu, unsigned int index)
{
    if (index > GetArrCount(menu->children) || menu->children == NULL)
        return NULL;
    return (Menu *)GetArrElem(menu->children, index);
}

int GetMenuChildrenCount(const Menu *menu)
{
    if (menu->children == NULL)
        return NULL;
    return GetArrCount(menu->children);
}

CodeStatus FreeMenu(Menu *menu)
{
    FreeArray(menu->children);
    FreeString(menu->name);
    return SUCCESSFUL_CODE;
}

CodeStatus ProcessAddMenu(ApplicationContext *appContext)
{
    system("cls");
    fflush(stdin);
    printf("-----Add-----\n");
    printf("Enter value (0 - Return): ");
    String *newValue = ReadStringPtr();
    if (IsEqualStrings(newValue, GetBackValue(appContext)))
        return SUCCESSFUL_CODE;
    system("pause");
    InsertValueToHashTable(GetHashTableAppContext(appContext), newValue);
    FreeString(newValue);
    return SUCCESSFUL_CODE;
}

CodeStatus ProcessMenu(const Menu *menu, ApplicationContext *appContext)
{
    while (1)
    {
        String *name = ConstructString(GetStringCount(menu->name));
        SetCharArrToString(name, "Add");
        if (IsEqualStrings(menu->name, name))
            return ProcessAddMenu(appContext);
        int value;
        Clear_Console;
        printf("-----");
        WriteString(menu->name);
        printf("-----\n");
        for (int i = 0; i < GetMenuChildrenCount(menu); i++)
        {
            printf("%d - ", i + 1);
            WriteString(GetChildrenMenuName(menu, i));
            printf("\n");
        }
        printf("0 - Return\n");
        scanf("%d", &value);
        if (value <= 0 || value > GetMenuChildrenCount(menu))
            return SUCCESSFUL_CODE;
        else if (value > 0 && value <= GetMenuChildrenCount(menu))
        {
            ProcessMenu(GetMenuChildren(menu, value - 1), appContext);
        }
    }
}
