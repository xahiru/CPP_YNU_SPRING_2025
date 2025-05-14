#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Input number of rows and columns
    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    // Dynamically allocate a 2D matrix
    int** matrix = new int*[rows];  // Allocate memory for rows

    // For each row, allocate memory for columns
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Fill the matrix with sequential numbers
    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = value++;
        }
    }

    // Display the matrix
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate the memory for the matrix
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];  // Deallocate each row
    }
    delete[] matrix;  // Deallocate the matrix

    return 0;
}
