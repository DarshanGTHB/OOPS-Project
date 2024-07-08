// DataModels.h
#ifndef DATAMODELS_H
#define DATAMODELS_H

#include <string>

struct USER {
    std::string UserId;
    std::string UserName;
    std::string Password;
    std::string Email;
    std::string MobNo;
    std::string Profession;
    std::string DefaultAccId;
    std::string balance;
};

struct Transaction {
    std::string userId;
    std::string transactionId;
    std::string transactionDate;
    std::string title;
    std::string description;
    std::string accountId;
    std::string entryDate;
    float amount;
    std::string recieveFrom_or_SentTo;
};

#endif // DATAMODELS_H
