#include <stdio.h>
#include <stdlib.h>
#include "DooNeGo.h"
#include "HashTable.h"
#include "Menu.h"
#include "ApplicationContext.h"

Menu *InitializeMenu()
{
    Menu *mainMenu = ConstructMenu("Main menu");

    Menu *hashTableMenu = ConstructMenu("HS interaction");
    Menu *hashTableMenuStats = ConstructMenu("HS statistics");

    Menu *addHashTableItem = ConstructMenu("Add");
    Menu *deleteHashTableItem = ConstructMenu("Delete");

    AddMenuChildren(mainMenu, hashTableMenu);
    AddMenuChildren(mainMenu, hashTableMenuStats);

    AddMenuChildren(hashTableMenu, addHashTableItem);
    AddMenuChildren(hashTableMenu, deleteHashTableItem);

    return mainMenu;
}

int main(int argc, char **argv)
{
    HashTable *hashTable = ConstructHashTable(20);
    ApplicationContext *appContext = ConstructAppContext();

    SetPtrHashTableToAppContext(appContext, hashTable);

    /* printf("Input:\n");
    for (int i = 0; i < 20; i++)
    {
        String *str = ReadStringPtr();
        InsertValueToHashTable(hashTable, str);
        FreeString(str);
    }

    printf("\nOutput:\n");
    for (int i = 0; i < GetHashTableCount(hashTable); i++)
    {
        WriteHashTableNode(GetHashTableNode(hashTable, i));
    }
    printf("\nMax collision: %d\n", GetMaxCountCollisions(hashTable));

    WriteEachNodeCollision(hashTable);*/


    Menu *menu = InitializeMenu();

    ProcessMenu(menu, appContext);

    FreeHashTable(hashTable);
    FreeMenu(menu);
    system("pause");
    return SUCCESSFUL_CODE;
}