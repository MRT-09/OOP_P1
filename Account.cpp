#include "Account.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string getCurrentDate() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    char buffer[16];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", ltm);
    return string(buffer);
}

Account::Account(const string& accountNumber, double initialBalance) {
    this->accountNumber = accountNumber;
    balance = initialBalance;
}

void Account::deposit(double amount) {
    if (amount > 0)
        balance += amount;
    transactionHistory.push_back(Transaction(amount, getCurrentDate(), "Deposit"));
}

void Account::transfer(Account& recipient, double amount) {
    if (amount > 0 && withdraw(amount))
        recipient.deposit(amount);
    transactionHistory.push_back(Transaction(-amount, getCurrentDate(), "Transfer to " + recipient.accountNumber));
    recipient.transactionHistory.push_back(Transaction(amount, getCurrentDate(), "Transfer from " + accountNumber));
}

void Account::printInfo() const {
    cout << "Account Number: " << accountNumber << "\n";
    cout << "Balance: " << balance << "\n";
}

CheckingAccount::CheckingAccount(const string& accountNumber, double initialBalance) : Account(accountNumber, initialBalance) {}

bool CheckingAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        transactionHistory.push_back(Transaction(-amount, getCurrentDate(), "Withdrawal"));
        return true;
    }
    return false;
}

SavingsAccount::SavingsAccount(const string& accountNumber, double initialBalance) : Account(accountNumber, initialBalance), interestRate(0.02) {}
SavingsAccount::SavingsAccount(const string& accountNumber, double initialBalance, double interestRate) : Account(accountNumber, initialBalance), interestRate(interestRate) {}

void SavingsAccount::applyInterest() {
    balance += balance * interestRate;
}

bool SavingsAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        transactionHistory.push_back(Transaction(-amount, getCurrentDate(), "Withdrawal"));
        return true;
    }
    return false;
}

CreditAccount::CreditAccount(const string& accountNumber, double initialBalance, double creditLimit) : Account(accountNumber, initialBalance), creditLimit(creditLimit) {}

bool CreditAccount::withdraw(double amount) {
    if (amount > 0 && (balance + creditLimit) >= amount) {
        balance -= amount;
        transactionHistory.push_back(Transaction(-amount, getCurrentDate(), "Withdrawal"));
        return true;
    }
    return false;
}