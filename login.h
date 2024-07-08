// login.h
#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <fstream>
#include "DataModels.h"
#include "HOME.h"

class login {
    std::string id, password;

public:
    login();
    void getinfo();
    void check();
};

#endif // LOGIN_H
