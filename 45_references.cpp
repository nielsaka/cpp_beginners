#include <iostream>

using namespace std;

void change_something(double& value) {
	value = 1234;
}

int main(int argc, char const *argv[])
{
	int val_1 = 8;

	// reference variable
	// val_2 is just another name for val_1
	// same bit of memory!
	int& val_2 = val_1;

	// not quite the same as pointer
	// syntax a little different
	// pointer can do more (what exactly? increment, decrease pointer)

	val_2 = 10;

	cout << "Value 1: " << val_1 << endl;
	cout << "Value 2: " << val_2 << endl;

	double val = 555343;
	change_something(val); // side-effect ! not good: hard to reason about code
	cout << "another value: " << val << endl; 

	return 0;
}