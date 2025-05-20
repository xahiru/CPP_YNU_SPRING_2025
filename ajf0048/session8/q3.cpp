#include <iostream>
#include <vector>

int diagonalSum(const std::vector<std::vector<int>>& mat) {
    int n = mat.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += mat[i][i]; // Main diagonal
        sum += mat[i][n - 1 - i]; // Secondary diagonal
    }
    return sum;
}

int main() {
    std::vector<std::vector<int>> mat = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};
    std::cout << "Diagonal Sum: " << diagonalSum(mat) << std::endl;
    return 0;
}