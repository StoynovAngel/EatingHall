#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <string>
#include <vector>
#include "User.h"

class Group{
private:
    std::string groupName;
    std::vector<User> users;
public:
    Group(const std::string&  groupName);
    std::string getGroupName() const;
    const std::vector<User>& getUsers() const; 
    void addUser(const User& user);  

    friend std::ostream& operator << (std::ostream& os, const Group& group);
};

#endif