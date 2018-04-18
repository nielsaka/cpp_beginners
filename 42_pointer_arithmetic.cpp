#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{	
	// variables that won't change: const
	// convention, capital letters
	const int NSTRINGS = 5;

	string texts[NSTRINGS] = {"flower", "mango", "wall", "window"};

	string* p_texts = texts;

	cout << *p_texts << endl;

	// move pointer forward in memory by three 'units'
	p_texts += 3;

	cout << *p_texts << endl;

	p_texts -= 2;

	cout << *p_texts << endl;

	cout << "==============" << endl;

	// comparison of pointers
	p_texts = texts;
	string* p_texts_end = &texts[NSTRINGS - 1];

	while(p_texts != p_texts_end) { // stopps before last element

		cout << *p_texts << endl;
		p_texts++;
	}

	cout << "==============" << endl;

	// can point beyond(!) end of array
	p_texts = texts;
	string* p_texts_beyond = &texts[NSTRINGS]; // address outside of array!

	while(p_texts != p_texts_beyond) { // now, includes last element

		cout << *p_texts << endl;
		p_texts++;
	}	


	// calc with pointers

	int elements = p_texts_beyond - &texts[0]; // potentially large number -> use long
	cout << "Number of elements in array: " << elements << endl;


	// pointers are of type 'long'?

	long elems = (long)(p_texts_beyond - &texts[0]);

	cout << "Number of elements in array: " << elems << endl;


	cout << "==============" << endl;

	p_texts = texts;
	p_texts += NSTRINGS / 2; 
	// integer division! 5 / 2 = 2
	// move pointer by 2 will yield third element

	cout << *p_texts << endl; // middle element

	return 0;
}

/*

& - address
* - dereference
type* - 'pointer' version of that type

TODO with pointers; practice:
*navigating array; going backwards and forwards in array
*addition, subtraction
*comparison 

*/