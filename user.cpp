// user.cpp
#include "user.h"

user::user() {
    setUserDetails();
}

user::user(USER& u1) {
    UserId = u1.UserId;
    UserName = u1.UserName;
    Password = u1.Password;
    Email = u1.Email;
    MobNo = u1.MobNo;
    Profession = u1.Profession;
    DefaultAccId = u1.DefaultAccId;
    balance = u1.balance;
}

void user::setUserDetails() {
    std::cout << "Enter UserId: ";
    std::cin >> UserId;
    if (check()) {
        std::cout << "Enter UserName: ";
        std::cin >> UserName;
        std::cout << "Enter Password: ";
        std::cin >> Password;
        std::cout << "Enter Email: ";
        std::cin >> Email;
        std::cout << "Enter Mobile Number: ";
        std::cin >> MobNo;
        std::cout << "Enter Profession: ";
        std::cin >> Profession;
        std::cout << "Enter Default Account Id: ";
        std::cin >> DefaultAccId;
        std::cout << "Enter Opening Balance: ";
        std::cin >> balance;
        writeToFile();
    }
}

bool user::check() {
    std::ifstream in("users.txt");
    USER temp;
    while (in >> temp.UserId >> temp.UserName >> temp.Password >> temp.Email >> temp.MobNo >> temp.Profession >> temp.DefaultAccId >> temp.balance) {
        if (temp.UserId == UserId) {
            std::cout << "\nUser Already Exists.....\n\n";
            return false;
        }
    }
    return true;
}

void user::writeToFile() {
    std::ofstream file("users.txt", std::ios::app);
    if (file.is_open()) {
        file << UserId << " " << UserName << " " << Password << " " << Email << " " << MobNo << " " << Profession << " " << DefaultAccId << " " << balance << std::endl;
        file.close();
    } else {
        std::cout << "Error opening the file." << std::endl;
    }
}
