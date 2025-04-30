#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::vector<int> arr = {1, 5, 7, 5, 8, 9, 11, 12};
    int target_sum = 12;
    std::unordered_map<int, int> num_count;
    int pair_count = 0;

   
    for (int num : arr) {
        num_count[num]++;
    }

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Array pairs whose sum equal to " << target_sum << ":\n";

   
    for (int num : arr) {
        int complement = target_sum - num;
        if (num_count[complement] > 0) {
            
            if (complement == num) {
                pair_count += (num_count[num] - 1); 
            } else {
                pair_count += num_count[complement];
            }

            
            num_count[num] = 0;
        }
    }

    
    num_count.clear();
    for (int num : arr) {
        num_count[num]++;
    }

    for (int num : arr) {
        int complement = target_sum - num;
        if (num_count[complement] > 0) {
            if (complement == num) {
                
                for (int i = 0; i < (num_count[num] - 1); i++) {
                    std::cout << num << "," << complement << std::endl;
                }
            } else {
                for (int i = 0; i < num_count[complement]; i++) {
                    std::cout << num << "," << complement << std::endl;
                }
            }
            num_count[num] = 0; 
        }
    }

    std::cout << "Number of pairs whose sum equal to " << target_sum << ": " << pair_count << std::endl;
    return 0;
}
