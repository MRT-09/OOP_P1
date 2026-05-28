#pragma once
#include <string>

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