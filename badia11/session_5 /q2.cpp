#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Input: ";
    std::cin >> n;
    
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    
    std::cout << "Input an integer value: Create an n x n matrix by said integer:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = n;
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}
