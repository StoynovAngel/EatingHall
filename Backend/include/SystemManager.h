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
private:
    std::string lastLoadedGroupName;
public:
    void addGroupMenu(GroupManager& groupManager);
    void addUserToSingleMenu(GroupManager& groupManager);
    void addUserToMainMenu(GroupManager& groupManager);
    void getUserFromMainMenu(GroupManager& groupManager);
    void getUserFromSingleMenu(GroupManager& groupManager);
    void viewGroupMenu(GroupManager& groupManager);
    void viewSingleMenu(GroupManager& groupManager);
    void loadGroupFromFile(GroupManager& groupManager);
    void saveGroupToFile(const Group& group); 
    void loadAllFiles(GroupManager& groupManager);

    std::string getLastLoadedGroupName();
};

#endif