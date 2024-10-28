#include <iostream>
#include <vector>
#include <string>

struct Account {
    int accountNumber;
    std::string name;
    double balance;

    Account(int accNum, std::string accName, double initialBalance = 0.0)
        : accountNumber(accNum), name(accName), balance(initialBalance) {}
};

class Bank {
private:
    std::vector<Account> accounts;
    int nextAccountNumber = 1001;

    Account* findAccount(int accountNumber) {
        for (auto& acc : accounts) {
            if (acc.accountNumber == accountNumber) {
                return &acc;
            }
        }
        return nullptr;
    }

public:
    void createAccount(const std::string& name, double initialDeposit) {
        Account newAccount(nextAccountNumber++, name, initialDeposit);
        accounts.push_back(newAccount);
        std::cout << "Account created successfully. Account Number: "
                  << newAccount.accountNumber << "\n";
    }

    void deposit(int accountNumber, double amount) {
        Account* account = findAccount(accountNumber);
        if (account) {
            account->balance += amount;
            std::cout << "Deposited $" << amount << " to account number "
                      << accountNumber << ". New balance: $" << account->balance << "\n";
        } else {
            std::cout << "Account not found.\n";
        }
    }

    void withdraw(int accountNumber, double amount) {
        Account* account = findAccount(accountNumber);
        if (account) {
            if (account->balance >= amount) {
                account->balance -= amount;
                std::cout << "Withdrew $" << amount << " from account number "
                          << accountNumber << ". New balance: $" << account->balance << "\n";
            } else {
                std::cout << "Insufficient balance.\n";
            }
        } else {
            std::cout << "Account not found.\n";
        }
    }

    void checkBalance(int accountNumber) {
        Account* account = findAccount(accountNumber);
        if (account) {
            std::cout << "Balance for account number " << accountNumber
                      << " is: $" << account->balance << "\n";
        } else {
            std::cout << "Account not found.\n";
        }
    }
};

int main() {
    Bank bank;
    int choice;
    do {
        std::cout << "\nBank Menu:\n"
                  << "1. Create Account\n"
                  << "2. Deposit Money\n"
                  << "3. Withdraw Money\n"
                  << "4. Check Balance\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                double initialDeposit;
                std::cout << "Enter account holder's name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter initial deposit: ";
                std::cin >> initialDeposit;
                bank.createAccount(name, initialDeposit);
                break;
            }
            case 2: {
                int accountNumber;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                bank.deposit(accountNumber, amount);
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;
            }
            case 4: {
                int accountNumber;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                bank.checkBalance(accountNumber);
                break;
            }
            case 5:
                std::cout << "Thank you for using our banking system!\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
