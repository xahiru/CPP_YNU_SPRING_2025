#include <iostream>
#include <string>
using namespace std;

void printSubstring(const string& s, int L, int R) {
    
    for (int i = L; i <= R; i++) {
        cout << s[i];
    }
    cout << endl;
}

int main() {
    string s1 = "cdbkdub";
    int L1 = 0, R1 = 5;
    printSubstring(s1, L1, R1);

    string s2 = "sdiblcsdbud";
    int L2 = 3, R2 = 7;
    printSubstring(s2, L2, R2);

    return 0;
}
