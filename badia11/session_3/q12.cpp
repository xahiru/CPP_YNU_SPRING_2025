#include <iostream>
#include <string>
#include <algorithm>

void permute(std::string str, int l, int r) {
    if (l == r) {
        std::cout << str << std::endl;
    } else {
        for (int i = l; i <= r; i++) {
            std::swap(str[l], str[i]);
            permute(str, l + 1, r);
            std::swap(str[l], str[i]); 
        }
    }
}

int main() {
    std::string str = "abc";
    std::cout << "Input a string: " << str << std::endl;
    std::cout << "All permutations of the string:\n";
    permute(str, 0, str.size() - 1);

    return 0;
}

