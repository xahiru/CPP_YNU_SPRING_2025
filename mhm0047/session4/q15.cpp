#include <iostream>
#include <vector>
using namespace std;

// Rotate matrix by 90 degrees clockwise and store in new matrix
vector<vector<int>> rotateOnce(const vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> rotated(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[j][n - 1 - i] = mat[i][j];
        }
    }
    return rotated;
}

// Rotate matrix K times using the helper function
vector<vector<int>> rotateK(const vector<vector<int>>& mat, int k) {
    k %= 4;
    vector<vector<int>> result = mat;

    while (k--) {
        result = rotateOnce(result);
    }

    return result;
}

// Print matrix
void display(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
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

    vector<vector<int>> rotatedMatrix = rotateK(matrix, K);

    cout << "Matrix after " << K << " clockwise rotations:\n";
    display(rotatedMatrix);

    return 0;
}
