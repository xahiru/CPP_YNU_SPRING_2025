#include <iostream>
#include <string>

int getStringLength(const std::string& s) {
    // Return the length of the string
    return s.length();
}

int main() {
    std::string s1 = "Yunnan";
    std::cout << "Input: s = " << s1 << std::endl;
    std::cout << "Output: " << getStringLength(s1) << std::endl; 

    std::string s2 = "Hello1234";
    std::cout << "Input: s = " << s2 << std::endl;
    std::cout << "Output: " << getStringLength(s2) << std::endl; 

    return 0;
}