#include <iostream>
using namespace std;

int main() {

	// multiple dimensions of array
	// like a matrix / table?
	string animals[2][3] = {
		{"fox", "dog", "cat"},
		{"mouse", "squirrel", "parrot"}
	};

	// can go to larger (arbitrary?) dimensions
	// e.g. my_array[2][5][1][9][111][15]

	// gets difficult with keeping track of dimensions and their size...

	// using "+" for pasting "Row " and value of `i` would not work
	// problem: "Row " is string (several characters?) while `i` is at first of type integer
	// which is then converted (?) to a char [or something like that? check Stroustrup again]
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "Row " << i << " in column " << j << ": " + animals[i][j] << endl;
		}
	}

	// print in table format
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << animals[i][j] + " " << flush;
		}
		cout << endl;
	}


	int numbers[10][10];

	for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 10; c++) {
			numbers[r][c] = (r + 1) * (c + 1);
		}
	}
	for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 10; c++) {
			cout << numbers[r][c] << " " << flush;
		}
		cout << endl;
	}

	return 0;
}

