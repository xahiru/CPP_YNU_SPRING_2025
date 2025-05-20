#include <iostream>
#include <vector>

void swapRows(std::vector<std::vector<int>>& mat, int row1, int row2) {
    std::swap(mat[row1], mat[row2]);
}

void swapColumns(std::vector<std::vector<int>>& mat, int col1, int col2) {
    int n = mat.size();
    for (int i = 0; i < n; ++i) {
        std::swap(mat[i][col1], mat[i][col2]);
    }
}

void middleSwap(std::vector<std::vector<int>>& mat) {
    swapRows(mat, 1, 2);
    swapColumns(mat, 1, 2);
}

void printMatrix(const std::vector<std::vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> mat = {{1, 2, 3, 4}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    std::cout << "Original Matrix:" << std::endl;
    printMatrix(mat);

    middleSwap(mat);
    std::cout << "Modified Matrix:" << std::endl;
    printMatrix(mat);

    return 0;
}