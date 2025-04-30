#include <iostream>
#include <limits>

int main() {
    int count = 0;
    int number;
    int max = std::numeric_limits<int>::min();
    int min = std::numeric_limits<int>::max();
    double sum = 0.0;

    std::cout << "Enter positive integers (terminate with -1): " << std::endl;

    while (true) {
        std::cin >> number;

        // Check for termination condition
        if (number == -1) {
            break;
        }

        // Validate that the number is positive
        if (number > 0) {
            count++;
            sum += number;

            if (number > max) {
                max = number;
            }

            if (number < min) {
                min = number;
            }
        } else {
            std::cout << "Please enter a positive integer or -1 to terminate." << std::endl;
        }
    }

    // Output the results
    if (count > 0) {
        double average = sum / count;
        std::cout << "Your input is for termination. Here is the result below:" << std::endl;
        std::cout << "Number of positive integers is: " << count << std::endl;
        std::cout << "The maximum value is: " << max << std::endl;
        std::cout << "The minimum value is: " << min << std::endl;
        std::cout << "The average is: " << average << std::fixed << std::setprecision(2) << average << std::endl;
    } else {
        std::cout << "No positive integers were entered." << std::endl;
    }

    return 0;
}