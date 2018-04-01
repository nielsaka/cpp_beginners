#include <iostream>
using namespace std; 

int main() {

	int value = 34;

	// number of bytes
	cout << sizeof(value) << endl;

	cout << sizeof(int) << endl;

	// sizeof is an operator!
	// looks like a function, but is
	// not

	// 5.5 is converted (truncated?)
	// to type int
	int vls[] = {4, 7, 5.5, 9};

	for (int i = 0; i < 4; i++) {
		cout << vls[i] << endl;
	}

	// 4 * 4 bytes  = 16 bytes! 
	cout << sizeof(vls) << endl;

	cout << "and another time: " << endl;
	int elems = sizeof(vls) / sizeof(int);
	for (int i = 0; i < elems; i++) {
		cout << vls[i] << endl;
	}

	// but sizeof is unsigned int
	// (though not a problem to compare
	// signed and unsigned int?)
	for (unsigned int i = 0; i < elems; i++) {
		cout << vls[i] << endl;
	}

	return 0;
}