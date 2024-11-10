#include <iostream>
#include <fstream>
#include "SystemManager.h"

void SystemManager::addGroupMenu(GroupManager& groupManager) {
    std::string groupName;
    double discount, surcharge;
    std::cout << "Enter group name: ";
    std::cin >> groupName;
    std::cout << "Enter discount: ";
    std::cin >> discount;

    if(discount == 0){
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

void SystemManager::addUserToGroupMenu(GroupManager& groupManager) {
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

void SystemManager::getUserFromGroupMenu(GroupManager& groupManager) {
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

void SystemManager::viewGroupMenu(GroupManager& groupManager) {
    Group* group = groupManager.groupByNameHelper();
    if (!group) return;
    std::cout << *group;
}
