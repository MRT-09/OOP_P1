#include "User.h"
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
using namespace std;

User::User(int id, const string& name) : id(id), name(name) {}

User::User(const User& other) : id(other.id), name(other.name) {
    for (const auto& a : other.accounts)
        accounts.push_back(a->clone());
}

User& User::operator=(const User& other) {
    if (this == &other) return *this;
    id = other.id;
    name = other.name;
    accounts.clear();
    for (const auto& a : other.accounts)
        accounts.push_back(a->clone());
    return *this;
}

int User::getId() const {
    return id;
}

const string& User::getName() const {
    return name;
}

size_t User::accountCount() const {
    return accounts.size();
}

Account* User::getAccount(size_t index) {
    if (index >= accounts.size())
        return nullptr;
    return accounts[index].get();
}

const Account* User::getAccount(size_t index) const {
    if (index >= accounts.size())
        return nullptr;
    return accounts[index].get();
}

void User::addAccount(const Account& account) {
    accounts.push_back(account.clone());
}

void User::getAccounts() const {
    printAccounts();
}

void User::printAccounts() const {
    for (size_t index = 0; index < accounts.size(); index++) {
        cout << "Account #" << index + 1 << "\n";
        accounts[index]->printInfo();
    }
}