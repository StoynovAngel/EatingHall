#ifndef FILEREADER_H
#define FILEREADER_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Validation.h"
#include "Group.h"

class FileReader{
    public:
        static void readFromGroup() {
            std::ifstream myFile("groups.txt");
            if (!myFile.is_open()) {
                std::cerr << "Error: Unable to open file 'groups.txt'" << std::endl;
                return;
            }

            std::string line;
            while (getline(myFile, line)) {
                std::cout << line << '\n';
            }

            myFile.close();
        }
};

#endif