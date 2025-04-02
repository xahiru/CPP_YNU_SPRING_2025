#include <iostream>

int main() {
    char ch;
    
    std::cout << "Enter a character: ";
    std::cin >> ch;
    
    std::cout << "ASCII Value of '" << ch << "' = " << int(ch) << std::endl;

    return 0;
}