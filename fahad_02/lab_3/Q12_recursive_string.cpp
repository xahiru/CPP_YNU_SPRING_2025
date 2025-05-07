#include <iostream>
#include <string>
using namespace std;

void permute(string str, int left, int right) {
    if (left == right) {
        cout << str << endl;
    } else {
        for (int i = left; i <= right; i++) {
            swap(str[left], str[i]);                  
            permute(str, left + 1, right);            
            swap(str[left], str[i]);                  
        }
    }
}

int main() {
    string input;
    cout << "Input a string: ";
    cin >> input;

    cout << "All permutations of the string:\n";
    permute(input, 0, input.length() - 1);

    return 0;
}
