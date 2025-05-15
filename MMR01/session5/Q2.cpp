#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    // Input the size of the matrix
    cout << "Input an integer value: ";
    cin >> n;

    // Create an n x n matrix and fill it with the value of n
    vector<vector<int>> matrix(n, vector<int>(n, n));

    // Output the created matrix
    cout << "Create an n x n matrix by said integer:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl; // New line after each row
    }

    return 0;
}