#include<iostream>
using namespace std;

int main()
{
    int len, wid;
    cout << "Input the length of the rectangle : ";
    cin >> len;
    cout << "Input the width of the rectangle : ";
    cin >> wid;
    cout << "The area of the rectangle is : " << len * wid << endl;
    cout << "The perimeter of the rectangle is : " << 2 * (len + wid) << endl;
    return 0;
}