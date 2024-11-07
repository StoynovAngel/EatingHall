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
    std::cout << "Enter surcharge: ";
    std::cin >> surcharge;

    Group group(groupName, discount, surcharge);
    if (!groupManager.addGroup(group)) {
        std::cout << "Group could not be added.\n";
    }
}

void SystemManager::addUserToGroupMenu() {
    std::string groupName, username;
    double balance;
    std::vector<Grade> grades;
    std::string gradeInput;
    std::string subjectInput;
    double mark;

    std::cout << "Enter group name to add user: ";
    std::cin >> groupName;
    Group* group = groupManager.getGroupByName(groupName);
    if (group) {
        std::cout << "Enter username: ";
        std::cin >> username;

        if (!UserValidation::isValidUsername(username)) {
            std::cerr << "Invalid username. User could not be added.\n";
            return;
        }

        std::cout << "Enter balance: ";
        std::cin >> balance;

        if (!UserValidation::balanceCheck(balance)) {
            std::cerr << "Invalid balance. User could not be added.\n";
            return;
        }

        std::cout << "(type 'done' when finished): \n";
        while (true) {
            std::cout << "Enter subject: ";
            std::cin >> subjectInput;
            if (subjectInput == "done") break;

            std::cout << "Enter mark: ";
            std::cin >> gradeInput;

            try {
                mark = std::stod(gradeInput);
                grades.push_back(Grade(subjectInput, mark));
            } catch (...) {
                std::cerr << "Invalid grade. Please enter a valid number or 'done'.\n";
            }
        }

        User user(username, balance, grades);
        group->addUser(user);
        std::cout << "User added successfully to the group.\n";
    } else {
        std::cout << "Group not found.\n";
    }
}


void SystemManager::showMenu() {
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Group\n";
        std::cout << "2. Add User to Group\n";
        std::cout << "3. Display Groups\n";
        std::cout << "4. Save to File\n";
        std::cout << "5. Load from File\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addGroupMenu(); break;
            case 2: addUserToGroupMenu(); break;
            case 3: groupManager.displayAllGroups(); break;
            case 4: FileWriter::writeToGroup(groupManager); break;
            case 5: FileReader::readFromGroup(); break;
            case 0: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice. Try again.\n"; break;
        }
    } while (choice != 0);
}
