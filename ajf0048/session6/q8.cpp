#include <iostream>
#include <string>

void printSubstring(const std::string& s, int L, int R) {
    std::cout << s.substr(L, R - L + 1) << std::endl;
}

int main() {
    std::string s = "cdbkdub";
    printSubstring(s, 0, 5); // Output: cdbkdu

    s = "sdiblcsdbud";
    printSubstring(s, 3, 7); // Output: blcsd

    return 0;
}