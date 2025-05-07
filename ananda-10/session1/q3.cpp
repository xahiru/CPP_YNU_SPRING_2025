#include <iostream>

int main() {
    char character;
    
    std::cout << "Enter a character:";
    std::cin >> character;
    std::cout << "ASCII Value of '" << character << "' = " << int(character) << std::endl;
    
    return 0;
}
