#include <iostream>
#include <string>
#include <unordered_set>

bool verifyLetters(const std::string& str1, const std::string& str2) {
    std::unordered_set<char> charSet(str1.begin(), str1.end());
    for (char ch : str2) {
        if (charSet.find(ch) == charSet.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str1 = "hello";
    std::string str2 = "ho";
    std::cout << (verifyLetters(str1, str2) ? "True" : "False") << std::endl;
    return 0;
}
