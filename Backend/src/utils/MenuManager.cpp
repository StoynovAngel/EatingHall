#include "MenuManager.h"

void MenuManager::showMenu() {
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Group\n";
        if(!groupsLoaded){
            std::cout << "2. Load specific File\n";
            std::cout << "3. Load all files\n";
        }
        if(groupsLoaded){
            std::cout << "4. Add User to Group\n";
            std::cout << "5. Get specific user\n";
            std::cout << "6. Get specific group\n";
        }
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: 
                systemManager.addGroupMenu(groupManager);
                break;
            case 2: 
                systemManager.loadGroupFromFile(groupManager);
                groupsLoaded = true; 
                break;
            case 3: 
                systemManager.loadAllFiles(groupManager);
                groupsLoaded = true; 
                break;
            case 4:
                if (groupsLoaded) {
                    systemManager.addUserToGroupMenu(groupManager);
                } else {
                    std::cout << "This option is not available until you load groups.\n";
                }
                break;
            case 5:
                if (groupsLoaded) {
                    systemManager.getUserFromGroupMenu(groupManager);
                } else {
                    std::cout << "This option is not available until you load groups.\n";
                }
                break;
            case 6:
                if (groupsLoaded) {
                    systemManager.viewGroupMenu(groupManager);
                } else {
                    std::cout << "This option is not available until you load groups.\n";
                }
                break;
            case 0: 
                std::cout << "Exiting...\n";
                break;
            default: 
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);
}