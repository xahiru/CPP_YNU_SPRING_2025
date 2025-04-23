#include <iostream>
#include <algorithm> // For std::max

int max_of_four(int a, int b, int c, int d) {
    return std::max({a, b, c, d});
}

int main() {
    int num1, num2, num3, num4;
    std::cout << "Enter four integers (separated by spaces or newlines): ";
    std::cin >> num1 >> num2 >> num3 >> num4;
    int maximum = max_of_four(num1, num2, num3, num4);
    std::cout << "The maximum of the four numbers is: " << maximum << std::endl;
    return 0;
}