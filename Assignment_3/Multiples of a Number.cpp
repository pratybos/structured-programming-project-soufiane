#include <iostream>

int main() {
    int number, count;

    // Prompt user for the base number and the number of multiples
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Enter how many multiples: ";
    std::cin >> count;

    // Print the multiples
    for (int i = 1; i <= count; ++i) {
        std::cout << number * i << " ";
    }
    std::cout << std::endl;

    return 0;
}
