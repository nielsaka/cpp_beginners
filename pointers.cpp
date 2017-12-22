#include <iostream>
using namespace std;


int main() {
	int v[5] {0, 1, 2, 3, 4};
	int* p = &v[3]; //pointer
	int& r = v[4];  //reference

	cout << p << endl; // address where pointing to
	cout << &p << endl;// address of p
	cout << *p << endl;// contents of address where pointing to

	v[3] = 100;

	cout << *p << endl;

	*p = -10;

	cout << v[3] << endl; // can change value of v[3]!


	cout << "The current value that r references to is: " << r << endl;
	v[4] = 78;
	cout << "The current value that r references to is: " << r << endl;

	r = v[3]; // I thought it is not changeable? 
	          // v[4] is not changeable via reference!
	cout << "The current value that r references to is: " << r << endl;
}