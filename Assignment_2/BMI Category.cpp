/*#include <iostream>
#include <iomanip> // for std::setprecision

int main() {
    // Variables to hold weight and height
    double weight, height, bmi;

    // Prompt user for input
    std::cout << "BMI Calculator\n";
    std::cout << "Enter your weight in kilograms: ";
    std::cin >> weight;
    std::cout << "Enter your height in meters: ";
    std::cin >> height;

    // Calculate BMI
    bmi = weight / (height * height);

    // Output BMI with precision
    std::cout << std::fixed << std::setprecision(2); // Set precision to 2 decimal places
    std::cout << "Your BMI is: " << bmi << std::endl;

    // Classify and display the category
    if (bmi < 18.5) {
        std::cout << "Category: Underweight" << std::endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        std::cout << "Category: Normal weight" << std::endl;
    } else if (bmi >= 25 && bmi < 29.9) {
        std::cout << "Category: Overweight" << std::endl;
    } else {
        std::cout << "Category: Obese" << std::endl;
    }

    return 0;
}
