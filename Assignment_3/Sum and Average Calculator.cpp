#include <iostream>

int main() {
    int number;
    int sum = 0;
    int count = 0;

    std::cout << "Enter numbers (negative number to stop): ";

    while (true) {
        std::cin >> number;

        // Stop if a negative number is entered
        if (number < 0) {
            break;
        }

        sum += number;
        count++;
    }

    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        std::cout << "Sum: " << sum << std::endl;
        std::cout << "Average: " << average << std::endl;
    } else {
        std::cout << "No positive numbers were entered." << std::endl;
    }

    return 0;
}
