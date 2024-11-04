#ifndef USERVALIDATION_H
#define USERVALIDATION_H
#include <string>

class UserValidation{
public:
    static bool isValidUsername(const std::string& username);
    static bool balanceCheck(const double balance);
};


#endif