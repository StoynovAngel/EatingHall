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
    double discount;
public:
    User() = default;
    User(const std::string& username);
    User(const std::string& username, double balance, const std::vector<Grade>& grades, double discount);
    std::string getUsername() const;
    double getBalance() const;
    double getDiscount() const;
    const std::vector<Grade>& getGrades() const;
    void addGrade(const Grade& grade);
    void setUsername(std::string username);
    void setBalance(double balance);
    void setDiscount(double discount);
    double getAverageGrade() const;
    friend std::ostream& operator<<(std::ostream& os, const User& user);

};

#endif