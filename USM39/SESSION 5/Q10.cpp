#include <iostream>

int main() {
    int n;
    std::cout << "Input number of terms: ";
    std::cin >> n;
    
    int sum = 0;
    std::cout << "The odd numbers are: ";
    for (int i = 0; i < n; ++i) {
        int odd = 2 * i + 1;
        sum += odd;
        std::cout << odd << " ";
    }
    std::cout << "\nThe Sum of odd Natural Numbers up to " << n << " terms: " << sum << std::endl;
    return 0;
}
