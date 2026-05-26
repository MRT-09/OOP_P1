#include "Transaction.h"
#include <string>
using namespace std;

Transaction::Transaction(double amt, const string& dt, const string& tp) : amount(amt), date(dt), type(tp) {}

double Transaction::getAmount() const {
    return amount;
}

string Transaction::getDate() const {
    return date;
}

string Transaction::getType() const {
    return type;
}