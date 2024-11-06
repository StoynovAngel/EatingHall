#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <string>
#include <iostream>
#include <fstream>
#include "Validation.h"
#include "Group.h"

class FileWriter{
    public:
        static void writeToGroup(const Group& group) {
            std::ofstream myFile("groups.txt", std::ios::app);
            if (myFile.is_open()) {
                myFile << group << std::endl;
            } else {
                std::cerr << "Error: Unable to open file 'groups.txt'" << std::endl;
            }
    }
};

#endif