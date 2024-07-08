// transaction.h
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <fstream>
#include <vector>
#include "GenTid.h"
#include "DateUtil.h"
#include "DataModels.h"

class transaction {
protected:
    std::string userId, transactionId = GenTid(), transactionDate, title, description, accountId, entryDate = todayDate();
    float amount;

public:
    virtual void Trigger() = 0; // Pure Virtual Function
};

class income : public transaction {
public:
    income(std::string uid);
    void printConsole();
    income* printFile();
    income* getIncomeInfo();
    void Trigger() override;
};

class expense : public transaction {
protected:
    std::string sentTo;

public:
    expense(std::string uid);
    void printConsole();
    void printFile();
    void getExpenseInfo();
    void Trigger() override;
};

#endif // TRANSACTION_H
