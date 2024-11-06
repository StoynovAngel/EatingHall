#include "UserValidation.h"
#include <cctype>


bool UserValidation::isValidUsername(const std::string& username){
    if(username.empty()) return false;

    for (char c : username) {
        if (!std::isalpha(c) && c != ' ') return false;
    }

    return true;
}

bool UserValidation::balanceCheck(double balance){
    return balance >= 0;
}