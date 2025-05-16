#include <iostream>
#include <string>

char findExtraChar(const std::string& s1, const std::string& s2) {
    int result = 0;
    
    for (char ch : s1)
        result ^= ch;
    
    for (char ch : s2)
        result ^= ch;
    
    return static_cast<char>(result);
}

int main() {
    std::string s1 = "abcd";
    std::string s2 = "abecd";

    char extra = findExtraChar(s1, s2);
    std::cout << "Extra Character: " << extra << std::endl;

    return 0;
}
