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

User::User(const std::string& username, double balance, const std::vector<Grade>& grades, double discount){
    if(!UserValidation::isValidUsername(username) || !UserValidation::balanceCheck(balance)){
        throw std::invalid_argument("Invalid username or balance");
    }
    this->username = username;
    this->balance = balance;
    this->grades = grades;
    this->discount = discount;
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

double User::getDiscount() const{
    return discount;
}

void User::addGrade(const Grade& grade){
    grades.push_back(grade);
}

void User::setUsername(std::string username){
    this->username = username;
}

void User::setBalance(double balance){
    this->balance = balance;
}

void User::setDiscount(double discount){
    this->discount = discount;
}

double User::getAverageGrade() const {
    if(grades.empty()){
        return 0.0;
    }
    double sum = 0.0;
    for(const auto& grade: grades){
        sum += grade.getMark();
    }
    return sum / grades.size();
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "Username: " << user.getUsername() << "\n    Balance: " << user.getBalance() << "\n    Discount: " << user.getDiscount() << "\n    Grades:\n";
    for (const auto& grade : user.getGrades()) {
        os << "    " << grade << "\n"; 
    }
    return os;
}