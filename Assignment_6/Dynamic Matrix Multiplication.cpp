#include <iostream>
using namespace std;

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Input dimensions for Matrix A
    cout << "Enter dimensions for Matrix A (rows columns): ";
    cin >> rowsA >> colsA;

    // Input dimensions for Matrix B
    cout << "Enter dimensions for Matrix B (rows columns): ";
    cin >> rowsB >> colsB;

    // Ensure the matrices can be multiplied
    if (colsA != rowsB) {
        cout << "Error: Matrix multiplication not possible with these dimensions." << endl;
        return 1;
    }

    // Dynamically allocate Matrix A
    int** A = new int*[rowsA];
    for (int i = 0; i < rowsA; i++)
        A[i] = new int[colsA];

    // Dynamically allocate Matrix B
    int** B = new int*[rowsB];
    for (int i = 0; i < rowsB; i++)
        B[i] = new int[colsB];

    // Input elements for Matrix A
    cout << "Enter elements for Matrix A:" << endl;
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++)
            cin >> A[i][j];

    // Input elements for Matrix B
    cout << "Enter elements for Matrix B:" << endl;
    for (int i = 0; i < rowsB; i++)
        for (int j = 0; j < colsB; j++)
            cin >> B[i][j];

    // Dynamically allocate the Resulting Matrix
    int** C = new int*[rowsA];
    for (int i = 0; i < rowsA; i++)
        C[i] = new int[colsB];

    // Initialize the Resulting Matrix
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++)
            C[i][j] = 0;

    // Perform matrix multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Output the Resulting Matrix
    cout << "Resulting Matrix:" << endl;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < rowsA; i++) delete[] A[i];
    delete[] A;

    for (int i = 0; i < rowsB; i++) delete[] B[i];
    delete[] B;

    for (int i = 0; i < rowsA; i++) delete[] C[i];
    delete[] C;

    return 0;
}
