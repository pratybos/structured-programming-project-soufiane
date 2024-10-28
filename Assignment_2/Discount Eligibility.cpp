/*#include <iostream>
#include <iomanip> // for std::setprecision

int main() {
    // Variables to hold the original price, discount, and final price
    double originalPrice, discount = 0.0, finalPrice;

    // Prompt user for the original price
    std::cout << "Enter the original price of the product: $";
    std::cin >> originalPrice;

    // Check if the price is eligible for a discount
    if (originalPrice > 100) {
        discount = originalPrice * 0.10; // Calculate 10% discount
    }

    // Calculate the final price
    finalPrice = originalPrice - discount;

    // Output the results with precision
    std::cout << std::fixed << std::setprecision(2); // Set precision to 2 decimal places
    std::cout << "Original Price: $" << originalPrice << std::endl;
    std::cout << "Discount Amount: $" << discount << std::endl;
    std::cout << "Final Price: $" << finalPrice << std::endl;

    return 0;
}
