#include <iostream>
#include <cstring> // For strcpy, strcat, strlen
#include <cctype> // For toupper

using namespace std;

char* appendString(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Allocate memory for the combined string
    char* result = new char[len1 + len2 + 1]; // +1 for the null terminator

    // Copy and concatenate strings
    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

void toUpperCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    // Input the first string
    cout << "Enter a string: ";
    string input1;
    getline(cin, input1);

    // Input the second string to append
    cout << "Enter a string to append: ";
    string input2;
    getline(cin, input2);

    // Convert input strings to C-style strings for dynamic memory allocation
    char* str1 = new char[input1.length() + 1];
    char* str2 = new char[input2.length() + 1];
    strcpy(str1, input1.c_str());
    strcpy(str2, input2.c_str());

    // Append strings and calculate new length
    char* modifiedString = appendString(str1, str2);
    int length = strlen(modifiedString);

    // Convert to uppercase
    toUpperCase(modifiedString);

    // Display results
    cout << "\nModified String: " << modifiedString << endl;
    cout << "Length of String: " << length << endl;

    // Free allocated memory
    delete[] str1;
    delete[] str2;
    delete[] modifiedString;

    return 0;
}
