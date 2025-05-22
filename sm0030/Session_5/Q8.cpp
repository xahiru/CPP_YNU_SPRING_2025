#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int num;
    int count = 0;
    int sum = 0;
    int max_val = std::numeric_limits<int>::min();
    int min_val = std::numeric_limits<int>::max();

    std::cout << "Enter positive integers (terminate with -1):" << std::endl;

    while (true) {
        std::cin >> num;

        if (num == -1) {
            std::cout << "Your input is for termination. Here is the result below:" << std::endl;
            break;
        }

        if (num >= 0) { // Process positive integers
            count++;
            sum += num;
            if (num > max_val) {
                max_val = num;
            }
            if (num < min_val) {
                min_val = num;
            }
        } else {
            std::cout << "Invalid input. Please enter a positive integer or -1 to terminate." << std::endl;
        }
    }

    if (count > 0) {
        std::cout << "Number of positive integers is: " << count << std::endl;
        std::cout << "The maximum value is: " << max_val << std::endl;
        std::cout << "The minimum value is: " << min_val << std::endl;
        std::cout.precision(2); // Set precision for average
        std::cout << std::fixed << "The average is " << static_cast<double>(sum) / count << std::endl;
    } else {
        std::cout << "No positive integers were entered." << std::endl;
    }

    return 0;
}