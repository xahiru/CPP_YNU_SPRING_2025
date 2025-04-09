#include <iostream>
using namespace std;

// Function to find the maximum of four numbers
int max_of_four(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}

int main() {
    int a, b, c, d;
    cout << "Enter four integers: ";
    cin >> a >> b >> c >> d;

    int result = max_of_four(a, b, c, d);
    cout << "The maximum of the four integers is: " << result << endl;

    return 0;
}