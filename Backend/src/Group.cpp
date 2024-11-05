#include "Group.h"
#include "Validation.h"
#include <stdexcept>

Group::Group(const std::string&  groupName) {
    if (!Validation::isAlphanumeric(groupName)) {
        throw std::invalid_argument("Invalid group name.");
    }
    this->groupName = groupName;
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

std::ostream& operator<<(std::ostream& os, const Group& group) {
    os << "Group Name: " << group.getGroupName() << "\nUsers:\n";
    for (const auto& user : group.users) {
        os << " - " << user.getUsername() << " - " << user.getBalance() << std::endl;
    }
    return os;
}
