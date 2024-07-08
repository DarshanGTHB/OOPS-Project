// login.cpp
#include "login.h"

login::login() {
    getinfo();
    check();
}

void login::getinfo() {
    std::cout << "Enter Your Id: ";
    std::cin >> id;
    std::cout << "Enter Your Password: ";
    std::cin >> password;
}

void login::check() {
    std::ifstream file("users.txt");
    USER u1;
    bool flag = false;
    while (file >> u1.UserId >> u1.UserName >> u1.Password >> u1.Email >> u1.MobNo >> u1.Profession >> u1.DefaultAccId >> u1.balance) {
        if (u1.UserId == id && u1.Password == password) {
            std::cout << "\n************************************************** HOME ******************************************************\n\n";
            flag = true;
            HOME(id);
        }
    }
    if (!flag)
        std::cout << "\nInvalid ID/Password.....\n\n";
    file.close();
}
