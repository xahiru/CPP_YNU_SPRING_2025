#include <iostream>
#include <string>

int main() {
    int a, b;
    std::cout << "Enter two positive integers a and b (separated by a newline):\n";
    std::cin >> a >> b;

    std::string words[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = a; i <= b; ++i) {
        if (i >= 1 && i <= 9) {
            std::cout << words[i] << std::endl;
        } else if (i > 9) {
            if (i % 2 == 0) {
                std::cout << "even" << std::endl;
            } else {
                std::cout << "odd" << std::endl;
            }
        }
    }

    return 0;
}