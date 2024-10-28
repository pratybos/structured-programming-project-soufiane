/*#include <iostream>
#include <string>

int main() {
    // Variables to hold user input
    int age;
    char citizenStatus;

    // Prompt user for age
    std::cout << "Enter your age: ";
    std::cin >> age;

    // Prompt user for citizenship status
    std::cout << "Are you a citizen? (y/n): ";
    std::cin >> citizenStatus;

    // Check eligibility for voting
    bool isEligible = (age >= 18) && (citizenStatus == 'y' || citizenStatus == 'Y');

    // Output the result
    if (isEligible) {
        std::cout << "You are eligible to vote." << std::endl;
    } else {
        std::cout << "You are not eligible to vote." << std::endl;
    }

    return 0;
}
