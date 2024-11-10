#include "SystemManager.h"

namespace fs = std::filesystem;

void SystemManager::addGroupMenu(GroupManager& groupManager) {
    std::string groupName;
    double discount, surcharge;
    std::cout << "Enter group name: ";
    std::cin >> groupName;
    std::cout << "Enter discount: ";
    std::cin >> discount;

    if (discount == 0) {
        std::cout << "Enter surcharge: ";
        std::cin >> surcharge;
    } else {
        surcharge = 0;
    }

    Group group(groupName, discount, surcharge);
    if (!groupManager.addGroup(group)) {
        std::cout << "Group could not be added.\n";
    } else {
        saveGroupToFile(group);
        std::cout << "Group saved to file.\n";
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
    saveGroupToFile(*group);
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

void SystemManager::loadGroupFromFile(GroupManager& groupManager) {
    std::string filename;
    std::cout << "Enter the filename to load groups from (without .txt): ";
    std::cin >> filename;

    std::string filePath = "files/" + filename + ".txt";
    
    std::vector<Group> loadedGroups = FileReader::readFromFile(filePath);
    
    for (const auto& group : loadedGroups) {
        groupManager.addGroup(group);
    }
    
    std::cout << "Groups loaded successfully from " << filePath << "\n";
}

void SystemManager::saveGroupToFile(const Group& group) {
    std::string directory = "files/";
    std::string filepath = directory + group.getGroupName() + ".txt";
    FileWriter::writeToFile(group, filepath);
}

void SystemManager::loadAllFiles(GroupManager& groupManager) {
    std::string directory = "files/";
    try {

        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.is_regular_file() && entry.path().extension() == ".txt") {
                std::string filename = entry.path().filename().string();
                std::cout << "Loading group from file: " << filename << std::endl;
                std::vector<Group> loadedGroups = FileReader::readFromFile(entry.path().string());
                for (const auto& group : loadedGroups) {
                    groupManager.addGroup(group);
                }
            }
        }
        std::cout << "All groups have been loaded successfully from the directory.\n";
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error accessing directory: " << e.what() << std::endl;
    }
}