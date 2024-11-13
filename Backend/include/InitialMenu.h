#ifndef INITIALMENU_H
#define INITIALMENU_H

#include  "Menu.h"

class InitialMenu : public Menu {
    private:
        bool proceedToMainMenu = false;

    public:
        void displayOptions() override {
            std::cout << "\nInitial Menu:\n";
            std::cout << "1. Add Group\n";
            std::cout << "2. Load specific File\n";
            std::cout << "3. Load all files\n";
            std::cout << "0. Exit\n";
            std::cout << "Enter your choice: ";
        }

        void handleChoice(int choice) override {
            switch (choice) {
                case 1: systemManager.addGroupMenu(groupManager); break;
                case 2: {
                    systemManager.loadGroupFromFile(groupManager); 
                    proceedToMainMenu = true; 
                    break;
                }
                case 3: {
                    systemManager.loadAllFiles(groupManager); 
                    proceedToMainMenu = true;
                    break;
                }
                case 0: {
                    std::cout << "Exiting...\n";
                    proceedToMainMenu = false;
                    break;
                } 
                default: std::cout << "Invalid choice. Try again.\n"; break;
            }
        }
        MenuState updateCondition() override {
            if (proceedToMainMenu) {
                return TO_MAIN_MENU;
            } else if (!proceedToMainMenu) {
                return EXIT;
            }
            return CONTINUE;
        }  
};

#endif