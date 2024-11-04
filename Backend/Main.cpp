#include <iostream>
#include "User.h"

int main()
{
    try {

        User user("JohnDoe");
        std::cout << "Username: " << user.getUsername() << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name; 
    std::cout << "Hello, " << name << "!" << std::endl;

    return 0;
}
