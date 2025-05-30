#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, value;
    cout << "Enter the size of the matrix (n): ";
    cin >> n;
    cout << "Enter the integer value to fill the matrix: ";
    cin >> value;
    
    // Create and fill an n x n matrix with the given value
    vector<vector<int>> matrix(n, vector<int>(n, value));
    
    // Display the matrix
    cout << "\nThe " << n << "x" << n << " matrix is:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}