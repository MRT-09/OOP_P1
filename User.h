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
    int getId() const;
    const std::string& getName() const;
    std::size_t accountCount() const;
    Account* getAccount(std::size_t index);
    const Account* getAccount(std::size_t index) const;
    void addAccount(const Account& account);
    void getAccounts() const;
    void printAccounts() const;
};