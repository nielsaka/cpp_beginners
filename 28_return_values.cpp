#include "iostream"

using namespace std;

int get_input() {
	cout << "Enter Selection: " << flush;

	int input;
	cin >> input;
	
	return input; // can't return array this way
}

// let's give it a try
int get_array() {

	int my_array[] = {1, 2, 3};
	cout << my_array[0] << " " << my_array[1] << " " << my_array[2] << endl;

	// this will fail
	// "invalid conversion from ‘int*’ to ‘int’"
	// expecting an int, but getting a pointer to an int ?
	return my_array;

}

int main(int argc, char const *argv[])
{
	int input = get_input();

	cout << "Your input times three: " << 3 * input << endl;

	cout << "Now the array." << endl;

	int my_array[] = get_array();
	cout << my_array[0] << " " << my_array[1] << " " << my_array[2] << endl;

	return 0;
}