#include <iostream>
#include <string>

int findPattern(const std::string& s, const std::string& p) {
    size_t pos = s.find(p);
    return (pos != std::string::npos) ? static_cast<int>(pos) : -1;
}

int main() {
    std::string s = "Hello", p = "llo";
    std::cout << findPattern(s, p) << std::endl; // Output: 2

    s = "World", p = "Doodle";
    std::cout << findPattern(s, p) << std::endl; // Output: -1

    return 0;
}