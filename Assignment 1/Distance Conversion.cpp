/*#include <iostream>
using namespace std;

int main() {
    double kilometers, miles, feet, inches;

    // Get distance in kilometers from user
    cout << "Enter the distance in kilometers: ";
    cin >> kilometers;

    // Convert kilometers to miles
    miles = kilometers * 0.621371;

    // Convert miles to feet
    feet = miles * 5280;

    // Convert feet to inches
    inches = feet * 12;

    // Output the results
    cout << "Distance in miles: " << miles << " miles" << endl;
    cout << "Distance in feet: " << feet << " feet" << endl;
    cout << "Distance in inches: " << inches << " inches" << endl;

    return 0;
}
