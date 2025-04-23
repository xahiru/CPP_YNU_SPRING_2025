#include <iostream>
#include <string>
using namespace std;

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}
void generatePermutations(string str, int left, int right) {
    if (left == right) {
        cout << str << endl;
        return;
    }

    for (int i = left; i <= right; i++) {
   
        swap(str[left], str[i]);
        
        generatePermutations(str, left + 1, right);
        
        swap(str[left], str[i]);
    }
}

int main() {
    string str;
    
    cout << "Input a string: ";
    cin >> str;
    
    cout << "All permutations of the string:" << endl;
    generatePermutations(str, 0, str.length() - 1);
    
    return 0;
}
