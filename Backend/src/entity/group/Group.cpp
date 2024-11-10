#include "Group.h"
#include "Validation.h"
#include "User.h"
#include <stdexcept>

Group::Group(const std::string&  groupName, double discount, double surcharge) {
    if (!Validation::isAlphanumeric(groupName) || !Validation::isNotNegative(discount)) {
        throw std::invalid_argument("Invalid group name.");
    }
    this->groupName = groupName;
    this->discount = discount;
    this->surcharge = surcharge;
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

double Group::getDiscount() const{
    return discount;
}

void Group::setDiscount(double discount) {
    this->discount = discount;
}

double Group::getSurcharge() const{
    return surcharge;
}

void Group::setSurcharge(double surcharge){
    this->surcharge = surcharge;
}

void Group::setGroupName(std::string groupName){
    this->groupName = groupName;
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
    os << "    Discount: " << group.discount << "\n";
    os << "    Surcharge: " << group.surcharge << "\n";
    os << "Users:" << "\n"; 
    for (const auto& user : group.getUsers()) {
        os << "    " << user << "\n"; 
    }
    return os;
}