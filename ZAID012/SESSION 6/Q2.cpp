#include <iostream>
#include <string>

std::string sliceString(const std::string &s) {
    return s.substr(1, s.length() - 2);
}

int main() {
    std::string s = "Hello";
    std::cout << sliceString(s) << std::endl;
    return 0;
}
