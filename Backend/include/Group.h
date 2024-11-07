#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include "User.h"

class Group{
private:
    std::string groupName;
    std::vector<User> users;
    double discount;
    double discharge;
public:
    Group(const std::string&  groupName, const double discount, const double discharge);
    std::string getGroupName() const;
    double getDiscount() const;
    double getDischarge() const;
    const std::vector<User>& getUsers() const; 

    void addUser(const User& user);  
    void setDiscount(double discount);
    void setDischarge(double discharge);
    User* findUser(const std::string& username);

    friend std::ostream& operator<<(std::ostream& os, const Group& group);
};

#endif