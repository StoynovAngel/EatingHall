#ifndef GROUPMANAGER_H
#define GROUPMANAGER_H
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "Group.h"

class GroupManager{
    private:
        std::unordered_map<std::string, Group> groups;
    public:
        bool addGroup(const Group& group);
        Group* getGroupByName(const std::string& name);
        Group* groupByNameHelper();
        void userHandler(Group* group);
        Group* searchGroup();
        void gradeHandler(std::vector<Grade>& grades);
};

#endif