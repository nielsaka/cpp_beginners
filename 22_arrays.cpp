#include <iostream>
using namespace std;

int main() {

	int values[4];

	values[0] = 33;
	values[1] = 43;
	values[2] = 35;
	values[3] = 100;

	cout << values[2] << endl;
	cout << values[3] << endl;

	// bad idea:
	cout << values[4] << endl; // really large number; points to somewhere else?

	// even worse:
	// values[4] = 1000;

	// but c++ will not stop you; 
	// will not raise an error at compile time (but a warning?)

	double numbers[4] = {0, 4.2, 34.12, 1324.5};

	cout << numbers[3] << endl;
	cout << numbers[4] << endl;


	for (int i = 0; i < 4; i++) {
		cout << "Element at index " << i << ": " << numbers[i] << endl;
	}

	// initialise with zeros

	int number_array[8] = {0};
	
	for (int i = 0; i < 4; i++) {
		cout << "Element at index " << i << ": " << number_array[i] << endl;
	}

	// can also fill with strings
	string texts[3];

	texts[0] = "a";
	texts[1] = "wonderful";
	texts[2] = "afternoon";

	cout << "I wish you";
	for (int i = 0; i < 3; i++) {
		cout << " " + texts[i];
	}
	cout << "." << endl;


	// c++ (compiler?) figures out number of elements
	string another_text[] = {"apple", "banana", "orange"};

	cout << "Would you like ";
	for (int i = 0; i < 3; i++) {
		if (i == 2) {
			cout << "or " + another_text[i] + "?"<< endl;
		} else {
			cout << another_text[i] + ", ";
		}
	}


	return 0;
}
