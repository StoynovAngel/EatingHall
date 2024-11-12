#include "MenuManager.h"

void MenuManager::start() {
    InitialMenu initialMenu;
    initialMenu.show();
    
    if (initialMenu.isConditionMet()) {
        MainMenu mainMenu;
        mainMenu.show();
    }
}