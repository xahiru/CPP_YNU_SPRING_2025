#include <iostream>
#include <vector>
#include <set>
#include <string>

std::string findThirdLargestString(const std::vector<std::string>& arr) {
    std::set<std::string> unique_strings(arr.begin(), arr.end());
    
    if (unique_strings.size() < 3) {
        return "Not enough unique strings";
    }

    auto it = unique_strings.rbegin();
    std::advance(it, 2); 
    return *it;
}

int main() {
    std::vector<std::string> arr = {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"};
    
    std::cout << "Array elements: ";
    for (const auto& str : arr) {
        std::cout << str << " ";
    }
    std::cout << "\nThird highest length string: " << findThirdLargestString(arr) << std::endl;

    return 0;
}
