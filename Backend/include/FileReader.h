#ifndef FILEREADER_H
#define FILEREADER_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Validation.h"
#include "Group.h"
#include "User.h"

class FileReader{
    public:
        static void readFromFile(std::string filename) {
            std::ifstream myFile(filename + ".txt");
            if (!myFile.is_open()) {
                std::cerr << "Error: Unable to open file " << filename << std::endl;
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
