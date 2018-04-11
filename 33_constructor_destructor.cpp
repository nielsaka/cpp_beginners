#include <iostream>
#include "Cat.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Starting programme ..." << endl;

	{ // new scope
		Cat bob; // instantiating Cat from its class

		bob.speak();
	}

	// cannot use object "bob" anymore after scope has ended: 
	// out-of-scope
	// object has been destroyed

	cout << "Ending programme ..." << endl;
	return 0;
} // Cat object will be destroyed at end of programme (or when closing 
// scope -> can destroy object intentionally)

/*
constructor - runs when object is instantiated
destructor - runs when object is destroyed; frees, deallocates memory
*/