#include <iostream>
#include <string>
#include <unordered_set>

bool verifyLetters(const std::string& first, const std::string& second) {
    std::unordered_set<char> firstChars;
    
    for (char c : first) {
        firstChars.insert(tolower(c));
    }
    
    for (char c : second) {
        if (firstChars.find(tolower(c)) == firstChars.end()) {
            return false;
        }
    }
    
    return true;
}

int main() {
    std::string first = "Programming";
    std::string second = "gram";
    
    bool result = verifyLetters(first, second);
    std::cout << (result ? "true" : "false") << std::endl;
    
    return 0;
}
