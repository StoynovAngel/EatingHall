#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <ostream>
#include "Grade.h" 

class User{
private:
    std::string username;
    double balance;
    std::vector<Grade> grades;
public:
    User(const std::string& username);
    User(const std::string& username, double balance, const std::vector<Grade>& grades);
    std::string getUsername() const;
    double getBalance() const;
    const std::vector<Grade>& getGrades() const;
    void addGrade(const Grade& grade);
    friend std::ostream& operator<<(std::ostream& os, const User& user);

};

#endif