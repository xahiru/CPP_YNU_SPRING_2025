#include <iostream>
#include <vector>

int main() {
    int num;
    std::vector<int> numbers;
    
    while (true) {
        std::cout << "Enter a positive integer (-1 to terminate): ";
        std::cin >> num;
        if (num == -1) break;
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        std::cout << "No positive integers entered." << std::endl;
        return 0;
    }

    int count = numbers.size();
    int max = *std::max_element(numbers.begin(), numbers.end());
    int min = *std::min_element(numbers.begin(), numbers.end());
    double average = std::accumulate(numbers.begin(), numbers.end(), 0.0) / count;

    std::cout << "Number of positive integers is: " << count << std::endl;
    std::cout << "The maximum value is: " << max << std::endl;
    std::cout << "The minimum value is: " << min << std::endl;
    std::cout << "The average is: " << average << std::endl;
    return 0;
}
