/*#include <iostream>
#include <string>
using namespace std;

// Function to calculate BMI and return the category as a string
string calculateBMI(double weight_lbs, double height_in) {
    // Convert weight from pounds to kilograms (1 pound = 0.453592 kg)
    double weight_kg = weight_lbs * 0.453592;
    // Convert height from inches to meters (1 inch = 0.0254 meters)
    double height_m = height_in * 0.0254;
    // Calculate BMI
    double bmi = weight_kg / (height_m * height_m);

    // Determine BMI category
    string category;
    if (bmi < 18.5) {
        category = "Underweight";
    } else if (bmi >= 18.5 && bmi < 24.9) {
        category = "Normal weight";
    } else if (bmi >= 25 && bmi < 29.9) {
        category = "Overweight";
    } else {
        category = "Obese";
    }

    // Output the BMI and category
    cout << "Your BMI is: " << bmi << endl;
    cout << "BMI Category: " << category << endl;

    return category;
}

int main() {
    double weight_lbs, height_in;

    // Get user input
    cout << "Enter your weight in pounds: ";
    cin >> weight_lbs;
    cout << "Enter your height in inches: ";
    cin >> height_in;

    // Calculate BMI and display category
    calculateBMI(weight_lbs, height_in);

    return 0;
}
