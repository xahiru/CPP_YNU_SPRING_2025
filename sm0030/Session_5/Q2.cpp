#include <iostream> 
#include <vector> 

int main() {
    int n; 
    std::cout << "Input: "; 
    std::cin >> n; 

    // Create an n x n matrix using std::vector of std::vectors
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

    // Fill the matrix with the input value n
    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < n; ++j) { 
            matrix[i][j] = n; 
    }

    std::cout << "Create an n x n matrix by said integer:" << std::endl; 
    // Print the matrix
    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < n; ++j) { 
            std::cout << matrix[i][j] << " "; 
        }
        std::cout << std::endl; 
    }

    return 0; 
}