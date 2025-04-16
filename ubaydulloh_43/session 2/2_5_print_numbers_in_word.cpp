#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    if (n > 1 && n < 10) {
        switch (n) {
            case 2: std::cout << "two"; break;
            case 3: std::cout << "three"; break;
            case 4: std::cout << "four"; break;
            case 5: std::cout << "five"; break;
            case 6: std::cout << "six"; break;
            case 7: std::cout << "seven"; break;
            case 8: std::cout << "eight"; break;
            case 9: std::cout << "nine"; break;
            default: break;
        }
    } else if (n > 9) {
        std::cout << "Greater than 9";
    }

    return 0;
}