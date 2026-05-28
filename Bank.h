#pragma once
#include <string>
#include <vector>
#include "User.h"
#include "Transaction.h"

const std::string REPORTS_DIRECTORY = "Reports/";

class Bank {
private:
    std::vector<User> users;
    std::vector<Transaction> transactionHistory;
public:
    Bank() = default;
    void addUser(const User& user);
    void processTransaction(const Transaction& transaction);
    void generateReport() const;
};