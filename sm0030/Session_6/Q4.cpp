#include <iostream>
#include <string>
#include <sstream>

int countWords(const std::string& s) {
    // Use stringstream to easily count words
    std::stringstream ss(s);
    std::string word;
    int count = 0;
    while (ss >> word) {
        count++;
    }
    return count;
}

int main() {
    std::string s1 = "Yunnan";
    std::cout << "Input: s = \"" << s1 << "\"" << std::endl;
    std::cout << "Output: " << countWords(s1) << std::endl; 
    std::string s2 = "World is hello";
    std::cout << "Input: s = \"" << s2 << "\"" << std::endl;
    std::cout << "Output: " << countWords(s2) << std::endl; 
    return 0;
}