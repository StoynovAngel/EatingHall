#include <iostream>
#include "User.h"
#include <Menu.h>

int main()
{
    try {

        User user("Ivan");
        std::cout << "Username: " << user.getUsername() << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    int choice;
    std:: cout << "Enter your choice (1-3): ";
    std:: cin >> choice;

    Menu::showMenu(choice);

    return 0;
}
