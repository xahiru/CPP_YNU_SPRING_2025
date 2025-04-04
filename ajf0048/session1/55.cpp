#include <iostream>
using namespace std;
 

int vol(int r);

int main (){
	int r;
	float PI = 3.1416;
	cout << "Enter radius of the sphere:" << endl;
	cin >> r;
	
	double volume = (4.0/3.0 * PI* r * r * r);
	 cout << "Volume of the sphere is:" << volume << endl;
	 
	 return 0;
}

int vol (int r, float PI){
	
	return 4.0/3.0 * PI * r * r *r;
}
