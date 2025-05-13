#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

vector<string> find_strings_with_numbers(const vector<string>& strings) {
    vector<string> result;
    
    for (int i = 0; i < strings.size(); i++) {
        string current = strings[i];
        bool has_number = false;
        
        for (int j = 0; j < current.length(); j++) {
            if (isdigit(current[j])) {
                has_number = true;
                break;
            }
        }
        
        if (has_number) {
            result.push_back(current);
        }
    }
    
    return result;
}