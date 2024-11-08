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

class FileReader {
public:
    static std::vector<Group> readFromGroup() {
        std::ifstream myFile("groups.txt");
        if (!myFile.is_open()) {
            std::cerr << "Error: Unable to open file 'groups.txt'" << std::endl;
            return {};
        }

        std::vector<Group> groups;
        Group currentGroup;
        User currentUser;
        std::string line;
        bool inGradesSection = false;

        while (getline(myFile, line)) {
            std::istringstream iss(line);

            if (line.find("Group Name:") != std::string::npos) {
                if (!currentGroup.getGroupName().empty()) {
                    groups.push_back(currentGroup);
                    currentGroup = Group(); 
                }
                std::string groupName;
                iss.ignore(11);
                getline(iss, groupName);
                currentGroup.setGroupName(groupName);

            } else if (line.find("--Discount:") != std::string::npos) {
                double discount;
                iss.ignore(12);
                iss >> discount;
                currentGroup.setDiscount(discount);

            } else if (line.find("--Discharge:") != std::string::npos) {
                double discharge;
                iss.ignore(13); 
                iss >> discharge;
                currentGroup.setDischarge(discharge);

            } else if (line.find("--Username:") != std::string::npos) {
                if (!currentUser.getUsername().empty()) {
                    currentGroup.addUser(currentUser);
                    currentUser = User(); 
                }
                std::string username;
                iss.ignore(12);
                getline(iss, username);
                currentUser.setUsername(username);

            } else if (line.find("Balance:") != std::string::npos) {
                double balance;
                iss.ignore(9);
                iss >> balance;
                currentUser.setBalance(balance);

            } else if (line.find("Grades:") != std::string::npos) {
                inGradesSection = true;

            } else if (inGradesSection && line.find(" - Subject:") != std::string::npos) {
                std::string subject, gradeStr;
                double grade;

                iss.ignore(11); 
                getline(iss, subject, ','); 
                iss.ignore(7); 
                iss >> grade;
                
                currentUser.addGrade(Grade(subject, grade));
            }
        }

        if (!currentUser.getUsername().empty()) {
            currentGroup.addUser(currentUser);
        }
        if (!currentGroup.getGroupName().empty()) {
            groups.push_back(currentGroup);
        }

        myFile.close();
        return groups;
    }
};

#endif
