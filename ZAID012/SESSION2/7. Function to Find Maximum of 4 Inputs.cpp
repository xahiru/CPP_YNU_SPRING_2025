#include <iostream>
using namespace std;

int max_of_four(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}

int main() {
    int a, b, c, d;
    cout << "Enter four numbers: ";
    cin >> a >> b >> c >> d;
    cout << "Maximum is: " << max_of_four(a, b, c, d) << endl;
    return 0;
}
