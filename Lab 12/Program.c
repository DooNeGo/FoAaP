#include <stdio.h>
#include <stdlib.h>
#include "DooNeGo.h"
#include "HashTable.h"
#include "Menu.h"
#include "ApplicationContext.h"

Menu *InitializeMenu()
{
    Menu *mainMenu = MenuConstructor("HTable menu");

    Menu *hashTableMenu = MenuConstructor("Interaction");
    Menu *hashTableMenuStats = MenuConstructor("Stats");

    Menu *addHashTableItem = MenuConstructor("Add");
    Menu *deleteHashTableItem = MenuConstructor("Delete");

    MenuAddChildren(mainMenu, hashTableMenu);
    MenuAddChildren(mainMenu, hashTableMenuStats);

    MenuAddChildren(hashTableMenu, addHashTableItem);
    MenuAddChildren(hashTableMenu, deleteHashTableItem);

    return mainMenu;
}

int main(int argc, char **argv)
{
    HashTable *hashTable = HashTableConstructor(20);
    ApplicationContext *appContext = AppContextConstructor();

    AppContextSetHTable(appContext, hashTable);

    /* printf("Input:\n");
    for (int i = 0; i < 20; i++)
    {
        String *str = ReadString();
        HashTableAdd(hashTable, str);
        StringFree(str);
    }

    printf("\nOutput:\n");
    for (int i = 0; i < GetHashTableCount(hashTable); i++)
    {
        WriteHashTableNode(HashTableNode(hashTable, i));
    }
    printf("\nMax collision: %d\n", GetMaxCountCollisions(hashTable));

    WriteEachNodeCollision(hashTable);*/


    Menu *menu = InitializeMenu();

    MenuProcess(menu, appContext);

    HashTableFree(hashTable);
    MenuFree(menu);

    system("pause");
    return SUCCESSFUL_CODE;
}