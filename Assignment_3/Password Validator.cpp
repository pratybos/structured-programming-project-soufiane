#include <iostream>
#include <string>
#include <cctype> // For isdigit, islower, isupper

bool isValidPassword(const std::string& password) {
    // Check length
    if (password.length() < 8) {
        std::cout << "Password must be at least 8 characters long." << std::endl;
        return false;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false;

    // Check for at least one uppercase, one lowercase letter, and one digit
    for (char ch : password) {
        if (std::isupper(ch)) hasUpper = true;
        if (std::islower(ch)) hasLower = true;
        if (std::isdigit(ch)) hasDigit = true;
    }

    if (!hasUpper) {
        std::cout << "Password must contain at least one uppercase letter." << std::endl;
    }
    if (!hasLower) {
        std::cout << "Password must contain at least one lowercase letter." << std::endl;
    }
    if (!hasDigit) {
        std::cout << "Password must contain at least one digit." << std::endl;
    }

    return hasUpper && hasLower && hasDigit;
}

int main() {
    std::string password;

    std::cout << "Enter your password: ";
    std::cin >> password;

    if (isValidPassword(password)) {
        std::cout << "Password is valid." << std::endl;
    } else {
        std::cout << "Password is invalid." << std::endl;
    }

    return 0;
}
