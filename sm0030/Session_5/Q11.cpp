#include <iostream>

int main() {
    int num_letters;
    std::cout << "Input the number of Letters (less than 26) in the Pyramid: ";
    std::cin >> num_letters;

    if (num_letters >= 26 || num_letters <= 0) {
        std::cout << "Please enter a number of letters between 1 and 25." << std::endl;
        return 1;
    }

    for (int i = 0; i < num_letters; ++i) { // Outer loop for rows
        // Print leading spaces
        for (int j = 0; j < num_letters - 1 - i; ++j) {
            std::cout << "  "; // Two spaces for alignment
        }

        // Print ascending part of the pyramid (A, B, C...)
        for (int j = 0; j <= i; ++j) {
            std::cout << static_cast<char>('A' + j) << " ";
        }

        // Print descending part of the pyramid (C, B, A...)
        for (int j = i - 1; j >= 0; --j) {
            std::cout << static_cast<char>('A' + j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}