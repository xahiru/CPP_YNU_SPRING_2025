#include <iostream>
#include <vector>
#include <set>

int main() {
    std::vector<int> arr = {5, 6, 7, 2, 3, 4, 12};
    std::set<int> unique_elements(arr.begin(), arr.end());

    auto it = unique_elements.begin();
    ++it; 
    std::cout << "Second smallest number: " << *it << std::endl;
    return 0;
}
