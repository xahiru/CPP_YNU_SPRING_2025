#include <iostream>
using namespace std;

int main() {
    int numbers[] = {10, 22, 45, 11};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int total = 0;

    for (int value : numbers) {
        total += value;
    }

    double avg = static_cast<double>(total) / length;

    cout << "Average = " << avg << endl;
    return 0;
}
