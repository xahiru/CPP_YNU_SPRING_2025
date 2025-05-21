#include <iostream>
#include <vector>

using namespace std;

vector
<vector<int>> rotateMatrixClockwise(vector<vector<int>> matrix, int k) 
{
    if (matrix.empty()) 
    
    return matrix;
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    for (int rotation = 0; rotation < k; rotation++) {
        vector<vector<int>> rotated(rows, vector<int>(cols, 0));
        
        for (int layer = 0; layer < min(rows, cols) / 2; layer++) {
            int top = layer;
            int bottom = rows - 1 - layer;
            int left = layer;
            int right = cols - 1 - layer;
            
            // Rotate top row (move left to right)
            for (int i = left; i < right; i++) {
                rotated[top][i + 1] = matrix[top][i];
            }
            
            // Rotate right column (move top to bottom)
            for (int i = top; i < bottom; i++) {
                rotated[i + 1][right] = matrix[i][right];
            }
            
            // Rotate bottom row (move right to left)
            for (int i = right; i > left; i--) {
                rotated[bottom][i - 1] = matrix[bottom][i];
            }
            
            // Rotate left column (move bottom to top)
            for (int i = bottom; i > top; i--) {
                rotated[i - 1][left] = matrix[i][left];
            }
        }
        
        matrix = rotated;
    }
    
    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    vector
    <vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int k = 2;
    
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    
    vector<vector<int>> rotated = rotateMatrixClockwise(matrix, k);
    
    cout << "Matrix after " << k << " clockwise rotations:" << endl;
    printMatrix(rotated);
    
    return 0;
}