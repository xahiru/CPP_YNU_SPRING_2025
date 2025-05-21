#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Get matrix dimensions from user
    cout << "Rows: ";
    cin >> rows;
    cout << "Columns: ";
    cin >> cols;

    // Validate input
    if (rows <= 0 || cols <= 0) {
        cout << "Invalid dimensions. Please enter positive integers." << endl;
        return 1;
    }

    // Dynamically allocate 2D array
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Fill matrix with sequential numbers
    int counter = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = counter++;
        }
    }

    // Display the matrix
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}