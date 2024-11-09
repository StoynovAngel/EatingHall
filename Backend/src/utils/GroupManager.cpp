#include "GroupManager.h"
#include "Group.h"
#include "UserValidation.h"

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
    } else {
        for (const auto& pair : groups) {
            os << pair.second << "\n";
        }
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
        double balance;
        std::vector<Grade> grades;
        std::string gradeInput;
        std::string subjectInput;
        double mark;
        double userDiscount;

        std::cout << "Enter username (or type 'done' to finish): ";
        std::cin >> username;
        if (username == "done") break;

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
        
        User user(username, balance, grades, 0.0);
        double avgGrade = user.getAverageGrade();
        std::cout << "Average Grade: " << avgGrade << std::endl;

        if (avgGrade >= 4.0) {
            user.setDiscount(5.0);
            std::cout << "Discount set to 5%" << std::endl;
        } else {
            user.setDiscount(0.0);
            std::cout << "Discount set to 0%" << std::endl;
        }
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