#pragma once
#include <string>
#include <vector>
#include "Account.h"
#include <memory>

class Bank;

class User {
    friend class Bank;

private:
    int id;
    std::string name;
    std::vector<std::unique_ptr<Account>> accounts;

public:
    User(int id, const std::string& name);
    User(const User& other);
    User& operator=(const User& other);
    void addAccount(const Account& account);
    void getAccounts() const;
};