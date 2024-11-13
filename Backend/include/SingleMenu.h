#ifndef SINGLEMENU_H
#define SINGLEMENU_H

#include  "Menu.h"

class SingleMenu : public Menu {
    private:
        int choice;
    public:
        SingleMenu(SystemManager& systemManager, GroupManager& groupManager) : Menu(systemManager, groupManager) {}
        void displayOptions() override {
            std::cout << "\nSingle Menu:\n";
            std::cout << "1. Add User to the Group\n";
            std::cout << "2. Display user\n";
            std::cout << "3. Display group\n";
            std::cout << "4. Go back to initial menu\n";
            std::cout << "0. Exit\n";
            std::cout << "Enter your choice: ";
        }

        void handleChoice(int choice) override {
            this->choice = choice;
            switch (choice) {
                case 1: systemManager.addUserToSingleMenu(groupManager); break;
                case 2: systemManager.getUserFromSingleMenu(groupManager); break;
                case 3: systemManager.viewSingleMenu(groupManager); break;
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