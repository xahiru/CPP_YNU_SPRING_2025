#include <iostream>
#include <vector>
using namespace std;

void rotateMatrixClockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int layer = 0; layer < n / 2; ++layer) {
        int first = layer;
        int last = n - layer - 1;
        for (int i = first; i < last; ++i) {
            int offset = i - first;
            int top = matrix[first][i]; // Save top
            // Left -> Top
            matrix[first][i] = matrix[last - offset][first];
            // Bottom -> Left
            matrix[last - offset][first] = matrix[last][last - offset];
            // Right -> Bottom
            matrix[last][last - offset] = matrix[i][last];
            // Top -> Right
            matrix[i][last] = top; // Assign saved top to right
        }
    }
}

int main() {
vector<vector<int>> matrix = {
{1, 2, 3},
{4, 5, 6},
{7, 8, 9}
};

int k = 1; // Number of rotations
for (int i = 0; i < k; ++i) {
rotateMatrixClockwise(matrix);
}

cout << "Rotated Matrix:" << endl;
for (const auto& row : matrix) {
for (const auto& elem : row) {
    cout << elem << " ";
}
cout << endl;
}

return 0;
}
