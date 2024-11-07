#include "GroupManager.h"
#include "Group.h"

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