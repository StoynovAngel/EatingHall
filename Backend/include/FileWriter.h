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
        static void writeToFile(const Group& group) {
            std::string filename = group.getGroupName() + ".txt";
            std::ofstream myFile(filename); 
            if (!myFile.is_open()) {
                std::cerr << "Error: Unable to open file " << filename << std::endl;
                return;
            }

            myFile << group;
            myFile.close();
            
        }
};

#endif