# include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	// all dimensions except first must be given set bounds
	string animals[][5] = {
		// treat data row-wise
		// (definitional matter?)
		{"fox", "dog", "cat", "duck"},
		{"wolf", "bear", "tiger"},
		{"bee", "wasp", "ant"}
	};

	cout << "Arrays consists of " << sizeof(animals) << " bytes." << endl;

	// what is the size of an object of 
	// type string? 32 bytes
	int len_str = sizeof(string);
	cout << "Object of class string has bytes: " << len_str << endl;

	// assuming each column has same number of rows
	// could check: seems there are 9 cells
	// but 3 * 3 = 9 indeed?
	cout <<
		"Number of cells in 2D array: " << 
		sizeof(animals) / len_str << 
		endl;

	int cols = sizeof(animals[1]) / len_str;
	cout << 
		"Number of columns: " <<
		 cols <<
		 endl;

	int rows = sizeof(animals) / len_str / cols;
	cout << 
		"Number of rows: " <<
		 rows <<
		 endl;

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			cout << animals[r][c] << " " << flush;
		}
		cout << endl;
	}

	// animals[i] has always same length, independen to 'i'

	// For John, the entries are rows. So:

	cout << endl << endl;
	rows = sizeof(animals[0]) / len_str;
	cols = sizeof(animals) / sizeof(animals[0]);

	for (int c = 0; c < cols; c++) {
		for (int r = 0; r < rows; r++) {
			cout << animals[c][r] << " " << flush;
		}
	cout << endl;
	}

	// actually, same as above ?!

	return 0;
}