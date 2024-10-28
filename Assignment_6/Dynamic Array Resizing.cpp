#include <iostream>
using namespace std;

int main() {
    int initialSize, newSize;

    // Input initial size of the array
    cout << "Enter initial size of array: ";
    cin >> initialSize;

    // Dynamically allocate array with initial size
    int* array = new int[initialSize];

    // Input elements for the initial array
    cout << "Enter elements: ";
    for (int i = 0; i < initialSize; i++) {
        cin >> array[i];
    }

    // Display the original array
    cout << "Original Array: ";
    for (int i = 0; i < initialSize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Input new size of the array
    cout << "Enter new size of array: ";
    cin >> newSize;

    // Dynamically allocate a new array with the new size
    int* newArray = new int[newSize];

    // Copy existing elements to the new array
    for (int i = 0; i < initialSize; i++) {
        newArray[i] = array[i];
    }

    // Input additional elements if the new size is larger
    if (newSize > initialSize) {
        cout << "Enter additional elements: ";
        for (int i = initialSize; i < newSize; i++) {
            cin >> newArray[i];
        }
    }

    // Display the resized array
    cout << "Resized Array: ";
    for (int i = 0; i < newSize; i++) {
        cout << newArray[i] << " ";
    }
    cout << endl;

    // Free dynamically allocated memory
    delete[] array;
    delete[] newArray;

    return 0;
}
