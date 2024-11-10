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
        static std::vector<Group> readFromFile(const std::string& filename) {
            std::ifstream myFile(filename);
            if (!myFile.is_open()) {
                std::cerr << "Error: Unable to open file " << filename << std::endl;
                return {}; 
            }

            std::vector<Group> groups;
            std::string line;
            std::string groupName;
            double groupDiscount = 0.0;
            double groupSurcharge = 0.0;

            while (std::getline(myFile, line)) {
                if (line.find("Group Name:") != std::string::npos) {
                    groupName = line.substr(line.find(":") + 2);
                } else if (line.find("Discount:") != std::string::npos) {
                    groupDiscount = std::stod(line.substr(line.find(":") + 2));
                } else if (line.find("Surcharge:") != std::string::npos) {
                    groupSurcharge = std::stod(line.substr(line.find(":") + 2));
                } else if (line.find("Users:") != std::string::npos) {
                    std::vector<User> users;
                    
                    while (std::getline(myFile, line) && line.find("Username:") != std::string::npos) {
                        std::string username = line.substr(line.find(":") + 2);
                        double userDiscount = 0.0;
                        std::vector<Grade> grades;

                        std::getline(myFile, line); 
                        if (line.find("Discount:") != std::string::npos) {
                            userDiscount = std::stod(line.substr(line.find(":") + 2));
                        }

                        std::getline(myFile, line);
                        while (std::getline(myFile, line) && line.find("Subject:") != std::string::npos) {
                            std::string subject = line.substr(line.find("Subject:") + 9, line.find(",") - line.find("Subject:") - 9);
                            double grade = std::stod(line.substr(line.find("Grade:") + 7));
                            grades.push_back(Grade(subject, grade));
                        }

                        User user(username, grades, userDiscount);
                        users.push_back(user);
                    }

                    Group group(groupName, groupDiscount, groupSurcharge);
                    for (const auto& user : users) {
                        group.addUser(user);
                    }
                    groups.push_back(group);
                }
            }

            myFile.close();
            return groups;
        }
};
#endif
