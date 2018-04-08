
// Preprocessor will replace these two lines
// with contents of header files?
// Preprocessor will look at lines starting with a hash symbol.
// These are 'preprocessor directives'.
// Later stages of compiler will see contents of header files.

// convention: 
// <iostream> is in system / global location
// "iostream" would be a local header file

#include "iostream"
#include "30_utils.h"

using namespace std;


// just declaration: 'prototype' - what return type? arguments?
// this could go in a different file, a header file!
// now it is in "30_utils.h"

//void do_something();

int main(int argc, char const *argv[])
{
	// will not work without declaration above main()
	// compiler reads file top to bottom
	do_something(); 

	return 0;
}

// can define function in a different file!
// for example, a method of a class
void do_something() {
	//do it
	cout << "Hello" << endl;
}