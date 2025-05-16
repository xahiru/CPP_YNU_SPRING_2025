#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    
    // Fill matrix with value n
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = n;
        }
    }
    
    // Print matrix
    cout << "Create an n x n matrix by said integer:\n";
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}