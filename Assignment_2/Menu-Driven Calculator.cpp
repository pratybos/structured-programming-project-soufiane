/*#include <iostream>

int main() {
    // Variables to hold user input
    double num1, num2;
    char operation;

    // Display menu
    std::cout << "Basic Arithmetic Operations\n";
    std::cout << "Choose an operation:\n";
    std::cout << " + : Addition\n";
    std::cout << " - : Subtraction\n";
    std::cout << " * : Multiplication\n";
    std::cout << " / : Division\n";
    std::cout << "Enter your choice: ";
    std::cin >> operation;

    // Input two numbers
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    // Perform the chosen operation
    switch (operation) {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
        break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
        break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
        break;
        case '/':
            // Handle division by zero
                if (num2 == 0) {
                    std::cout << "Error: Division by zero is not allowed." << std::endl;
                } else {
                    std::cout << "Result: " << num1 / num2 << std::endl;
                }
        break;
        default:
            std::cout << "Error: Invalid operation selected." << std::endl;
        break;
    }

    return 0;
}
