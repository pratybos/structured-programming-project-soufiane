#include <iostream>
#include <string>
#include <cctype>

bool hasUppercase(const std::string &password) {
    for (char ch : password) {
        if (isupper(ch)) return true;
    }
    return false;
}

bool hasLowercase(const std::string &password) {
    for (char ch : password) {
        if (islower(ch)) return true;
    }
    return false;
}

bool hasDigit(const std::string &password) {
    for (char ch : password) {
        if (isdigit(ch)) return true;
    }
    return false;
}

bool hasSpecialChar(const std::string &password) {
    const std::string specialChars = "!@#$%^&*()-_=+[{]}|;:'\",<.>/?`~";
    for (char ch : password) {
        if (specialChars.find(ch) != std::string::npos) return true;
    }
    return false;
}

void checkPasswordStrength(const std::string &password) {
    bool hasUpper = hasUppercase(password);
    bool hasLower = hasLowercase(password);
    bool hasDigit = hasDigit(password);
    bool hasSpecial = hasSpecialChar(password);
    bool isLongEnough = password.length() >= 8;

    std::cout << "\nPassword Strength Analysis:\n";
    if (isLongEnough && hasUpper && hasLower && hasDigit && hasSpecial) {
        std::cout << "Strong Password!\n";
        return;
    }

    std::cout << "Suggestions to improve your password:\n";
    if (!isLongEnough)
        std::cout << "- Make sure the password is at least 8 characters long.\n";
    if (!hasUpper)
        std::cout << "- Include at least one uppercase letter (A-Z).\n";
    if (!hasLower)
        std::cout << "- Include at least one lowercase letter (a-z).\n";
    if (!hasDigit)
        std::cout << "- Include at least one digit (0-9).\n";
    if (!hasSpecial)
        std::cout << "- Include at least one special character (e.g., !, @, #, $, etc.).\n";
}

int main() {
    std::string password;
    std::cout << "Enter a password to check its strength: ";
    std::getline(std::cin, password);

    checkPasswordStrength(password);

    return 0;
}
