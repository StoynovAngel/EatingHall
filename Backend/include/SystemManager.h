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
private:
    GroupManager groupManager; 

public:
    void addGroupMenu();
    void addUserToGroupMenu();
    void displayGroups() const;
    void showMenu();
    void getUserFromGroupMenu();
    void viewGroupMenu();
};

#endif