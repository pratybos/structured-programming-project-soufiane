/*#include <iostream>
using namespace std;

int main() {
    int age;
    string age_group;

    // Get the person's age
    cout << "Enter your age: ";
    cin >> age;

    // Determine the age group
    if (age >= 0 && age <= 12) {
        age_group = "Child";
    } else if (age >= 13 && age <= 19) {
        age_group = "Teenager";
    } else if (age >= 20 && age <= 64) {
        age_group = "Adult";
    } else if (age >= 65) {
        age_group = "Senior";
    } else {
        cout << "Invalid age entered." << endl;
        return 1; // Exit the program if the age is invalid
    }

    // Output the age group
    cout << "Age group: " << age_group << endl;

    return 0;
}
10