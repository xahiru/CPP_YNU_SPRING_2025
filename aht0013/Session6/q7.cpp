#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, p;
    cin >> s >> p;
    int pos = s.find(p);
    cout << (pos != string::npos ? pos : -1) << endl;

    return 0;
}