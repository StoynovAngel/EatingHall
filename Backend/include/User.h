#ifndef USER_H
#define USER_H
#include <string>
#include <stdexcept> 

class User{
private:
    std::string username;
    double balance;
public:
    User(const std::string& username);
    User(const std::string& username, double balance);
    std::string getUsername() const;
    double getBalance() const;
};


#endif