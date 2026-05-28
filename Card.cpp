#include "Card.h"
#include <string>
#include "Account.h"

Card::Card(const std::string& cardNumber, Account* linkedAccount, double limit) : cardNumber(cardNumber), linkedAccount(linkedAccount), limit(limit) {}