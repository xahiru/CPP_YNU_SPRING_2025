#include <iostream>
#include <string>

void findPattern(const std::string& text, const std::string& pattern) {
    size_t pos = text.find(pattern);
    while (pos != std::string::npos) {
        std::cout << "Pattern found at " << pos << std::endl;
        pos = text.find(pattern, pos + 1);
    }
}

int main() {
    std::string text = "heisahe";
    std::string pattern = "he";
    findPattern(text, pattern);
    return 0;
}
