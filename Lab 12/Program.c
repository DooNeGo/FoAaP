#include "HashTable.h"
#include "Menu.h"

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

int main()
{
    HashTable *hashTable = HashTableConstructor(6);
    ApplicationContext *appContext = AppContextConstructor(hashTable);
    Menu *menu = InitializeMenu();

    MenuProcess(menu, appContext);

    HashTableFree(hashTable);
    MenuFree(menu);
    AppContextFree(appContext);

    return SUCCESSFUL_CODE;
}