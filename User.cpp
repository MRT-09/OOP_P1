#include "User.h"
#include <string>
#include <vector>
#include "Account.h"

User::User(int id, const std::string& name) : id(id), name(name) {}

void User::addAccount(const Account& account) {
    accounts.push_back(account);
}

void User::getAccounts() const {
    for (const auto& account : accounts)
        account.printInfo();
}