#include "MenuManager.h"

void MenuManager::start() {
    InitialMenu initialMenu;
    Menu::MenuState state = initialMenu.show();
    
    while (state != Menu::EXIT) {
        if (state == Menu::TO_MAIN_MENU) {
            MainMenu mainMenu;
            state = mainMenu.show();
        } else if (state == Menu::BACK_TO_INITIAL_MENU) {
            state = initialMenu.show();
        }
    }

    std::cout << "Application exited.\n";

}