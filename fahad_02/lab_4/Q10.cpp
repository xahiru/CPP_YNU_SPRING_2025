#include <iostream>
using namespace std;

int i[5] = {0, 2, 4, 6, 8};
int *p;

void foo()
{
  cout << *p << endl; // Print the value pointed by p
  ++(*p);             // first dereferencing then Increment the value of the array
  ++p;                // Move the pointer to the next element
}

void bar()
{
  for (int i = 0; i < 3; ++i)
  { // bar function will call foo three times
    foo();
  }
}

int main()
{
  p = i; // assigning the address of i to p
  bar(); // calling bar function
  cout << "Check Point 1" << endl;
  p = i; // Reset p to point to the first element of i
  foo(); // Call foo again
  // foo function will print the value of p and increment the value of the array
  cout << "Check Point 2" << endl;
  return 0;
}