#include <iostream>
#include "Cat.h"

using namespace std;

void Cat::speak(){

	if (happy) {
		cout << "meeouaw" << endl;
	} else {
		cout << "sssss" << endl;
	}
}

void Cat::jump() {

	cout << "jumping to top of bookcase" << endl;
}

void Cat::pet() {
	happy = true;
}

void Cat::shower() {
	happy = false;
}


// constructor
// can be anywhere in file; but better at beginning of file
// convention(?): method has same name as class
Cat::Cat() {

	cout << "Cat here!" << endl;

	// In C++98, this is the place to assign values to 
	// variables.

	happy = true;

}

// destructor
// name of constructor/class with a tilde prefixed
// will be called at end of scope when object is 
// destroyed
Cat::~Cat() {
	cout << "Cat destroyed" << endl;
}