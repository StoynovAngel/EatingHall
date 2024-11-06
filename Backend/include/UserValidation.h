#ifndef USERVALIDATION_H
#define USERVALIDATION_H
#include <string>

namespace UserValidation{
    bool isValidUsername(const std::string& username);
    bool balanceCheck(const double balance);
};


#endif