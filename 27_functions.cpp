#include <iostream>

using namespace std;

// no return object : type is void
void show_menu() {
	cout << "1. Search" << endl;
	cout << "2. View Record" << endl;
	cout << "3. Quit" << endl;
}
// these functions must be defined in order
// as they appear
// if defined below main(), error
int read_input(){
	int input = 0;
	while(true) {
		cout << "Enter Selection: " << flush;
		cin >> input;
		if (input < 1 || input > 3) {
			cout << "Please choose a number between 1 to 3." << endl;
		} else {
			return input;
		}
	}
}

// In c++, really shouldn't be focusing on functions. Instead, abstraction 
// via classes with methods
// functions are 'C style'
void react(int input) {
	switch (input) {
		case 1: 
			cout << "Search unsuccessful." << endl;
			break;
		case 2: 
			cout << "No records present." << endl;
			break;
		case 3:
			cout << "Bye." << endl;
			break;
		default:
			cout << "No, really. Please choose a number between 1 to 3." << endl;
	}
}

// main programme is simple / short
int main(int argc, char const *argv[])
{
	show_menu();
	int input = read_input();
	react(input);
	
	return 0;
}