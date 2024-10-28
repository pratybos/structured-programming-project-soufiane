#include <iostream>

using namespace std;

int main() {
    int numArrays;

    // the number of arrays
    cout << "Enter the number of arrays: ";
    cin >> numArrays;

    // Create an array of pointers
    int** arrays = new int*[numArrays];
    int* sizes = new int[numArrays];  // To store the size of each array

    // Input the size of each array and allocate memory for each array
    for (int i = 0; i < numArrays; i++) {
        cout << "size of each array " << i + 1 << ": ";
        cin >> sizes[i];

        arrays[i] = new int[sizes[i]];  // Allocate memory for each array

        // Input values for each element of the array
        cout << "Enter " << sizes[i] << " elements for array " << i + 1 << ": ";
        for (int j = 0; j < sizes[i]; j++) {
            cin >> arrays[i][j];
        }
    }

    // Display each array and calculate its sum
    cout << "\nArray Contents and Sums:" << endl;
    for (int i = 0; i < numArrays; i++) {
        int sum = 0;
        cout << "Array " << i + 1 << ": ";
        for (int j = 0; j < sizes[i]; j++) {
            cout << arrays[i][j] << " ";
            sum += arrays[i][j];
        }
        cout << "\nSum of Array " << i + 1 << ": " << sum << endl;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < numArrays; i++) {
        delete[] arrays[i];  // Delete each array
    }
    delete[] arrays;  // Delete the array of pointers
    delete[] sizes;   // Delete the size array

    return 0;
}
