#include <iostream>
#include "User.h"
#include "Group.h"
#include "Grade.h"
#include "Menu.h"
#include "FileWriter.h"
#include "GroupManager.h"

int main() {
    try {
        std::vector<Grade> grades1 = { Grade("Math", 90.0), Grade("Science", 85.0) };
        User user1("Alice", 50.0, grades1);

        std::vector<Grade> grades2 = { Grade("BG", 90.0), Grade("PHYSICS", 85.0) };
        User user2("Angel", 50.0, grades2);

        Group group("Students");
        group.addUser(user1);
        group.addUser(user2);

        GroupManager manager;
        if (manager.addGroup(group)) {
            std::cout << "Group added successfully." << std::endl;
        } else {
            std::cout << "Failed to add group (duplicate group name)." << std::endl;
        }
        std::cout << group << std::endl;
        FileWriter::writeToGroup(group);

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }
    Menu::showMenu();

    return 0;
}
