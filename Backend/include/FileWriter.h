#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <string>
#include <iostream>
#include <fstream>
#include "Validation.h"
#include "Group.h"

class FileWriter{
    public:
        static void writeToGroup(const GroupManager& groupManager) {
            std::ofstream myFile("groups.txt"); 
            if (!myFile.is_open()) {
                std::cerr << "Error: Unable to open file 'groups.txt'" << std::endl;
                return;
            }
            groupManager.displayAllGroups(myFile);
            std::cout << "Groups saved to 'groups.txt'.\n";
        }
};

#endif