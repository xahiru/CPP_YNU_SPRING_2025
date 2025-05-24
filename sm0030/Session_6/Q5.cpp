#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

std::string reverseString(std::string s) {
    // Reverse the string using std::reverse
    std::reverse(s.begin(), s.end());
    return s;
}

int main() {
    std::string s1 = "Hello";
    std::cout << "Input: s = \"" << s1 << "\"" << std::endl;
    std::cout << "Output: \"" << reverseString(s1) << "\"" << std::endl; 

    std::string s2 = "World";
    std::cout << "Input: s = \"" << s2 << "\"" << std::endl;
    std::cout << "Output: \"" << reverseString(s2) << "\"" << std::endl; 

    return 0;
}