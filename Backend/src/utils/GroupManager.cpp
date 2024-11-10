#include "GroupManager.h"
#include "Group.h"
#include "Validation.h"

bool GroupManager::addGroup(const Group& group) {
    auto result = groups.emplace(group.getGroupName(), group);
    if (!result.second) {
        std::cout << "Group with name '" << group.getGroupName() << "' already exists.\n";
        return false;
    }
    return true;
}

Group* GroupManager::getGroupByName(const std::string& name) {
    auto it = groups.find(name);
    if (it != groups.end()) {
        return &it->second;
    }
    return nullptr;
}

void GroupManager::displayAllGroups(std::ostream& os) const {
    if (groups.empty()) {
        os << "No groups to display.\n";
    }
    for (const auto& pair : groups) {
        os << pair.second << "\n";
    }
    
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
        std::vector<Grade> grades;
        std::string gradeInput;
        std::string subjectInput;
        double mark;
        double userDiscount;

        std::cout << "Enter username (or type 'done' to finish): ";
        std::cin >> username;
        if (username == "done") break;

        if (!Validation::isAlpha(username)) {
            std::cerr << "Invalid username. User could not be added.\n";
            return;
        }


        if (group->getGroupName() != "out"){
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

        }
        
        User user(username, grades, 0.0); 
        user.updateDiscount();
        group->addUser(user);
        std::cout << "User added successfully to the group.\n";

    }
}

std::string GroupManager::searchGroup(){
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    return filename;
}