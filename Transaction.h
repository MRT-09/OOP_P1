#pragma once
#include <string>

#define MAX_TRANSACTION_AMOUNT 5000

class Transaction {
    friend class Account;
    friend class Bank;
private:
    double amount;
    std::string date, type;
    bool suspicious;
public:
    Transaction(double amt, const std::string& dt, const std::string& tp);
};