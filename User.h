#pragma once
#include <string>
#include <vector>
#include "Account.h"

class User {
private:
    int id;
    std::string name;
    std::vector<Account> accounts;
public:
    User(int id, const std::string& name);
    void addAccount(const Account& account);
    void getAccounts() const;
};