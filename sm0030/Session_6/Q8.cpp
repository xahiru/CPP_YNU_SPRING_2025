#include <iostream>
#include <string>

void printSubstring(const std::string& s, int L, int R) {
    // Print characters from index L to R (inclusive)
    // The length of the substring is (R - L + 1)
    std::cout << s.substr(L, R - L + 1) << std::endl;
}

int main() {
    std::string s1 = "cdbkdub";
    int L1 = 0;
    int R1 = 5;
    std::cout << "Input: s = \"" << s1 << "\", L = " << L1 << ", R = " << R1 << std::endl;
    std::cout << "Output: ";
    printSubstring(s1, L1, R1);

    std::string s2 = "sdiblcsdbud";
    int L2 = 3;
    int R2 = 7;
    std::cout << "Input: s = \"" << s2 << "\", L = " << L2 << ", R = " << R2 << std::endl;
    std::cout << "Output: ";
    printSubstring(s2, L2, R2); 

    return 0;
}