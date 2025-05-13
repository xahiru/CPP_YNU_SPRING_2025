#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void rotateMatrixClockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << "\t";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int K = 2; 
    
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    
    K = K % 4;
    
    for (int i = 0; i < K; i++) {
        rotateMatrixClockwise(matrix);
    }
    
    cout << "\nMatrix after " << K << " clockwise rotation(s):" << endl;
    printMatrix(matrix);
    
    return 0;
}