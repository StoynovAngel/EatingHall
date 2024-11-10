#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <vector>
#include <string>
#include "Group.h"
#include "GroupManager.h"
#include "User.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "SystemManager.h"
#include "GroupManager.h"

class MenuManager{
    private:
        SystemManager systemManager;
        GroupManager groupManager;
    public:
        void showMenu();
};

#endif