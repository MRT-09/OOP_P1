#include "Bank.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include "User.h"
#include "Transaction.h"
#include "utils.h"
using namespace std;

void Bank::addUser(const User& user) {
    users.push_back(user);
}

User* Bank::findUserById(int id) {
    for (auto& user : users) {
        if (user.id == id)
            return &user;
    }
    return nullptr;
}

const User* Bank::findUserById(int id) const {
    for (const auto& user : users) {
        if (user.id == id)
            return &user;
    }
    return nullptr;
}

const vector<User>& Bank::getUsers() const {
    return users;
}

void Bank::processTransaction(const Transaction& transaction) {
    transactionHistory.push_back(transaction);
}

void Bank::generateReport() const {
    string reportPath = REPORTS_DIRECTORY + "BankReport" + getCurrentDateTime() + ".txt";
    filesystem::create_directories(REPORTS_DIRECTORY);
    ofstream reportFile(reportPath);
    if (!reportFile.is_open())
        throw runtime_error("Failed to create report file.");
    reportFile << "Bank Users:\n";
    for (const auto& user : users)
        reportFile << "User ID: " << user.id << ", Name: " << user.name << "\n";
    reportFile << "Bank Transaction Report:\n";
    for (const auto& transaction : transactionHistory)
        reportFile << "Date: " << transaction.date << ", Type: " << transaction.type << ", Amount: " << transaction.amount << "\n";
}