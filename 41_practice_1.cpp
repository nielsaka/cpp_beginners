#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string my_array[] = {"Ostern", "Schokolade", "Marmelade", "Tee", "MIF"};

	// loop through array with pointers
	int len_my_array = sizeof(my_array) / sizeof(string); // just one dimension
	string* my_pointer = my_array;

	cout << "My pointer is equal to " << my_pointer << endl;
	cout << "and when de-referenced it is '" << *my_pointer << "'" << endl;
	cout << "so pointing at the first element of the array" << endl;

	cout << "The size of the pointer is " << sizeof(my_pointer) <<
		",\nwhereas the size of the array is " << sizeof(my_array) <<
		" bits(?)" << endl;
	cout << "=================================" << endl;

	// 1. array style
	for (int i = 0; i < len_my_array; ++i)
	{
		cout << my_pointer[i] << " " << flush;
		// somehow, the pointer knows that there is a
		// 'next' element?
	}
	cout << endl << "=============================" << endl;

	// 2. increment pointer; de-reference
	for (int i = 0; i < len_my_array; ++i, ++my_pointer)
	{
		cout << *my_pointer << " " << flush;
	}
	cout << endl << "=============================" << endl;

	// 3. comparison of pointers; de-reference
	my_pointer = my_array;
	string* my_pointer_end = my_pointer + len_my_array - 1; 
	while (my_pointer <= my_pointer_end) {
		cout << *my_pointer << " " << flush;
		my_pointer++;
	}
	cout << endl << "=============================" << endl;

	return 0;
}

// Is an array always one continuous, uninterrupted block of memory?
// If not, would incrementing pointers still work or would it suddenly
// point at the 'next(?)' memory slot with completely unrelated contents?