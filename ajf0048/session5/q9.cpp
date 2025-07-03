#include <iostream>

void printAlphabets(char c1, char c2) {
    // Ensure c1 is less than or equal to c2
    if (c1 > c2) {
        std::cout << "Invalid range: c1 should be less than or equal to c2." << std::endl;
        return;
    }

    for (char c = c1; c <= c2; ++c) {
        std::cout << c << " "; // Print each character followed by a space
    }
}

int main() {
    // Example 1
    char c1 = 'a', c2 = 'z';
    printAlphabets(c1, c2); // Output: a b c d e f g h i j k l m n o p q r s t u v w x y z 

    std::cout << std::endl; // New line for better output formatting

    // Example 2
    c1 = 'h', c2 = 'u';
    printAlphabets(c1, c2); // Output: h i j k l m n o p q r s t u 

    return 0;
}