#pragma once
#include <string>

class Transaction {
    friend class Account;
private:
    double amount;
    std::string date, type;
public:
    Transaction(double amt, const std::string& dt, const std::string& tp);
};