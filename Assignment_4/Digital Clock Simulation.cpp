#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

void displayTime(int hours, int minutes) {
    // Display the time in HH:MM format
    std::cout << std::setw(2) << std::setfill('0') << hours << ":"
              << std::setw(2) << std::setfill('0') << minutes << "\r";
    std::cout.flush();
}

void updateClock(int &hours, int &minutes) {
    // Increment minutes and handle overflow to hours
    minutes++;
    if (minutes == 60) {
        minutes = 0;
        hours++;
        if (hours == 24) {
            hours = 0;
        }
    }
}

int main() {
    int hours = 0, minutes = 0;

    std::cout << "Digital Clock Simulation (Press Ctrl+C to stop)\n";

    while (true) {
        displayTime(hours, minutes);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        updateClock(hours, minutes);
    }

    return 0;
}
