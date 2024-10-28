#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Expense {
    std::string type;
    double amount;
    std::string description;
};

// Function to add a new expense
void addExpense(std::vector<Expense>& expenses) {
    Expense newExpense;
    std::cout << "Enter expense type (e.g., food, transport): ";
    std::cin >> newExpense.type;
    std::cout << "Enter amount: ";
    std::cin >> newExpense.amount;
    std::cin.ignore(); // Clear newline from input buffer
    std::cout << "Enter description: ";
    std::getline(std::cin, newExpense.description);

    expenses.push_back(newExpense);
    std::cout << "Expense added successfully.\n" << std::endl;
}

// Function to calculate the total expenditure
double calculateTotal(const std::vector<Expense>& expenses) {
    double total = 0.0;
    for (const auto& expense : expenses) {
        total += expense.amount;
    }
    return total;
}

// Function to display expenses by category
void displayExpensesByType(const std::vector<Expense>& expenses, const std::string& type) {
    bool found = false;
    std::cout << "\nExpenses for category: " << type << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    for (const auto& expense : expenses) {
        if (expense.type == type) {
            std::cout << "Amount: $" << expense.amount << " | Description: " << expense.description << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No expenses found for this category.\n";
    }
}

// Function to display all expenses
void displayAllExpenses(const std::vector<Expense>& expenses) {
    std::cout << "\nAll Expenses:\n";
    std::cout << "-----------------------------------" << std::endl;
    for (const auto& expense : expenses) {
        std::cout << "Type: " << expense.type << " | Amount: $" << std::fixed << std::setprecision(2)
                  << expense.amount << " | Description: " << expense.description << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Total Expenditure: $" << std::fixed << std::setprecision(2) << calculateTotal(expenses) << std::endl;
}

int main() {
    std::vector<Expense> expenses;
    int choice;

    do {
        std::cout << "\nExpense Tracker Menu:\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. View All Expenses\n";
        std::cout << "3. View Expenses by Category\n";
        std::cout << "4. View Total Expenditure\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                addExpense(expenses);
                break;
            }
            case 2: {
                displayAllExpenses(expenses);
                break;
            }
            case 3: {
                std::string type;
                std::cout << "Enter category to view expenses: ";
                std::cin >> type;
                displayExpensesByType(expenses, type);
                break;
            }
            case 4: {
                double total = calculateTotal(expenses);
                std::cout << "\nTotal Expenditure: $" << std::fixed << std::setprecision(2) << total << std::endl;
                break;
            }
            case 5: {
                std::cout << "Exiting Expense Tracker. Goodbye!" << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
