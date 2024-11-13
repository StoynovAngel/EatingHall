#include "MenuManager.h"

void MenuManager::start() {
    SystemManager systemManager;
    GroupManager groupManager; 
    InitialMenu initialMenu(systemManager, groupManager);
    Menu::MenuState state = initialMenu.show();
    
    while (state != Menu::EXIT) {
        if (state == Menu::TO_MAIN_MENU) {
            MainMenu mainMenu(systemManager, groupManager);
            state = mainMenu.show();
        }
        else if (state == Menu::TO_SINGLE_MENU){
            SingleMenu singleMenu(systemManager, groupManager);
            state = singleMenu.show();
        }
        else if (state == Menu::BACK_TO_INITIAL_MENU) {
            state = initialMenu.show();
        }
    }

    std::cout << "Application exited.\n";

}