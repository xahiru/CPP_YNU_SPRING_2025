#include <iostream>
#include <string>

std::string numberToWord(int n) {
    switch (n) {
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        default: return ""; 
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;

    for (int i = a; i <= b; ++i) {
        if (i >= 1 && i <= 9) {
            std::cout << numberToWord(i) << std::endl;
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