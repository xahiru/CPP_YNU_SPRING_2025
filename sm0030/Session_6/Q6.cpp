#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cout << "Enter a string with multiple words: " << std::endl;
    // Use std::getline to read a line with spaces
    std::getline(std::cin, s);
    std::cout << "Output: " << s << std::endl;

    return 0;
}