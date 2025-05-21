#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string arr1[] = {"abcd", "abcde", "abcdef", "abcdefg", "abcdefgh"};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    cout << "Array elements: ";
    for(int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    vector<pair<int, string>> len_str_pairs;
    for(int i = 0; i < size1; i++) {
        len_str_pairs.push_back({arr1[i].length(), arr1[i]});
    }
    sort(len_str_pairs.begin(), len_str_pairs.end(), greater<pair<int, string>>());
    
    if(size1 >= 3) {
        string third_largest = "";
        int different_lengths = 1;
        int prev_length = len_str_pairs[0].first;
        
        for(int i = 1; i < size1 && different_lengths < 3; i++) {
            if(len_str_pairs[i].first != prev_length) {
                different_lengths++;
                prev_length = len_str_pairs[i].first;
            }
            
            if(different_lengths == 3) {
                third_largest = len_str_pairs[i].second;
            }
        }
        
        cout << "Third highest length string: " << third_largest << endl;
    } else {
        cout << "Array has less than 3 elements" << endl;
    }
    string arr2[] = {"abc", "abc", "abc", "abc", "abc"};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    cout << "\nArray elements: ";
    for(int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "Third highest length string: " << arr2[0] << endl;
    
    string arr3[] = {"abcd", "abcd", "abc"};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "\nArray elements: ";
    for(int i = 0; i < size3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    
    len_str_pairs.clear();
    for(int i = 0; i < size3; i++) {
        len_str_pairs.push_back({arr3[i].length(), arr3[i]});
    }
    
    sort(len_str_pairs.begin(), len_str_pairs.end(), greater<pair<int, string>>());
    
    cout << "Third highest length string: " << arr3[2] << endl;
    
    return 0;
}
