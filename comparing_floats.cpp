#include <iostream>
#include <iomanip>

#include <cmath>
using namespace std;

int main () {

	float val_1 = 1.1;

	// first try

	if (val_1 == 1.1) { // floating point arithmetic... :-/
		cout << "equals" << endl;
		cout << setprecision(10) << val_1 << endl;
	} else {
		cout << "not equal" << endl;
		cout << setprecision(10) << val_1 << endl;
	}

	// better

	if (abs(val_1 - 1.1) < 0.0001) { // abs() is provided by cmath or math.h header
		cout << "equal (roughly)" << endl;
		cout << setprecision(10) << val_1 << endl;
	} else {
		cout << "not equal (not even roughly)" << endl;
		cout << setprecision(10) << val_1 << endl;
	}

	return 0;
}