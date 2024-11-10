#include "MenuManager.h"

void MenuManager::showMenu() {
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Group\n";
        std::cout << "2. Add User to Group\n";
        std::cout << "3. Display unsaved Groups\n";
        std::cout << "4. Save to File\n";
        std::cout << "5. Load from File\n";
        std::cout << "6. Get specific user\n";
        std::cout << "7. Get specific group\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: systemManager.addGroupMenu(groupManager); break;
            case 2: systemManager.addUserToGroupMenu(groupManager); break;
            case 3: groupManager.displayAllGroups(); break;
            case 4: FileWriter::writeToFile(groupManager, groupManager.searchGroup()); break;
            case 5: FileReader::readFromFile(groupManager.searchGroup()); break;
            case 6: systemManager.getUserFromGroupMenu(groupManager); break;
            case 7: systemManager.viewGroupMenu(groupManager); break;
            case 0: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice. Try again.\n"; break;
        }
    } while (choice != 0);
}