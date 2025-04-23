#include <iostream>
#include <cstring> 
using namespace std;

void permute(char *str, int l, int r) {
    if (l == r) {
        cout << str << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);  
            permute(str, l + 1, r);  
            swap(str[l], str[i]);  
        }
    }
}

int main() {
    char str[] = "abc";
    int n = strlen(str);
    cout << "All permutations of the string:\n";
    permute(str, 0, n - 1);

    return 0;
}
