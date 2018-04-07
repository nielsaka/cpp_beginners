#include "iostream"

using namespace std;

// no return object : type is void
void show_menu() {
	cout << "1. Search" << endl;
	cout << "2. View Record" << endl;
	cout << "3. Quit" << endl;
}

int get_input() {

	cout << "Enter your selection: " << flush;

	int input; 
	cin >> input;

	// can also return object in brackets, but don't have to
	return(input);
}

// passing just one variable to a function
void process_selection(int selection) {

	switch (selection) {
		case 1:
			cout << "Searching for your..." << endl;
			// will continue code below
		case 2: 
			cout << "Record not found" << endl;
		case 3:
			cout << "Bye!" << endl;
	}
}

int main(int argc, char const *argv[])
{
	show_menu();
	int selection = get_input();
	process_selection(selection);

	return 0;
}