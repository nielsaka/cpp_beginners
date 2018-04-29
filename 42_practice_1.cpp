#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string text[] = {"Decke", "Lampe", "Horizont", "Himmel"};

	int len = sizeof(text) / sizeof(string);
	string* pointer = text;

	// print array multiple times
	int n_print = 3;
	for (int i = 0; i < n_print; ++pointer)
	{		
		if (pointer == &text[len - 1]) {
			cout << *pointer << endl;
			i++; 
			// reset pointer BEFORE array
			// pointing to some random stuff?!
			// two ways: 
			if (i == 1) pointer -= len; else pointer = text - 1; 
			
		} else {
			cout << *pointer << " " << flush;
		}

	}
	return 0;
}