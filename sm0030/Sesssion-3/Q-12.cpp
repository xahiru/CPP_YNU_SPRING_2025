#include <iostream>
#include <string>
#include <algorithm> // For std::swap

void permuteString(std::string str, int l, int r) {
    if (l == r) {
        std::cout << str << std::endl;
    } else {
        for (int i = l; i <= r; i++) {
            std::swap(str[l], str[i]);
            permuteString(str, l + 1, r);
            std::swap(str[l], str[i]); // Backtrack to restore the original string
        }
    }
}

int main() {
    std::string inputString;
    std::cout << "Input a string: ";
    std::cin >> inputString;

    std::cout << "All permutations of the string:" << std::endl;
    permuteString(inputString, 0, inputString.length() - 1);

    return 0;
}