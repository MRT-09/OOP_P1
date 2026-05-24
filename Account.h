#pragma once
#include <string>

class Account {
protected:
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

class CheckingAccount : public Account {
public:
    CheckingAccount(const std::string& accountNumber, double initialBalance);
    bool withdraw(double amount) override;
};

class SavingsAccount : public Account {
private:
    double interestRate;
public:
    SavingsAccount(const std::string& accountNumber, double initialBalance);
    SavingsAccount(const std::string& accountNumber, double initialBalance, double interestRate);
    void applyInterest();
    bool withdraw(double amount) override;
};