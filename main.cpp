#include <iostream>
#include <limits>
#include <string>
#include "Bank.h"
#include "User.h"
#include "Account.h"
#include "Transaction.h"
#include "utils.h"
using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value)
            return value;
        clearInput();
        cout << "Invalid input. Try again.\n";
    }
}

double readDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value)
            return value;
        clearInput();
        cout << "Invalid input. Try again.\n";
    }
}

string readLine(const string& prompt) {
    cout << prompt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string value;
    getline(cin, value);
    return value;
}

void listUsers(const Bank& bank) {
    const auto& users = bank.getUsers();
    if (users.empty()) {
        cout << "No users available.\n";
        return;
    }

    for (const auto& user : users)
        cout << "User ID: " << user.getId() << ", Name: " << user.getName() << ", Accounts: " << user.accountCount() << '\n';
}

void addUser(Bank& bank) {
    int id = readInt("Enter user ID: ");
    string name = readLine("Enter user name: ");

    if (bank.findUserById(id) != nullptr) {
        cout << "A user with that ID already exists.\n";
        return;
    }

    bank.addUser(User(id, name));
    cout << "User added.\n";
}

User* selectUser(Bank& bank) {
    int id = readInt("Enter user ID: ");
    User* user = bank.findUserById(id);
    if (user == nullptr)
        cout << "User not found.\n";
    return user;
}

void addAccountToUser(Bank& bank) {
    User* user = selectUser(bank);
    if (user == nullptr)
        return;

    cout << "Account type:\n";
    cout << "1. Checking\n";
    cout << "2. Savings\n";
    cout << "3. Credit\n";
    int type = readInt("Choose account type: ");
    string accountNumber = readLine("Enter account number: ");
    double initialBalance = readDouble("Enter initial balance: ");

    if (type == 1) {
        user->addAccount(CheckingAccount(accountNumber, initialBalance));
    } else if (type == 2) {
        double interestRate = readDouble("Enter interest rate (0 for default): ");
        if (interestRate > 0)
            user->addAccount(SavingsAccount(accountNumber, initialBalance, interestRate));
        else
            user->addAccount(SavingsAccount(accountNumber, initialBalance));
    } else if (type == 3) {
        double creditLimit = readDouble("Enter credit limit: ");
        user->addAccount(CreditAccount(accountNumber, initialBalance, creditLimit));
    } else {
        cout << "Invalid account type.\n";
        return;
    }

    cout << "Account added.\n";
}

void showUserAccounts(Bank& bank) {
    User* user = selectUser(bank);
    if (user == nullptr)
        return;

    cout << "Accounts for " << user->getName() << ":\n";
    user->printAccounts();
}

Account* selectAccount(User& user) {
    if (user.accountCount() == 0) {
        cout << "This user has no accounts.\n";
        return nullptr;
    }

    user.printAccounts();
    int accountIndex = readInt("Choose account number: ");
    Account* account = user.getAccount(static_cast<size_t>(accountIndex - 1));
    if (account == nullptr)
        cout << "Invalid account selection.\n";
    return account;
}

void depositToAccount(Bank& bank) {
    User* user = selectUser(bank);
    if (user == nullptr)
        return;

    Account* account = selectAccount(*user);
    if (account == nullptr)
        return;

    double amount = readDouble("Enter deposit amount: ");
    account->deposit(amount);
    bank.processTransaction(Transaction(amount, getCurrentDate(), "Deposit"));
    cout << "Deposit completed.\n";
}

void withdrawFromAccount(Bank& bank) {
    User* user = selectUser(bank);
    if (user == nullptr)
        return;

    Account* account = selectAccount(*user);
    if (account == nullptr)
        return;

    double amount = readDouble("Enter withdrawal amount: ");
    if (account->withdraw(amount)) {
        bank.processTransaction(Transaction(-amount, getCurrentDate(), "Withdrawal"));
        cout << "Withdrawal completed.\n";
    } else {
        cout << "Withdrawal failed.\n";
    }
}

void transferBetweenAccounts(Bank& bank) {
    cout << "Source account:\n";
    User* sourceUser = selectUser(bank);
    if (sourceUser == nullptr)
        return;

    Account* sourceAccount = selectAccount(*sourceUser);
    if (sourceAccount == nullptr)
        return;

    cout << "Recipient account:\n";
    User* recipientUser = selectUser(bank);
    if (recipientUser == nullptr)
        return;

    Account* recipientAccount = selectAccount(*recipientUser);
    if (recipientAccount == nullptr)
        return;

    double amount = readDouble("Enter transfer amount: ");
    sourceAccount->transfer(*recipientAccount, amount);
    bank.processTransaction(Transaction(-amount, getCurrentDate(), "Transfer"));
    cout << "Transfer completed if the source account had sufficient funds.\n";
}

void applyInterestToSavings(Bank& bank) {
    User* user = selectUser(bank);
    if (user == nullptr)
        return;

    Account* account = selectAccount(*user);
    if (account == nullptr)
        return;

    auto* savings = dynamic_cast<SavingsAccount*>(account);
    if (savings == nullptr) {
        cout << "Selected account is not a savings account.\n";
        return;
    }

    savings->applyInterest();
    cout << "Interest applied.\n";
}

void recordCustomTransaction(Bank& bank) {
    double amount = readDouble("Enter transaction amount: ");
    string type = readLine("Enter transaction description: ");
    bank.processTransaction(Transaction(amount, getCurrentDate(), type));
    cout << "Transaction recorded.\n";
}

void showMenu() {
    cout << "\nBanking Menu\n";
    cout << "1. Add user\n";
    cout << "2. Add account to user\n";
    cout << "3. List users\n";
    cout << "4. Show user accounts\n";
    cout << "5. Deposit\n";
    cout << "6. Withdraw\n";
    cout << "7. Transfer\n";
    cout << "8. Apply interest to savings account\n";
    cout << "9. Record transaction\n";
    cout << "10. Generate report\n";
    cout << "0. Exit\n";
}

int main() {
    Bank bank;

    while (true) {
        showMenu();
        int choice = readInt("Choose an option: ");

        switch (choice) {
            case 1:
                addUser(bank);
                break;
            case 2:
                addAccountToUser(bank);
                break;
            case 3:
                listUsers(bank);
                break;
            case 4:
                showUserAccounts(bank);
                break;
            case 5:
                depositToAccount(bank);
                break;
            case 6:
                withdrawFromAccount(bank);
                break;
            case 7:
                transferBetweenAccounts(bank);
                break;
            case 8:
                applyInterestToSavings(bank);
                break;
            case 9:
                recordCustomTransaction(bank);
                break;
            case 10:
                bank.generateReport();
                cout << "Report generated in the Reports folder.\n";
                break;
            case 0:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
}