#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
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
    void loadGroupFromFile(GroupManager& groupManager);
    void saveGroupToFile(const Group& group); 
    void loadAllFiles(GroupManager& groupManager);
};

#endif