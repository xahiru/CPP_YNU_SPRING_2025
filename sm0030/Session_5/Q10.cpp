#include <iostream>

int main() {
    int n;
    std::cout << "Input number of terms: ";
    std::cin >> n;

    std::cout << "The odd numbers are: ";
    int sum_odd = 0;
    for (int i = 0; i < n; ++i) {
        int odd_num = 2 * i + 1;
        std::cout << odd_num << " ";
        sum_odd += odd_num;
    }
    std::cout << std::endl;

    std::cout << "The Sum of odd Natural Numbers upto " << n << " terms: " << sum_odd << std::endl;

    return 0;
}