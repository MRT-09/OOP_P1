#include "Bank.h"
#include <iostream>
#include <vector>
#include "User.h"
#include "Transaction.h"
using namespace std;

void Bank::addUser(const User& user) {
    users.push_back(user);
}

void Bank::processTransaction(const Transaction& transaction) {
    transactionHistory.push_back(transaction);
}

void Bank::generateReport() const {
    cout << "Bank Users:\n";
    for (const auto& user : users)
        cout << "User ID: " << user.id << ", Name: " << user.name << "\n";
    cout << "Bank Transaction Report:\n";
    for (const auto& transaction : transactionHistory)
        cout << "Date: " << transaction.date << ", Type: " << transaction.type << ", Amount: " << transaction.amount << "\n";
}