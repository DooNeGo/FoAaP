#include "HashTable.h"
#include "Menu.h"

Menu *InitializeMenu()
{
    Menu *mainMenu = MenuConstructor("HTable menu");

    Menu *hashTableMenu = MenuConstructor("Interaction");
    Menu *hashTableMenuStats = MenuConstructor2("Stats", MenuStats);

    Menu *addHashTableItem = MenuConstructor2("Add", MenuAdd);
    Menu *deleteHashTableItem = MenuConstructor2("Delete", MenuDelete);
    Menu *showHTable = MenuConstructor2("Show", MenuShow);
    Menu *checkHTableValue = MenuConstructor2("Check", MenuCheck);

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