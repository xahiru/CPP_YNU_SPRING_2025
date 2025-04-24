#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::vector<int> arr = {1, 2, 3, 5, 5, 7, 8, 8, 9, 9, 2};
    std::unordered_map<int, int> count_map;
    std::vector<int> repeating;

    for (int num : arr) {
        count_map[num]++;
        if (count_map[num] == 2) {
            repeating.push_back(num);
        }
    }

    std::cout << "Repeating elements: ";
    for (int num : repeating) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
