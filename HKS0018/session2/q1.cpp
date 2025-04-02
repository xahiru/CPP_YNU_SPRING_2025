#include <iostream>
#include <math.h>

using namespace std;


int main(){
    double r;
    double PI;
    double s;

    cout<<"Enter radius: "<<endl;
    cin>>r;
    r = r*r*r;
    PI = 3.14159;
    s = (4.0/3.0)*PI*r;

    cout<<"The volume of sphere is " <<s<<endl;





    return 0;
}