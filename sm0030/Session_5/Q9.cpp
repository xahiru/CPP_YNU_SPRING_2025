#include <iostream>
#include <iomanip> // For std::setw

int main() {
    int n;
    std::cout << "Input the number upto: ";
    std::cin >> n;

    std::cout << "Multiplication table from 1 to " << n << std::endl;

    for (int i = 1; i <= 10; ++i) { // Loop for rows (multipliers 1 to 10)
        for (int j = 1; j <= n; ++j) { // Loop for columns (numbers 1 to n)
            std::cout << std::setw(2) << j << "x" << i << "=" << std::setw(2) << j * i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}