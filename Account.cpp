#include "Account.h"
#include <iostream>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

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