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
    double surcharge;
public:
    Group() = default;
    Group(const std::string&  groupName, double discount, double surcharge);
    std::string getGroupName() const;
    double getDiscount() const;
    double getSurcharge() const;
    const std::vector<User>& getUsers() const; 

    void addUser(const User& user);  
    void setDiscount(double discount);
    void setSurcharge(double surcharge);
    void setGroupName(std::string groupName);
    User* findUser(const std::string& username);

    friend std::ostream& operator<<(std::ostream& os, const Group& group);
};

#endif