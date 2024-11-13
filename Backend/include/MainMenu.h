#ifndef MAINMENU_H
#define MAINMENU_H

#include  "Menu.h"

class MainMenu : public Menu {
    private:
        int choice;
    public:
        void displayOptions() override {
            std::cout << "\nMain Menu:\n";
            std::cout << "1. Add Group\n";
            std::cout << "2. Add User to Group\n";
            std::cout << "3. Get specific user\n";
            std::cout << "4. Get specific group\n";
            std::cout << "5. Go back to initial menu\n";
            std::cout << "0. Exit\n";
            std::cout << "Enter your choice: ";
        }

        void handleChoice(int choice) override {
            this->choice = choice;
            switch (choice) {
                case 1: systemManager.addGroupMenu(groupManager); break;
                case 2: systemManager.addUserToGroupMenu(groupManager); break;
                case 3: systemManager.getUserFromGroupMenu(groupManager); break;
                case 4: systemManager.viewGroupMenu(groupManager); break;
                case 5: std::cout << "Going back...\n"; break;
                case 0: std::cout << "Exiting...\n"; break;
                default: std::cout << "Invalid choice. Try again.\n"; break;
            }
        }
        MenuState updateCondition() override {
            return choice == 5 ? BACK_TO_INITIAL_MENU : choice == 0 ? EXIT : CONTINUE;
        }  
};

#endif