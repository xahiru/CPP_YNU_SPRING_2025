#include <iostream>
#include <vector>

void transposeMatrix(std::vector<std::vector<int>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(mat[i][j], mat[j][i]);
        }
    }
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
    std::vector<std::vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::cout << "Original Matrix:" << std::endl;
    printMatrix(mat);

    transposeMatrix(mat);
    std::cout << "Transposed Matrix:" << std::endl;
    printMatrix(mat);

    return 0;
}
