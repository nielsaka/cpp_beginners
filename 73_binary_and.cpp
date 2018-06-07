#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int colour = 0x123456;

	// goal: extract certain part from integer (e.g red colour)

	// single ampersand -> bit-wise and (= bit-wise comparison)
	// look at each bit and if both are one, then set to one.
	// will set non-red range to 0 and keep number for red
	int red = (colour & 0xFF0000) >> 16; // shift by 16 bits
	int green = (colour & 0x00FF00) >> 8; // shift by one byte
	// better to use unsigned char, because max value is 255
	unsigned char blue = (colour & 0x0000FF); 

	// 0xFF0000 = 111111110000000000000000

	cout << hex << colour << endl;
	// = 123456
	cout << hex << red << flush;
	cout << hex << green << flush;
	cout << hex << (int)blue << endl;
	// = 123456

	// alternatively, just use right bit-shift operator and cast to unsigned char
	// (maybe not working on all machines/OS/compilers?)

	// this will move bits and then cut-off leading digits, 
	// because unsigned char will hold 8 bits (2^8 = 256).
	// type implicitly converted from int to unsigned char
	unsigned char red_again = colour >> 16; 
	unsigned char green_again = colour >> 8;
	unsigned char blue_again = colour;
	cout << hex << (int)red_again   << flush;
	cout << hex << (int)green_again << flush;
	cout << hex << (int)blue_again  << endl;
	// = 123456

	return 0;
}