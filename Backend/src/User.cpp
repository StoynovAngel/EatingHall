#include "User.h"
#include "UserValidation.h"
#include <iostream>
#include <string>

User::User(const std::string& username) {
    if (!UserValidation::isValidUsername(username)) {
        throw std::invalid_argument("Invalid username provided.");
    }
    this->username = username;
    this->balance = 0;
}

User::User(const std::string& username, double balance){
    if(!UserValidation::isValidUsername(username) || !UserValidation::balanceCheck(balance)){
        throw std::invalid_argument("Invalid username or balance");
    }
    this->username = username;
    this->balance = balance;
}

std::string User::getUsername() const {
    return username;
}

double User::getBalance() const {
    return balance;
}