#include <iostream>

void printAlphabets(char c1, char c2) {
    // Loop from c1 to c2 and print each character with a space
    for (char c = c1; c <= c2; ++c) {
        std::cout << c << " ";
    }
    // No new line after printing 
}

int main() {
    char c1_1 = 'a';
    char c2_1 = 'z';
    std::cout << "Input: c1 = '" << c1_1 << "', c2 = '" << c2_1 << "'" << std::endl;
    std::cout << "Output: ";
    printAlphabets(c1_1, c2_1); 
    std::cout << std::endl; // Add a newline for the next example

    char c1_2 = 'h';
    char c2_2 = 'u';
    std::cout << "Input: c1 = '" << c1_2 << "', c2 = '" << c2_2 << "'" << std::endl;
    std::cout << "Output: ";
    printAlphabets(c1_2, c2_2); 
    std::cout << std::endl;

    return 0;
}