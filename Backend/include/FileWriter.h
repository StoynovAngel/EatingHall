#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <string>
#include <iostream>
#include <fstream>
#include "Group.h"
#include <string>
#include <filesystem> 

class FileWriter{
    public:
        static void writeToFile(const Group& group, const std::string& filepath) {
            std::filesystem::path path(filepath);
            std::filesystem::create_directories(path.parent_path());

            std::ofstream myFile(filepath);
            if (!myFile.is_open()) {
                std::cerr << "Error: Unable to open file " << filepath << std::endl;
                return;
            }

            myFile << group;
            myFile.close();

        }
            
};

#endif