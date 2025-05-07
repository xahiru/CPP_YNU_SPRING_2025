#include <iostream>

int main() {
    int n;
    std::cout << "Input the number up to: ";
    std::cin >> n;
    
    std::cout << "Multiplication table from 1 to " << n << std::endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << j << "x" << i << "=" << j * i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
