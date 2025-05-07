#include <iostream>

int main() {
    int rows, cols;
    std::cout << "Rows: ";
    std::cin >> rows;
    std::cout << "Columns: ";
    std::cin >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = value++;
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
