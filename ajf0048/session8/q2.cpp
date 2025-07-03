#include <iostream>
#include <vector>

bool multiplyMatrices(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2, const std::vector<std::vector<int>>& res) {
    int n = mat1.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result == res;
}

int main() {
    std::vector<std::vector<int>> mat1 = {{1, 2, 3, 4}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    std::vector<std::vector<int>> mat2 = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    std::vector<std::vector<int>> res = {{1, 2, 3, 4}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

    if (multiplyMatrices(mat1, mat2, res)) {
        std::cout << "The result is correct." << std::endl;
    } else {
        std::cout << "The result is incorrect." << std::endl;
    }

    return 0;
}