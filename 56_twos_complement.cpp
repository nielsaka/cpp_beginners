#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char val = 127; // max value for char; 1 byte;
	// char is signed by default
	// first bit is sign, remain seven bits: 2^7 = 128; 
	// possible range: [-128, -1],  [0,127]

	cout << (int)val << endl;

	// NO WARNING or ERROR!

	val++;
	cout << (int)val << endl; // -128
	// not as expected
	// -128 smallest value in signed char


	// At a lower level, how to add positive and negative numbers
	// in binary number system?

	// One's Complement (in three bit system)
	// --------------
	// define
	// 111 = -0
	// 110 = -1
	// 101 = -2
	// 100 = -3
	// 000 = 0
	// 001 = 1 etc.

	// -> can add and subtract! try
	// problem: overflow bit; multiplication

	// Instead: Two's complement
	// -------------------------
	// define
	// 111 = -1
	// 110 = -2
	// 101 = -3
	// 100 = -4
	// 000 = 0
	// 001 = 1 etc.

	// advantage: arithmetic is easier; can discard overflow bit

	return 0;
}