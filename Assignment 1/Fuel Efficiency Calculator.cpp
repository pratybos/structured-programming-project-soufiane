/*#include <iostream>
#include <iomanip>

int main() {
    // Variable to store fuel efficiency in MPG
    double mpg;

    // Prompt the user to enter fuel efficiency in MPG
    std::cout << "Enter fuel efficiency in miles per gallon (MPG): ";
    std::cin >> mpg;

    // Conversion from MPG to L/100km
    double litersPer100km = 235.215 / mpg;

    // Display result with 2 decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Equivalent fuel efficiency is: " << litersPer100km << " L/100km\n";

    return 0;
}
