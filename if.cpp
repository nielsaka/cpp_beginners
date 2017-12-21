#include <iostream>

using namespace std;

int main() {

	string password = "hallo";

	cout << "Enter your password > " << flush;

	string input;
	cin >> input;

	// whitespaces are stripped
	// only first word stored
	cout << "'" << input << "'" << endl; 
	cout << input << endl; 

	if (input == password) { // "    hallo  sjdlf kldj" will work!
		cout << "Welcome." << endl;
	} else {
		cout << "Wrong password." << endl;
	}

	return 0;
}