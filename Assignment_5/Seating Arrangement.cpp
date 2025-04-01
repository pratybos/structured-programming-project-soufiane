#include <iostream>
#include <iomanip>
#include <vector>

const int ROWS = 10;
const int COLS = 10;

void displaySeating(const std::vector<std::vector<int>>& seats) {
    int available = 0, reserved = 0;

    std::cout << "\nCurrent Seating Arrangement:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << seats[i][j] << " ";
            if (seats[i][j] == 0) {
                available++;
            } else {
                reserved++;
            }
        }
        std::cout << "\n";
    }
    std::cout << "\nAvailable: " << available << ", Reserved: " << reserved << "\n";
}

void reserveSeat(std::vector<std::vector<int>>& seats) {
    int row, col;
    std::cout << "\nEnter row and column to reserve (0-9): ";
    std::cin >> row >> col;

    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (seats[row][col] == 0) {
            seats[row][col] = 1;
            std::cout << "Seat reserved successfully.\n";
        } else {
            std::cout << "Seat already reserved.\n";
        }
    } else {
        std::cout << "Invalid seat location.\n";
    }
}

void cancelReservation(std::vector<std::vector<int>>& seats) {
    int row, col;
    std::cout << "\nEnter row and column to cancel reservation (0-9): ";
    std::cin >> row >> col;

    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (seats[row][col] == 1) {
            seats[row][col] = 0;
            std::cout << "Reservation cancelled successfully.\n";
        } else {
            std::cout << "Seat is not reserved.\n";
        }
    } else {
        std::cout << "Invalid seat location.\n";
    }
}

int main() {
    std::vector<std::vector<int>> seats(ROWS, std::vector<int>(COLS, 0));
    int choice;

    while (true) {
        std::cout << "\n--- Theater Seating Management ---\n";
        std::cout << "1. Display Seating Arrangement\n";
        std::cout << "2. Reserve a Seat\n";
        std::cout << "3. Cancel a Reservation\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displaySeating(seats);
                break;
            case 2:
                reserveSeat(seats);
                break;
            case 3:
                cancelReservation(seats);
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
