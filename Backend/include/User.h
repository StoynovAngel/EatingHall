#ifndef USER_H
#define USER_H
#include <string>
#include <stdexcept> 

class User{
private:
    std::string username;
    double balance = 100.0;
public:
    User(const std::string& username);
    std::string getUsername() const;
    double getBalance() const;
};


#endif