#include <iostream>
#include <string>
#include <unordered_map>

char findExtraChar(const std::string& s1, const std::string& s2) {
    std::unordered_map<char, int> charCount;
    for (char c : s1) charCount[c]++;
    for (char c : s2) {
        if (charCount[c] == 0) return c;
        charCount[c]--;
    }
    return '\0';
}

int main() {
    std::string s1 = "abcd";
    std::string s2 = "abecd";
    std::cout << "Extra Character: " << findExtraChar(s1, s2) << std::endl;
    return 0;
}
