#include <iostream>

using namespace std;

int main() {

	bool bool_value = false;
	// sometimes:
	// BOOL bool_value = FALSE;

	cout << bool_value << endl; // 0 
	// true = (any integer/number other than 0)
	// false = 0


	// char //
	//////////

	// char is exactly one byte -> can take 256 different values
	// integers -128 to 127 mapped to ASCII symbols

	cout << "Size of char: " << sizeof(char) << endl;

	// DOES NOT WORK
	// char char_value = "A"; 

	// "A" is a const char
	// 'A' is a char 
	// ??


	char char_value = 55;
	cout << char_value << endl;  // 7 

	char_value = 'A';
	cout << char_value << endl; // A

	// cast char to int
	cout << (int)char_value << endl; // 65

	cout << "Size of char: " << sizeof(char) << endl;


	// wchar //
	///////////

	wchar_t wchar_t_value = 'i'; // contains the integer for ASCII symbol
	cout << wchar_t_value << " = " << (char)wchar_t_value << endl;
	char_value = 105;
	cout << char_value << endl;

	cout << "Size of char: " << sizeof(wchar_t) << endl; // 4 bytes
	// wchar_t also useful for unicode etc.
	// can store greater range of values than 256

	return 0;
}