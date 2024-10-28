/*#include <iostream>
#include <cmath>  // For the pow function
using namespace std;

int main() {
    double loan_amount, annual_interest_rate, loan_term_years;
    double monthly_payment;

    // Get loan details from user
    cout << "Enter the loan amount: ";
    cin >> loan_amount;

    cout << "Enter the annual interest rate (in %): ";
    cin >> annual_interest_rate;

    cout << "Enter the loan term in years: ";
    cin >> loan_term_years;

    // Convert annual interest rate to monthly and percentage to decimal
    double monthly_interest_rate = (annual_interest_rate / 100) / 12;

    // Calculate the number of monthly payments
    int num_payments = loan_term_years * 12;

    // Calculate the monthly payment using the formula
    monthly_payment = loan_amount * monthly_interest_rate * pow(1 + monthly_interest_rate, num_payments) /
                      (pow(1 + monthly_interest_rate, num_payments) - 1);

    // Output the result
    cout << "The monthly payment is: $" << monthly_payment << endl;

    return 0;
}
