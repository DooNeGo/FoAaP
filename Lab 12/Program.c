#include "HashTable.h"
#include "Menu.h"

Menu *InitializeMenu()
{
    Menu *mainMenu = MenuConstructor("HTable menu");

    Menu *hashTableMenu = MenuConstructor("Interaction");
    Menu *hashTableMenuStats = MenuConstructor2("Stats", MenuStatsAction);

    Menu *addHashTableItem = MenuConstructor2("Add", MenuAddAction);
    Menu *deleteHashTableItem = MenuConstructor2("Delete", MenuDeleteAction);
    Menu *showHTable = MenuConstructor2("Show", MenuShowAction);
    Menu *checkHTableValue = MenuConstructor2("Check", MenuCheckAction);

    MenuAddChild(mainMenu, hashTableMenu);
    MenuAddChild(mainMenu, hashTableMenuStats);

    MenuAddChild(hashTableMenu, showHTable);
    MenuAddChild(hashTableMenu, addHashTableItem);
    MenuAddChild(hashTableMenu, deleteHashTableItem);
    MenuAddChild(hashTableMenu, checkHTableValue);

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