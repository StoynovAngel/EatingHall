#ifndef MAINMENU_H
#define MAINMENU_H

#include  "Menu.h"

class MainMenu : public Menu {
    private:
        int choice;
    public:
        MainMenu(SystemManager& systemManager, GroupManager& groupManager) : Menu(systemManager, groupManager) {}
        void displayOptions() override {
            std::cout << "\nMain Menu:\n";
            std::cout << "1. Add User to Group\n";
            std::cout << "2. Get specific user\n";
            std::cout << "3. Get specific group\n";
            std::cout << "4. Go back to initial menu\n";
            std::cout << "0. Exit\n";
            std::cout << "Enter your choice: ";
        }

        void handleChoice(int choice) override {
            this->choice = choice;
            switch (choice) {
                case 1: systemManager.addUserToMainMenu(groupManager); break;
                case 2: systemManager.getUserFromMainMenu(groupManager); break;
                case 3: systemManager.viewGroupMenu(groupManager); break;
                case 4: std::cout << "Going back...\n"; break;
                case 0: std::cout << "Exiting...\n"; break;
                default: std::cout << "Invalid choice. Try again.\n"; break;
            }
        }
        MenuState updateCondition() override {
            return choice == 4 ? BACK_TO_INITIAL_MENU : choice == 0 ? EXIT : CONTINUE;
        }  
};

#endif