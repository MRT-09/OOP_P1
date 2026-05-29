#include <iostream>
#include "Bank.h"
#include "User.h"
#include "Account.h"
using namespace std;
int main() {
    Bank bank;
    User user1(0, "First"), user2(1, "Second");
    CheckingAccount checking1("CHK1", 1000), checking2("CHK2", 1500);
    SavingsAccount savings1("SAV1", 5000), savings2("SAV2", 3000, 0.03);
    CreditAccount credit1("CRD1", 2000, 5000), credit2("CRD2", 1000, 3000);
    bank.addUser(user1), bank.addUser(user2);
    user1.addAccount(checking1), user1.addAccount(savings1), user1.addAccount(credit1);
    user2.addAccount(checking2), user2.addAccount(savings2), user2.addAccount(credit2);
    checking1.deposit(500), savings1.applyInterest(), credit1.withdraw(1000);
    checking1.transfer(checking2, 200), savings1.transfer(savings2, 300), credit1.transfer(credit2, 500);
    bank.processTransaction(Transaction(200, "2024-06-01", "Deposit to CHK1"));
    bank.processTransaction(Transaction(-1000, "2024-06-01", "Withdrawal from CRD1"));
    bank.generateReport();
    return 0;
}