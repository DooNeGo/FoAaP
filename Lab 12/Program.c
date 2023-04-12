#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"
#include "Menu.h"
#include "ApplicationContext.h"
#include "String.h"
#include "ConsoleReader.h"
#include "ConsoleWriter.h"

Menu *InitializeMenu()
{
    Menu *mainMenu = MenuConstructor("HTable menu");

    Menu *hashTableMenu = MenuConstructor("Interaction");
    Menu *hashTableMenuStats = MenuConstructor("Stats");

    Menu *addHashTableItem = MenuConstructor("Add");
    Menu *deleteHashTableItem = MenuConstructor("Delete");
    Menu *showHTable = MenuConstructor("Show");
    Menu *checkHTableValue = MenuConstructor("Check");

    MenuAddChildren(mainMenu, hashTableMenu);
    MenuAddChildren(mainMenu, hashTableMenuStats);

    MenuAddChildren(hashTableMenu, showHTable);
    MenuAddChildren(hashTableMenu, addHashTableItem);
    MenuAddChildren(hashTableMenu, deleteHashTableItem);
    MenuAddChildren(hashTableMenu, checkHTableValue);

    return mainMenu;
}

int main(int argc, char const *argv[])
{
    HashTable *hashTable = HashTableConstructor(6);
    ApplicationContext *appContext = AppContextConstructor();
    Menu *menu = InitializeMenu();

    AppContextSetHTable(appContext, hashTable);
    MenuProcess(menu, appContext);

    HashTableFree(hashTable);
    MenuFree(menu);
    free(appContext);

    system("pause");
    return SUCCESSFUL_CODE;
}