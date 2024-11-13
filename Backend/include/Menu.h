#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "SystemManager.h"
#include "GroupManager.h"

class Menu{
    protected:
        SystemManager& systemManager;
        GroupManager& groupManager;
    public:
        Menu(SystemManager& sysManager, GroupManager& grpManager) : systemManager(sysManager), groupManager(grpManager) {}

        enum MenuState {
            EXIT,
            TO_MAIN_MENU,
            TO_SINGLE_MENU,
            BACK_TO_INITIAL_MENU,
            CONTINUE
        };

        virtual void displayOptions() = 0;
        virtual void handleChoice(int choice) = 0;
        virtual MenuState updateCondition() = 0;

        MenuState show() {
            int choice;
            do
            {
                displayOptions();
                std::cin >> choice;
                handleChoice(choice);

                MenuState state = updateCondition();

                if (state != CONTINUE) {
                    return state;
                }
                
            } while (choice != 0);
            return EXIT;
        }
};

#endif