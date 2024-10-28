/* #include <iostream>
#include <iomanip>
int main() {

    const double USD_TO_EURO = 0.85;
    const double USD_TO_YEN = 109.57;
    const double USD_TO_POUND = 0.73;


    double usdAmount;

    // Prompt the user to enter the amount in USD
    std::cout << "Enter the amount in US Dollars (USD): ";
    std::cin >> usdAmount;

    // Convert to each currency
    double euros = usdAmount * USD_TO_EURO;
    double yen = usdAmount * USD_TO_YEN;
    double pounds = usdAmount * USD_TO_POUND;

    // Display results with 2 decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nEquivalent amount in various currencies:\n";
    std::cout << "Euros: " << euros << " EUR\n";
    std::cout << "Yen: " << yen << " JPY\n";
    std::cout << "Pounds: " << pounds << " GBP\n";

    return 0;
}
