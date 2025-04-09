#include <iostream>
#include <math.h>

using namespace std;

#define PI 3.1415


int main(){
    double r;
    double s;

    cout<<"Enter radius: "<<endl;
    cin>>r;
    r = r*r*r;
    s = (4.0/3.0)*PI*r;

    cout<<"The volume of sphere is " <<s<<endl;





    return 0;
}