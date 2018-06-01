#include <iostream>
#include <iomanip> // needed for setfill(), setw(), hex (and also bit shift operator?)
#include <bitset> // for fun: print integer as binary

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned char alpha = 0xFF;
	unsigned char red = 0x12;
	unsigned char blue = 0x34;
	unsigned char green = 0x56;

	// want to combine red, blue, green, alpha to a specific colour
	// char is 1 byte; unsigned int 4 bytes.
	// how to insert the bytes?
	unsigned int colour = alpha;

	cout << colour << endl;
	// turn output into hexadecimal
	cout << hex << colour << endl;
	// and pad with zeros
	cout << setfill('0') << setw(8) << hex << colour << endl;
	// move bits around: left bit shift operator!
	colour = colour << 8; // move by 8 bits to the left; pad with zeros on right
	cout << setfill('0') << setw(8) << hex << colour << endl;
	colour = colour << 16; // move by further 16 bits to the left; pad with zeros on right
	cout << setfill('0') << setw(8) << hex << colour << endl;

	///////////////
	// reset colour
	///////////////
	colour = 0;
	colour += alpha;
	colour <<= 8;
	colour +=red;
	colour <<= 8;
	colour +=green;
	colour <<= 8;
	colour +=blue;

	cout << dec << colour << endl;
	cout << bitset<64>(colour) << endl;
	cout << setfill('0') << setw(8) << hex << colour << endl; // ff123456 !!

	return 0;
}