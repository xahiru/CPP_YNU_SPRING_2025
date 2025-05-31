#include<iostream>
#include<cmath>
using namespace std;

void volume_sphere(double red){
    double vol;
    cout<<"Input the radius of a sphere : ";
    vol = (4.0 /3.0)*M_PI*pow(red,3);
    cout<<"The volume of a sphere is : "<< vol <<endl;
}

void volume_cube(int side){
    cout<<"5The volume of a cube is : "<<pow(side,3)<<endl;
}

void area_perimeter_rectangle(int len, int wid){
    cout<<"The area of the rectangle is : "<<len*wid<<endl;
    cout<<"The perimeter of the rectangle is : "<<2*(len+wid)<<endl;
}

void area_circle(double rad){
    double area, circumference;

    area = M_PI * pow(rad, 2);
    circumference = 2 * M_PI * rad;

    cout << "The area of the circle is : " << area << endl;
    cout << "The circumference of the circle is : " << fixed;
    cout.precision(0);
    cout << circumference << endl;
}

void number_in_word(int n){
    if (n > 1 && n < 9) {
        switch(n) {
            case 2: cout << "two"; break;
            case 3: cout << "three"; break;
            case 4: cout << "four"; break;
            case 5: cout << "five"; break;
            case 6: cout << "six"; break;
            case 7: cout << "seven"; break;
            case 8: cout << "eight"; break;
        }
    } else if (n > 9) {
        cout << "Greater than 9";
    }
}

void odd_even(int n, int m){
    if (n >= 1 && n <= 9) {
        switch(n) {
            case 1: cout << "one"<<endl; break;
            case 2: cout << "two"<<endl; break;
            case 3: cout << "three"<<endl; break;
            case 4: cout << "four"<<endl; break;
            case 5: cout << "five"<<endl; break;
            case 6: cout << "six"<<endl; break;
            case 7: cout << "seven"<<endl; break;
            case 8: cout << "eight"<<endl; break;
            case 9: cout << "nine"<<endl; break;
        }
    } 
    else if (n > 9) {
        cout << "nine"<<endl;
    }

    if (m >= 1 && m <= 9) {
        switch(m) {
            case 1: cout << "one"<<endl; break;
            case 2: cout << "two"<<endl; break;
            case 3: cout << "three"<<endl; break;
            case 4: cout << "four"<<endl; break;
            case 5: cout << "five"<<endl; break;
            case 6: cout << "six"<<endl; break;
            case 7: cout << "seven"<<endl; break;
            case 8: cout << "eight"<<endl; break;
            case 9: cout << "nine"<<endl; break;
        }
    } 
    else if (m > 9) {
        cout << "nine"<<endl;
    }

    if(n%2==0){
        cout<<"even"<<endl;
    }
    else{
        cout<<"odd"<<endl;
    }
    if(m%2==0){
        cout<<"even"<<endl;
    }
    else{
        cout<<"odd"<<endl;
    }
}


int main(){
volume_sphere(6);
volume_cube(5);
area_perimeter_rectangle(10,15);
area_circle(5);
number_in_word(5);
odd_even(8,11);

}