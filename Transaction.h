#pragma once
#include <string>

class Transaction {
private:
    double amount;
    std::string date, type;
public:
    Transaction(double amt, const std::string& dt, const std::string& tp);
    double getAmount() const;
    std::string getDate() const;
    std::string getType() const;
};