/*#include <iostream>
using namespace std;

int main() {
    int total_minutes, days, hours, minutes;

    // Get the time duration in minutes from the user
    cout << "Enter the time duration in minutes: ";
    cin >> total_minutes;

    // Convert minutes to days
    days = total_minutes / (24 * 60);

    // Get the remaining minutes after calculating days
    int remaining_minutes = total_minutes % (24 * 60);

    // Convert the remaining minutes to hours
    hours = remaining_minutes / 60;

    // Get the remaining minutes after calculating hours
    minutes = remaining_minutes % 60;

    // Output the result
    cout << days << " days, " << hours << " hours, " << minutes << " minutes" << endl;

    return 0;
}
