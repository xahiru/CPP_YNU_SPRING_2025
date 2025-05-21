#include <iostream>
#include <string>

std::string sliceString(const std::string& s) {
    // Return a substring containing all characters except first and last
    // The length of s will be greater than 2, so s.substr(1, s.length() - 2) is safe.
    return s.substr(1, s.length() - 2);
}

int main() {
    std::string s1 = "Hello";
    std::cout << "Input: s = \"" << s1 << "\"" << std::endl;
    std::cout << "Output: " << sliceString(s1) << std::endl; 

    std::string s2 = "World";
    std::cout << "Input: s = \"" << s2 << "\"" << std::endl;
    std::cout << "Output: " << sliceString(s2) << std::endl;

    return 0;
}