/*#include <iostream>
using namespace std;

int main() {
    int year;

    // Get the year from the user
    cout << "Enter a year: ";
    cin >> year;

    // Determine if the year is a leap year
    bool is_leap_year = false;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                is_leap_year = true;
            }
        } else {
            is_leap_year = true;
        }
    }

    // Output the result
    if (is_leap_year) {
        cout << year << " is a leap year." << endl;
    } else {
        cout << year << " is not a leap year." << endl;
    }

    return 0;
}
