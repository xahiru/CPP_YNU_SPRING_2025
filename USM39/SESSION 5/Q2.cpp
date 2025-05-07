#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Input an integer value: ";
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, n));
    
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
