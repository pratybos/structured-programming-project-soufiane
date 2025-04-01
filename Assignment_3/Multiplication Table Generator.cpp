#include <iostream>
#include <iomanip>

int main() {
    const int size = 10;

    // Print the header row
    std::cout << "    ";
    for (int i = 1; i <= size; ++i) {
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;

    // Print the multiplication table
    for (int row = 1; row <= size; ++row) {
        // Print the row header
        std::cout << std::setw(3) << row << " ";

        // Print the products in the row
        for (int col = 1; col <= size; ++col) {
            std::cout << std::setw(3) << row * col;
        }
        std::cout << std::endl;
    }

    return 0;
}
