#include <iostream>
#include <limits.h>

using namespace std;

int main() {

	int value = 4294967295; // will be -1

	std::cout << value << endl;

	// max int will be 2^30 + 2^29 + ... + 2^0
	// or: 0 111 ... 1111

	// 31st bit is used for sign

	// min int will be - 2^31
	// or: 1 000 ... 0000

	// -1 will be 1 111 ... 1111 = 4294967295

	// --> int is 4 byte long
	// could be different on other machines?

	std::cout << "Max int value: " << INT_MAX << endl;
	std::cout << "Min int value: " << INT_MIN << endl;


	// long int for large integer values
	long int l_value = 1231314515512421;

	// can also just type "long" or "short"
	long l_value2 = 12313145155124219;

	std::cout << l_value << endl;
	std::cout << l_value2 << endl;

	short int s_value = 12354151; // too large already
	std::cout << s_value << endl;

	cout << "Size of int: " << 
	sizeof(int) << endl; // 4 bytes

	cout << "Size of long int: " << 
	sizeof(long int) << endl; // 8 bytes

	cout << "Size of short int: " << 
	sizeof(short int) << endl; // 2 btyes

	unsigned int u_value = -23434;
	cout << "Value of u_int: " << u_value << endl;

	u_value = 2147483648; // 2147483648
	cout << "Value of u_int: " << u_value << endl;

	value = 2147483648; // -2147483648
	cout << "Value of int: " << value << endl;


	return 0;
}