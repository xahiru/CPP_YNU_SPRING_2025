#include <iostream>

int sum_from_to(int first, int last) {
    int sum = 0;
    if (first <= last) {
        for (int i = first; i <= last; ++i) {
            sum += i;
        }
    } else {
        for (int i = first; i >= last; --i) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    std::cout << sum_from_to(4, 7) << std::endl;    // Output: 22
    std::cout << sum_from_to(-3, 1) << std::endl;   // Output: -5
    std::cout << sum_from_to(7, 4) << std::endl;    // Output: 22
    std::cout << sum_from_to(9, 9) << std::endl;    // Output: 9
    return 0;
}