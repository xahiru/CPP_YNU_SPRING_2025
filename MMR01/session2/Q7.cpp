#include <iostream>
using namespace std;

int max_of_four(int a, int b, int c, int d) {
    int max1 = (a > b) ? a : b;
    int max2 = (c > d) ? c : d;
    return (max1 > max2) ? max1 : max2;
}

int main() {
    int a, b, c, d;
    cout<<"input number:";
    cin >> a >> b >> c >> d;
    cout << max_of_four(a, b, c, d);
    return 0;
}