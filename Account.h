#pragma once
#include <string>

class Account {
private:
    std::string accountNumber;
    double balance;
public:
    Account(const std::string& accountNumber, double initialBalance);
    virtual ~Account() = default;
    virtual void deposit(double amount);
    virtual bool withdraw(double amount) = 0;
    virtual void transfer(Account& recipient, double amount);
    virtual void printInfo() const;
};
