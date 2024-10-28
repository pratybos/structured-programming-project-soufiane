/*#include <iostream>
#include <iomanip>

int main() {
    // Variables to hold scores for assessments
    double homeworkScore, midtermScore, finalExamScore;
    double finalGrade;

    // Prompt user for input scores
    std::cout << "Enter your homework score (out of 100): ";
    std::cin >> homeworkScore;

    std::cout << "Enter your midterm score (out of 100): ";
    std::cin >> midtermScore;

    std::cout << "Enter your final exam score (out of 100): ";
    std::cin >> finalExamScore;

    // Calculate the final grade based on the weighted average
    finalGrade = (homeworkScore * 0.4) + (midtermScore * 0.3) + (finalExamScore * 0.3);

    // Output the final grade with precision
    std::cout << std::fixed << std::setprecision(2); // Set precision to 2 decimal places
    std::cout << "Your final grade is: " << finalGrade << std::endl;

    // Determine if the final grade is passing
    if (finalGrade >= 60.0) {
        std::cout << "Congratulations! You have passed." << std::endl;
    } else {
        std::cout << "Unfortunately, you have not passed." << std::endl;
    }

    return 0;
}
