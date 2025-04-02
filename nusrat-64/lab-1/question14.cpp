#include <iostream>

int main() {
    int rows;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    for (int i = rows; i > 0; i--) { 
        for (int j = 0; j < rows - i; j++) {
            std::cout << " ";
        }
        for (int k = 0; k < (2 * i - 1); k++) {
            std::cout << "*"; 
        }
        std::cout << std::endl;
    }

    return 0;
}