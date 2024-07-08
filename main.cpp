// main.cpp
#include <iostream>
#include "user.h"
#include "login.h"

int main() {
    std::cout << "1.New Registration\n2.Log_In\n3.Exit\n";
    char choice;
    std::cin >> choice;

    user* u;
    login* l;
    while (choice != '3') {
        switch (choice) {
        case '1':
            u = new user;
            break;
        case '2':
            l = new login;
            break;

        default:
            std::cout << "\nInvalid Choice ....\n\n";
            fflush(stdin);
            break;
        }
        std::cin >> choice;
    }
    std::cout << "\n-----X-----X-----X-----X-----Exited-----X-----X-----X-----X-----\n\n";

    return 0;
}
