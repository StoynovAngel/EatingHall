#include "User.h"
#include "UserValidation.h"
#include "Grade.h"

#include <iostream>
#include <vector>

User::User(const std::string& username) {
    if (!UserValidation::isValidUsername(username)) {
        throw std::invalid_argument("Invalid username provided.");
    }
    this->username = username;
    this->balance = 0;
}

User::User(const std::string& username, double balance, const std::vector<Grade>& grades){
    if(!UserValidation::isValidUsername(username) || !UserValidation::balanceCheck(balance)){
        throw std::invalid_argument("Invalid username or balance");
    }
    this->username = username;
    this->balance = balance;
    this->grades = grades;
}

std::string User::getUsername() const {
    return username;
}

double User::getBalance() const {
    return balance;
}

const std::vector<Grade>& User::getGrades() const {
    return grades;
}

void User::addGrade(const Grade& grade){
    grades.push_back(grade);
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "Username: " << user.getUsername() << "\nBalance: " << user.getBalance() << "\nGrades:\n";
    for (const auto& grade : user.getGrades()) {
        os << "   - " << grade << "\n"; 
    }
    return os;
}