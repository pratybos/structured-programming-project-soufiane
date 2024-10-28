#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(0)));
    int target = std::rand() % 100 + 1; // Random number between 1 and 100

    int guess;
    int attempts = 0;

    std::cout << "I have selected a number between 1 and 100. Try to guess it!" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > target) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (guess < target) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
        }
    } while (guess != target);

    return 0;
}
