#include <iostream>
#include <string>

int main() {
    std::string input;

    // Prompt the user for input
    std::cout << "Enter a string: ";
    std::cin >> input;

    // Reverse the string by swapping characters
    int n = input.length();
    for (int i = 0; i < n / 2; ++i) {
        // Swap the characters at positions i and (n - i - 1)
        char temp = input[i];
        input[i] = input[n - i - 1];
        input[n - i - 1] = temp;
    }

    // Display the reversed string
    std::cout << "Reversed string: " << input << std::endl;

    return 0;
}
