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