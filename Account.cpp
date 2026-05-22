#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(const string& accountNumber, double initialBalance) {
    this->accountNumber = accountNumber;
    balance = initialBalance;
}

void Account::deposit(double amount) {
    if (amount > 0)
        balance += amount;
}

void Account::transfer(Account& recipient, double amount) {
    if (amount > 0 && withdraw(amount)) {
        recipient.deposit(amount);
    }
}

void Account::printInfo() const {
    cout << "Account Number: " << accountNumber << "\n";
    cout << "Balance: " << balance << "\n";
}

CheckingAccount::CheckingAccount(const string& accountNumber, double initialBalance) : Account(accountNumber, initialBalance) {}

bool CheckingAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}