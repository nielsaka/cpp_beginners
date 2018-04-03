#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int value = 6;
	// works as well with char
	//char value = 4;

	const int const_var = 7;

	switch (value) {
		case 4: 
			cout << "value is 4..."; 
			break; // without break, it will run all remaing code below
		case 5: 
			cout << "value is 5!" << endl;
			break;
		case 6: 
			cout << "value is 6" << endl;
			// break;
		//case variable: "not allowed to have variables as switch";
		case const_var:
			cout << 
				"but a constant is possible (just as if the text was written here" <<
				" instead of 'const_var')." << 
				endl;
		// case 5: "not allowed to have same case again"
		default: 
			cout << "unrecognised value" << endl;
			break;
	}

	return 0;
}