// transaction.cpp
#include "transaction.h"
#include<iostream>

income::income(std::string uid) {
    userId = uid;
    getIncomeInfo()->printFile()->Trigger();
    std::cout << "\nTransaction is Done Successfully.....\n\n";
}

void income::printConsole() {
    std::cout.fill('-');
    std::cout.width(100);
    std::cout << "" << std::endl;

    std::cout.fill(' ');
    std::cout << title;
    std::cout.width(20);
    std::cout << description;
    std::cout.width(10);
    std::cout << accountId;
    std::cout.width(15);
    std::cout << transactionDate;
    std::cout.width(20);
    std::cout << amount;
    std::cout << std::endl;
}

income* income::printFile() {
    std::ofstream file("income.txt", std::ios::app);
    file << userId << " " << transactionId << " " << transactionDate << " " << title << " " << description << " " << accountId << " " << entryDate << " " << amount << " " << std::endl;
    file.close();
    return this;
}

income* income::getIncomeInfo() {
    std::cout << "Enter Income Title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Enter Description: ";
    std::getline(std::cin, description);
    std::cout << "Enter Account ID: ";
    std::cin >> accountId;
    std::cout << "Enter Transaction Date (yyyy-mm-dd): ";
    std::cin.ignore();
    std::getline(std::cin, transactionDate);
    std::cout << "Enter Amount: ";
    std::cin >> amount;
    
    return this;
}

void income::Trigger() {
    std::ifstream in("users.txt");
    USER temp;
    std::vector<USER> U;
    while (in >> temp.UserId >> temp.UserName >> temp.Password >> temp.Email >> temp.MobNo >> temp.Profession >> temp.DefaultAccId >> temp.balance) {
        U.push_back(temp);
    }
    in.close();
    
    std::ofstream out("users.txt");

    for (auto& i : U) {
        if (i.UserId == userId) {
            out << i.UserId << " " << i.UserName << " " << i.Password << " " << i.Email << " " << i.MobNo << " " << i.Profession << " " << i.DefaultAccId << " " << std::to_string(stof(i.balance) + (amount)) << std::endl;
        } else {
            out << i.UserId << " " << i.UserName << " " << i.Password << " " << i.Email << " " << i.MobNo << " " << i.Profession << " " << i.DefaultAccId << " " << i.balance << std::endl;
        }
    }
    out.close();
}

expense::expense(std::string uid) {
    userId = uid;
    getExpenseInfo();
    Trigger();
    printFile();
    std::cout << "\nTransaction is Done Successfully.....\n\n";
}

void expense::printConsole() {
    std::cout.fill('-');
    std::cout.width(100);
    std::cout << "" << std::endl;

    std::cout.fill(' ');
    std::cout << title;
    std::cout.width(20);
    std::cout << description;
    std::cout.width(10);
    std::cout << accountId;
    std::cout.width(15);
    std::cout << transactionDate;
    std::cout.width(20);
    std::cout << sentTo;
    std::cout.width(20);
    std::cout << amount;
    std::cout << std::endl;
}

void expense::printFile() {
    std::ofstream file("expense.txt", std::ios::app);
    file << userId << " " << transactionId << " " << transactionDate << " " << title << " " << description << " " << accountId << " " << entryDate << " " << amount << " " << sentTo << " " << std::endl;
    file.close();
}

void expense::getExpenseInfo() {
    std::cout << "Enter Expense Title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Enter Description: ";
    std::getline(std::cin, description);
    std::cout << "Enter Account ID: ";
    std::cin >> accountId;
    std::cout << "Enter Transaction Date (yyyy-mm-dd): ";
    std::cin.ignore();
    std::getline(std::cin, transactionDate);
    std::cout << "Sent To: /enter '0' if it is not a user-to-user Transaction : ";
    std::cin >> sentTo;
    std::cout << "Enter Amount: ";
    std::cin >> amount;
}

void expense::Trigger() {
    if (sentTo != "0") {
        std::ofstream file("income.txt", std::ios::app);
        file << sentTo << " " << transactionId << " " << transactionDate << " " << title << " " << description << " " << accountId << " " << entryDate << " " << amount << " "  << std::endl;
        file.close();
    }

    std::ifstream in("users.txt");
    USER temp;
    std::vector<USER> U;
    while (in >> temp.UserId >> temp.UserName >> temp.Password >> temp.Email >> temp.MobNo >> temp.Profession >> temp.DefaultAccId >> temp.balance) {
        U.push_back(temp);
    }
    in.close();

    std::ofstream out("users.txt");

    for (auto& i : U) {
        if (i.UserId == userId) {
            out << i.UserId << " " << i.UserName << " " << i.Password << " " << i.Email << " " << i.MobNo << " " << i.Profession << " " << i.DefaultAccId << " " << std::to_string(stof(i.balance) - (amount)) << std::endl;
        } else if (sentTo != "0" && i.UserId == sentTo) {
            out << i.UserId << " " << i.UserName << " " << i.Password << " " << i.Email << " " << i.MobNo << " " << i.Profession << " " << i.DefaultAccId << " " << std::to_string(stof(i.balance) + (amount)) << std::endl;
        } else {
            out << i.UserId << " " << i.UserName << " " << i.Password << " " << i.Email << " " << i.MobNo << " " << i.Profession << " " << i.DefaultAccId << " " << i.balance << std::endl;
        }
    }
    out.close();
}
