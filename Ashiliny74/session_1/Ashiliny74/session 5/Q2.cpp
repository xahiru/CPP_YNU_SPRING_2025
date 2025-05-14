#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    // Get the size of the matrix from the user
    cout << "Input an integer value (n): ";
    cin >> n;

    // Create an n x n matrix using a vector of vectors
    vector<vector<int>> matrix(n, vector<int>(n));

    // Input values for the matrix
    cout << "Create an n x n matrix by said integer:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter value for matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Display the matrix
    cout << "The n x n matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}