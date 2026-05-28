#include "Transaction.h"
#include <string>
using namespace std;

Transaction::Transaction(double amt, const string& dt, const string& tp) : amount(amt), date(dt), type(tp), suspicious(amt > MAX_TRANSACTION_AMOUNT) {}