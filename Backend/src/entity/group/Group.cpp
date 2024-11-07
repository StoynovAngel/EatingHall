#include "Group.h"
#include "Validation.h"
#include "User.h"
#include <stdexcept>

Group::Group(const std::string&  groupName, const double discount, double discharge) {
    if (!Validation::isAlphanumeric(groupName) || !Validation::isNotNegative(discount)) {
        throw std::invalid_argument("Invalid group name.");
    }
    this->groupName = groupName;
    this->discount = discount;
    this->discharge = discharge;
}

std::string Group::getGroupName() const {
    return groupName;
}

const std::vector<User>& Group::getUsers() const {
    return users;
}

void Group::addUser(const User& user) {
    users.push_back(user);
}

void Group::setDiscount(double discount) {
    this->discount = discount;
}

void Group::setDischarge(double discharge){
    this->discharge = discharge;
}

User* Group::findUser(const std::string& username) {
    for(auto& user: users){
        if(user.getUsername() == username){
            return &user;
        }
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Group& group) {
    os << "Group Name: " << group.getGroupName() << "\n";
    os << "--Discount: " << group.discount << "\n";
    os << "--Discharge: " << group.discharge << "\n";
    os << "Users:\n";
    for (const auto& user : group.getUsers()) {
        os << "--" << user << "\n"; 
    }
    return os;
}