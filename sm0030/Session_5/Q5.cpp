#include <iostream>
#include <string>
#include <set>
#include <algorithm>

bool verifyLetters(const std::string& first, const std::string& second) {
    std::set<char> first_chars;
    for (char c : first) {
        first_chars.insert(c);
    }

    for (char c : second) {
        if (first_chars.find(c) == first_chars.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str1 = "programming";
    std::string str2 = "gra";
    std::cout << "Does all letters of \"" << str2 << "\" appear in \"" << str1 << "\"? " << (verifyLetters(str1, str2) ? "true" : "false") << std::endl;

    str1 = "hello";
    str2 = "world";
    std::cout << "Does all letters of \"" << str2 << "\" appear in \"" << str1 << "\"? " << (verifyLetters(str1, str2) ? "true" : "false") << std::endl;

    return 0;
}