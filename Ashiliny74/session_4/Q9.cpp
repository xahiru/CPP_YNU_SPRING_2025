#include <iostream>

int main() {
    int n;

    // Prompt for user input
    std::cout << "Input the number up to: ";
    std::cin >> n;

    // Display the multiplication table
    std::cout << "Multiplication table from 1 to " << n << std::endl;

    // Loop through each multiplier
    for (int i = 1; i <= n; ++i) {
        // Loop through each number to be multiplied
        for (int j = 1; j <= n; ++j) {
            std::cout << j << "x" << i << "=" << j * i; // Output each multiplication
            if (j != n) // Prevent additional space at end of line
                std::cout << " "; 
        }
        std::cout << std::endl; // Move to the next line after each multiplier
    }

    return 0;
}