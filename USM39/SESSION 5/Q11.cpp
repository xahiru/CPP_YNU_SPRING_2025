#include <iostream>

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    
    int* squares = new int[n];
    for (int i = 0; i < n; ++i) {
        squares[i] = (i + 1) * (i + 1);
    }
    
    std::cout << "Squares: ";
    for (int i = 0; i < n; ++i) {
        std::cout << squares[i] << " ";
    }
    std::cout << std::endl;

    delete[] squares;
    return 0;
}
