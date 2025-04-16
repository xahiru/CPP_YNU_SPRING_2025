#include <iostream>

#define PI 3.1415

using namespace std;

int main(){
    double r, a, c;

    cout<<"Enter radius (1/2 of diameter) of a circle: "<<endl;
    cin>> r;

    a = PI* r * r;
    c = 2 * PI * r;

    cout <<"The area of the circle is:"<<a<<endl;
    cout <<"The circumference of the circle is: "<<c<<endl;

    return 0;


}