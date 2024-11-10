#include "User.h"
#include "Validation.h"
#include "Grade.h"

#include <iostream>
#include <vector>

User::User(const std::string& username) {
    if (!Validation::isAlpha(username)) {
        throw std::invalid_argument("Invalid username provided.");
    }
    this->username = username;
}

User::User(const std::string& username, const std::vector<Grade>& grades, double discount){
    if(!Validation::isAlpha(username)){
        throw std::invalid_argument("Invalid username");
    }
    if(!Validation::isNotNegative({discount})){
        throw std::invalid_argument("Discount should be >= 0.");
    }
    this->username = username;
    this->grades = grades;
    this->discount = discount;
}

std::string User::getUsername() const {
    return username;
}

void User::setUsername(std::string username){
    this->username = username;
}

const std::vector<Grade>& User::getGrades() const {
    return grades;
}

double User::getDiscount() const{
    return discount;
}
void User::setDiscount(double discount){
    this->discount = discount;
}

void User::addGrade(const Grade& grade){
    grades.push_back(grade);
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

void User::updateDiscount() {
    double avgGrade = getAverageGrade();
    discount = (avgGrade >= 4.0) ? 5.0 : 0.0;
}


std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "Username: " << user.getUsername() << "\n    Discount: " << user.getDiscount() << "\n    Grades:\n";
    for (const auto& grade : user.getGrades()) {
        os << "    " << grade << "\n"; 
    }
    return os;
}