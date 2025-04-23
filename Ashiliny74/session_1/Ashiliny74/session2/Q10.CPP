#include <iostream>
#include <string>

using namespace std;

string numberToWords(int n) {
    string words[] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
        "twenty", "twenty-one", "twenty-two", "twenty-three", "twenty-four",
        "twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine",
        "thirty", "thirty-one", "thirty-two", "thirty-three", "thirty-four",
        "thirty-five", "thirty-six", "thirty-seven", "thirty-eight", "thirty-nine",
        "forty", "forty-one", "forty-two", "forty-three", "forty-four",
        "forty-five", "forty-six", "forty-seven", "forty-eight", "forty-nine",
        "fifty", "fifty-one", "fifty-two", "fifty-three", "fifty-four",
        "fifty-five", "fifty-six", "fifty-seven", "fifty-eight", "fifty-nine",
        "sixty", "sixty-one", "sixty-two", "sixty-three", "sixty-four",
        "sixty-five", "sixty-six", "sixty-seven", "sixty-eight", "sixty-nine",
        "seventy", "seventy-one", "seventy-two", "seventy-three", "seventy-four",
        "seventy-five", "seventy-six", "seventy-seven", "seventy-eight", "seventy-nine",
        "eighty", "eighty-one", "eighty-two", "eighty-three", "eighty-four",
        "eighty-five", "eighty-six", "eighty-seven", "eighty-eight", "eighty-nine",
        "ninety", "ninety-one", "ninety-two", "ninety-three", "ninety-four",
        "ninety-five", "ninety-six", "ninety-seven", "ninety-eight", "ninety-nine",
        "one hundred"
    };
    return (n < 100) ? words[n] : "out of range";
}

void sum_from_to(int first, int last) {
    for (int n = first; n <= last; n++) {
        if (n >= 1 && n <= 9) {
            cout << numberToWords(n) << endl;
        } else if (n > 9) {
            if (n % 2 == 0) {
                cout << "even" << endl;
            } else {
                cout << "odd" << endl;
            }
        }
    }
}

int main() {
    int a, b;
    cout << "Enter two integers (a b): ";
    cin >> a >> b;
    
    // Call the function
    sum_from_to(a, b);
    
    return 0;
}