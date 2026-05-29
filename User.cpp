#include "User.h"
#include <string>
#include <vector>
#include "Account.h"

User::User(int id, const std::string& name) : id(id), name(name) {}

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

void User::addAccount(const Account& account) {
    accounts.push_back(account.clone());
}

void User::getAccounts() const {
    for (const auto& account : accounts)
        account->printInfo();
}