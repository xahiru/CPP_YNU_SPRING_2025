#include <iostream>
#include <string>

int findPattern(const std::string& s, const std::string& p) {
    // Find the first occurrence of pattern p in string s
    size_t found = s.find(p);
    if (found != std::string::npos) {
        return static_cast<int>(found);
    } else {
        return -1;
    }
}

int main() {
    std::string s1 = "Hello";
    std::string p1 = "llo";
    std::cout << "Input: s = \"" << s1 << "\", p = \"" << p1 << "\"" << std::endl;
    std::cout << "Output: " << findPattern(s1, p1) << std::endl; 

    std::string s2 = "World";
    std::string p2 = "Doodle";
    std::cout << "Input: s = \"" << s2 << "\", p = \"" << p2 << "\"" << std::endl;
    std::cout << "Output: " << findPattern(s2, p2) << std::endl; 

    return 0;
}