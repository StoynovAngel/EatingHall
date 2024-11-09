#include "SystemManager.h"
#include <iostream>
#include <fstream>

void SystemManager::addGroupMenu() {
    std::string groupName;
    double discount, surcharge;
    std::cout << "Enter group name: ";
    std::cin >> groupName;
    std::cout << "Enter discount: ";
    std::cin >> discount;

    if(discount <= 0){
        std::cout << "Enter surcharge: ";
        std::cin >> surcharge;
    }else{
        surcharge = 0;
    }

    Group group(groupName, discount, surcharge);
    if (!groupManager.addGroup(group)) {
        std::cout << "Group could not be added.\n";
    }
}

void SystemManager::addUserToGroupMenu() {
    std::string groupName;

    std::cout << "Enter group name to add user: ";
    std::cin >> groupName;
    Group* group = groupManager.getGroupByName(groupName);

    if (!group) {
        std::cout << "No such group" << "\n";
        return;
    }
    groupManager.userHandler(group);
}

void SystemManager::getUserFromGroupMenu() {
    std::string groupName, username;

    Group* group = groupManager.groupByNameHelper();
    if (!group) return;

    std::cout << "Enter username to search: ";
    std::cin >> username;

    User* user = group->findUser(username);
    if (user) {
        std::cout << *user;
    } else {
        std::cout << "User not found in the group.\n";
    }
}

void SystemManager::viewGroupMenu() {
    Group* group = groupManager.groupByNameHelper();
    if (!group) return;
    std::cout << *group;
}


void SystemManager::showMenu() {
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
            case 1: addGroupMenu(); break;
            case 2: addUserToGroupMenu(); break;
            case 3: groupManager.displayAllGroups(); break;
            case 4: FileWriter::writeToFile(groupManager, groupManager.searchGroup()); break;
            case 5: FileReader::readFromFile(groupManager.searchGroup()); break;
            case 6: getUserFromGroupMenu(); break;
            case 7: viewGroupMenu(); break;
            case 0: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice. Try again.\n"; break;
        }
    } while (choice != 0);
}
