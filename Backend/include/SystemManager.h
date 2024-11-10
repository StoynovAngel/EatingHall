#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <vector>
#include <string>
#include "Group.h"
#include "GroupManager.h"
#include "User.h"
#include "FileReader.h"
#include "FileWriter.h"

class SystemManager {
public:
    void addGroupMenu(GroupManager& groupManager);
    void addUserToGroupMenu(GroupManager& groupManager);
    void displayGroups(GroupManager& groupManager) const;
    void getUserFromGroupMenu(GroupManager& groupManager);
    void viewGroupMenu(GroupManager& groupManager);
    void loadGroupsFromFile(GroupManager& groupManager);
    void saveGroupToFile(const Group& group); 
};

#endif