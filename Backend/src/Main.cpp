#include <iostream>
#include "User.h"
#include "Group.h"
#include "Menu.h"

int main()
{
     try {

        User user1("Alice", 50.0);
        User user2("Bob", 75.5);
        User user3("Charlie", 120.0);

        std::string groupName = "Students";
        Group group(groupName);
        group.addUser(user1);
        group.addUser(user2);
        group.addUser(user3);
        std::cout << group;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }

    std:: cout << "Enter your choice (1-3): " << std::endl;
    Menu::showMenu();

    return 0;
}
