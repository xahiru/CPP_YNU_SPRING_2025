#include <iostream>
using namespace std;

void updateVar(int *a)
{
    *a = *a + 10;
}

int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;

    updateVar(&a);

    cout << "Updated value: " << a << endl;

    return 0;
}