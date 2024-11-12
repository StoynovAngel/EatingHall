#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "SystemManager.h"
#include "GroupManager.h"

class Menu{
    public:
        SystemManager systemManager;
        GroupManager groupManager;
        virtual void displayOptions() = 0;
        virtual void handleChoice(int choice) = 0;
        virtual bool isConditionMet() const { return false; }

        void show() {
            int choice;
            do
            {
                displayOptions();
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                handleChoice(choice);

                if (isConditionMet()) {
                    break;
                }
                
            } while (choice != 0);
        }
};

#endif