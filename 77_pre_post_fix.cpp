#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a = 7;

	cout << "a = " << a << endl;
	cout << "Prefix operator first increases and then evaluates" << endl;
	cout << "++a = " << ++a << endl;
	
	cout << "Postfix operator first evaluates and then increases" << endl;
	cout << "a++ = " << a++ << endl;
	cout << "a = " << a << endl;

	// also works with other operators
	// --
	// ++ 
	// ??
	return 0;
}