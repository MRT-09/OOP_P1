#pragma once
#include <string>
#include <vector>
#include "Account.h"
#include "Bank.h"

class User {
    friend class Bank;

private:
    int id;
    std::string name;

public:
    User(int id, const std::string& name);
    void addAccount(const Account& account);
    void getAccounts() const;
};