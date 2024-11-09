#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <string>
#include <iostream>
#include <fstream>
#include "Validation.h"
#include "Group.h"
#include <string>

class FileWriter{
    public:
        static void writeToFile(const GroupManager& groupManager, std::string filename) {
            std::ofstream myFile(filename + ".txt"); 
            if (!myFile.is_open()) {
                std::cerr << "Error: Unable to open file " << filename  << std::endl;
                return;
            }
            groupManager.displayAllGroups(myFile);
            std::cout << "Groups saved to " << filename  << std::endl; 
        }
};

#endif