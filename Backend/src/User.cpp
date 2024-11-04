#include "User.h"
#include "UserValidation.h"
#include <iostream>
#include <string>

User::User(const std::string& username) {
    if (!UserValidation::isValidUsername(username)) {
        throw std::invalid_argument("Invalid username provided.");
    }
    this->username = username;
}

std::string User::getUsername() const {
    return username;
}

double User::getBalance() const {
    return balance;
}