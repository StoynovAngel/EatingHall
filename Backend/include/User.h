#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <ostream>
#include "Grade.h" 

class User{
private:
    std::string username;
    std::vector<Grade> grades;
    double discount = 0.0;
public:
    User() = default;
    User(const std::string& username);
    User(const std::string& username, const std::vector<Grade>& grades, double discount);
    std::string getUsername() const;
    double getDiscount() const;
    const std::vector<Grade>& getGrades() const;
    void addGrade(const Grade& grade);
    void setUsername(std::string username);
    void setDiscount(double discount);
    double getAverageGrade() const;
    void updateDiscount(); 
    friend std::ostream& operator<<(std::ostream& os, const User& user);

};

#endif