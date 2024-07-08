// HOME.cpp
#include "HOME.h"
#include<set>
#include<string>
#include <iomanip>

void HOME(std::string id) {
    income* i;
    expense* e;

    std::cout << "1.Profile\n";
    std::cout << "2.Income Entry\n";
    std::cout << "3.Expense Entry\n";
    std::cout << "4.Daily Transaction\n";
    std::cout << "5.Sort Transaction\n";
    std::cout << "6.Log Out\n";

    char c;
    std::cin >> c;
    while (c != '6') {
        switch (c) {
        case '1':
            std::cout << "\nProfile:\n\n";
            profile(id);
            break;

        case '2':
            i = new income(id);
            delete (i);
            break;

        case '3':
            e = new expense(id);
            delete (e);
            break;

        case '4':
            dailyTransaction(id);
            break;
        case '5':
            SORT();
            std::cout << "\nSuccessfully Sorted .....\n\n";
            break;
        }

        std::cin >> c;
    }

    std::cout << "\nLogging Out.......\n\n";
    std::cout << "1.New Registration\n2.Log_In\n3.Exit\n";
}

void profile(std::string id) {
    std::ifstream in("users.txt");
    USER temp;
    while (in >> temp.UserId >> temp.UserName >> temp.Password >> temp.Email >> temp.MobNo >> temp.Profession >> temp.DefaultAccId >> temp.balance) {
        if (temp.UserId == id) {
            std::cout << "User Id       : " << temp.UserId << std::endl;
            std::cout << "Balance       : " << temp.balance << std::endl;
            std::cout << "Name          : " << temp.UserName << std::endl;
            std::cout << "Email Id      : " << temp.Email << std::endl;
            std::cout << "Mobile No     : " << temp.MobNo << std::endl;
            std::cout << "Profession    : " << temp.Profession << std::endl;
            break;
        }
    }
    in.close();
}

void SORT() {
    std::set<std::string> SetDate;
    std::vector<Transaction> t1(0);
    Transaction temp;
    std::ifstream in("income.txt");
    
    while (in >> temp.userId >> temp.transactionId >> temp.transactionDate >> temp.title >> temp.description >> temp.accountId >> temp.entryDate >> temp.amount) {
        t1.push_back(temp);
        SetDate.insert(temp.transactionDate);
    }
    in.close();
    std::ofstream out("sorted_transaction.txt");

    for (auto i = SetDate.begin(); i != SetDate.end(); i++) {
        for (int j = 0; j < t1.size(); j++) {
            if (t1[j].transactionDate == *i) {
                out << t1[j].userId << " " << t1[j].transactionId << " " << t1[j].transactionDate << " " << t1[j].title << " " << t1[j].description << " " << t1[j].accountId << " " << t1[j].entryDate << " " << t1[j].amount << std::endl;
            }
        }
    }
    out.close();
}

void dailyTransaction(std::string id) {
    std::ifstream in("sorted_transaction.txt");
    Transaction t1;
    std::cout << "\nIncome Info:\n\n";
    std::cout << std::setw(20) << "Title" << std::setw(20) << "Description" << std::setw(20) << "Amount" << std::setw(20) << "Date \n";
    std::cout << "------------------------------------------------------------------------------------------------------\n";
    while (in >> t1.userId >> t1.transactionId >> t1.transactionDate >> t1.title >> t1.description >> t1.accountId >> t1.entryDate >> t1.amount) {
        if (id == t1.userId) {
            std::cout << std::setw(20) << t1.title << std::setw(20) << t1.description << std::setw(20) << t1.amount << std::setw(20) << t1.transactionDate << std::endl;
        }   
    }
    in.close();

    std::ifstream innn("expense.txt");
    Transaction t2;
    std::cout << "\nExpense Info:\n\n";
    std::cout << std::setw(20) << "Title" << std::setw(20) << "Description" << std::setw(20) << "Amount" << std::setw(20) << "SendTo" << std::setw(20) << "Date \n";
    std::cout << "------------------------------------------------------------------------------------------------------\n";

    while (innn >> t2.userId >> t2.transactionId >> t2.transactionDate >> t2.title >> t2.description >> t2.accountId >> t2.entryDate >> t2.amount >> t2.recieveFrom_or_SentTo) {
        if (id == t2.userId) {
            std::cout << std::setw(20) << t2.title << std::setw(20) << t2.description << std::setw(20) << t2.amount << std::setw(20) << t2.recieveFrom_or_SentTo << std::setw(20) << t2.transactionDate << std::endl;
        }   
    }
    innn.close();
}
