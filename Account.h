#pragma once
#include <string>
#include <vector>
#include "Transaction.h"

#define DEFAULT_INTEREST_RATE 0.02

class Account {
    friend class User;
protected:
    std::string accountNumber;
    double balance;
    std::vector<Transaction> transactionHistory;
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

class CreditAccount : public Account {
private:
    double creditLimit;
public:
    CreditAccount(const std::string& accountNumber, double initialBalance, double creditLimit);
    bool withdraw(double amount) override;
};