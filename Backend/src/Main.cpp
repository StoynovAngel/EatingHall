#include <iostream>
#include "User.h"
#include "Group.h"
#include "Grade.h"
#include "Menu.h"

int main()
{
     try {
        std::vector<Grade> grades = {Grade("Math", 90.0), Grade("Science", 85.0)};
        User user1("Alice", 50.0, grades);

        std::string groupName = "Students";
        Group group(groupName);
        group.addUser(user1);

        std::cout << group << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }

    Menu::showMenu();

    return 0;
}
