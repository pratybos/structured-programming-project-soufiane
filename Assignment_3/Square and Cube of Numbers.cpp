#include <iostream>
#include <iomanip> // For formatting output

int main() {
    int limit;

    // Prompt the user for the upper limit
    std::cout << "Enter a number: ";
    std::cin >> limit;

    // Print the table header
    std::cout << "Number" << std::setw(10) << "Square" << std::setw(10) << "Cube" << std::endl;

    // Loop through numbers from 1 to the given limit
    for (int i = 1; i <= limit; ++i) {
        int square = i * i;
        int cube = i * i * i;
        std::cout << std::setw(6) << i << std::setw(10) << square << std::setw(10) << cube << std::endl;
    }

    return 0;
}
