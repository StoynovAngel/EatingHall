#include "GroupManager.h"
#include "Group.h"
#include "Validation.h"
#include "FileReader.h"

namespace fs = std::filesystem;

bool GroupManager::addGroup(const Group& group) {
    std::cout << "Trying to add group with name: " << group.getGroupName() << "\n";
    
    if (groups.find(group.getGroupName()) != groups.end()) {
        std::cout << "Group already exists in the map.\n";
        std::cout << "Group with name '" << group.getGroupName() << "' already exists.\n";
        return false;
    }

    auto result = groups.emplace(group.getGroupName(), group);
    if (!result.second) {
        std::cout << "Failed to add group with name '" << group.getGroupName() << "'.\n";
        return false;
    }
    std::cout << "Group added successfully.\n";
    return true;
}

Group* GroupManager::getGroupByName(const std::string& name) {
    auto it = groups.find(name);
    if (it != groups.end()) {
        return &it->second;
    }
    return nullptr;
}

Group* GroupManager::groupByNameHelper() {
    std::string groupName;

    std::cout << "Enter group name: ";
    std::cin >> groupName;
    Group* group = getGroupByName(groupName);

    if (!group) {
        std::cout << "No such group.\n";
        return nullptr; 
    }
    return group;
}


void GroupManager::userHandler(Group* group) {
    while (true) {
        std::string username;
        double userDiscount;
        std::vector<Grade> grades;

        std::cout << "Enter username (or type 'done' to finish): ";
        std::cin >> username;
        if (username == "done") break;

        if (!Validation::isAlpha(username)) {
            std::cerr << "Invalid username. User could not be added.\n";
            return;
        }

        if (group->getGroupName() != "out"){
            gradeHandler(grades);
        }
        
        User user(username, grades, 0.0); 
        user.updateDiscount();
        group->addUser(user);
        std::cout << "User added successfully to the group.\n";

    }
}

Group* GroupManager::searchGroup() {
    std::string groupName;
    std::cout << "Enter group name: ";
    std::cin >> groupName;

    if (groups.find(groupName) != groups.end()) {
        return &groups[groupName];
    }
    std::string filePath = "files/" + groupName + ".txt";
    if (fs::exists(filePath)) {

        std::vector<Group> loadedGroups = FileReader::readFromFile(filePath);
        if (!loadedGroups.empty()) {
            Group group = loadedGroups[0];
            groups[groupName] = group;
            return &groups[groupName];
        } else {
            std::cout << "Error: File " << filePath << " is empty or does not contain valid groups.\n";
            return nullptr;
        }
    }

    std::cout << "Group '" << groupName << "' not found." << std::endl;
    return nullptr;
}
void GroupManager::gradeHandler(std::vector<Grade>& grades) {
    std::string subjectInput;
    double mark;

    std::cout << "(type 'done' when finished): \n";
    while (true) {
        std::cout << "Enter subject: ";
        std::cin >> subjectInput;
        if (subjectInput == "done") break;

        std::cout << "Enter mark: ";
        std::cin >> mark;

        if (!Validation::validMark(mark)) { 
            std::cerr << "Invalid mark. Must be between 2 and 6.\n";
            continue;
        }

        grades.push_back(Grade(subjectInput, mark));
    }
}