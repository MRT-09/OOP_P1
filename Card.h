#pragma once
#include <string>
#include "Account.h"

class Card {
    friend class Account;
private:
    std::string cardNumber;
    Account* linkedAccount;
    double limit;
public:
    Card(const std::string& cardNumber, Account* linkedAccount, double limit);
};