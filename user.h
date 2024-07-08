// user.h
#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include "DataModels.h"

class user {
protected:
    std::string UserId, UserName, Password, Email, MobNo, Profession, DefaultAccId, balance;

public:
    user();
    user(USER& u1);
    void setUserDetails();
    bool check();
    void writeToFile();
};

#endif // USER_H
