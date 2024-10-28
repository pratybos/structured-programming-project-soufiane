/*#include <iostream>
using namespace std;

int main() {
    int score;
    char grade;
    string message;

    // Get the student's score
    cout << "Enter the student's score (0-100): ";
    cin >> score;

    // Validate score range
    if (score < 0 || score > 100) {
        cout << "Invalid score. Please enter a value between 0 and 100." << endl;
        return 1;  // Exit the program
    }

    // Determine the grade and message
    if (score >= 90) {
        grade = 'A';
        message = "Excellent work!";
    } else if (score >= 80) {
        grade = 'B';
        message = "Good job!";
    } else if (score >= 70) {
        grade = 'C';
        message = "Satisfactory performance.";
    } else if (score >= 60) {
        grade = 'D';
        message = "Needs improvement.";
    } else {
        grade = 'F';
        message = "Unsatisfactory. Please seek help to improve.";
    }

    // Output the grade and message
    cout << "Grade: " << grade << endl;
    cout << "Message: " << message << endl;

    return 0;
}
