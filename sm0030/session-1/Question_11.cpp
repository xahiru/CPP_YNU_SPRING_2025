#include <iostream>

using namespace std;

int main() {
  int num, reversedNum = 0, remainder, originalNum;

  cout << "Enter a Number to Check: ";
  cin >> num;

  originalNum = num;

  while (num != 0) {
    remainder = num % 10;
    reversedNum = reversedNum * 10 + remainder;
    num /= 10;
  }

  if (originalNum == reversedNum)
    cout << originalNum << " is a palindrome.";
  else
    cout << originalNum << " is not a palindrome.";

  return 0;
}